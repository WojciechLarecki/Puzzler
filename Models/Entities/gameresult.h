#ifndef GAMERESULT_H
#define GAMERESULT_H

#include <QString>
#include <QDateTime>

/**
 * @brief Klasa reprezentująca wynik rozwiązanej gry.
 *
 * Przechowuje informacje o liczbie punktów, czasie rozpoczęcia i zakończenia gry,
 * rozmiarze planszy oraz identyfikatorze użytkownika.
 */
class GameResult {
private:
    int _id; ///< Identyfikator wyniku.
    int _points; ///< Liczba zdobytych punktów.
    QDateTime _startDateTime; ///< Czas rozpoczęcia gry.
    QDateTime _endDateTime; ///< Czas zakończenia gry.
    int _boardSize; ///< Rozmiar planszy.
    int _userId; ///< Identyfikator gracza.

public:
    /**
     * @brief Konstruktor domyślny klasy GameResult.
     */
    GameResult();

    /**
     * @brief Pobiera identyfikator wyniku gry.
     * @return Identyfikator wyniku.
     */
    int getId() const;

    /**
     * @brief Ustawia identyfikator wyniku gry.
     * @param id Nowy identyfikator.
     */
    void setId(int id);

    /**
     * @brief Pobiera liczbę zdobytych punktów.
     * @return Liczba punktów.
     */
    int getPoints() const;

    /**
     * @brief Ustawia liczbę zdobytych punktów.
     * @param points Nowa liczba punktów.
     */
    void setPoints(int points);

    /**
     * @brief Pobiera datę i czas rozpoczęcia gry.
     * @return Obiekt QDateTime z czasem rozpoczęcia gry.
     */
    QDateTime getStartDateTime() const;

    /**
     * @brief Ustawia datę i czas rozpoczęcia gry.
     * @param start Czas rozpoczęcia gry.
     */
    void setStartDateTime(const QDateTime& start);

    /**
     * @brief Pobiera datę i czas zakończenia gry.
     * @return Obiekt QDateTime z czasem zakończenia gry.
     */
    QDateTime getEndDateTime() const;

    /**
     * @brief Ustawia datę i czas zakończenia gry.
     * @param end Czas zakończenia gry.
     */
    void setEndDateTime(const QDateTime& end);

    /**
     * @brief Pobiera rozmiar planszy.
     * @return Rozmiar planszy.
     */
    int getBoardSize() const;

    /**
     * @brief Ustawia rozmiar planszy.
     * @param size Nowy rozmiar planszy.
     */
    void setBoardSize(int size);

    /**
     * @brief Pobiera id gracza, który ustanowił wynik gry.
     * @return Identyfikator użytkownika.
     */
    int getUserId() const;

    /**
     * @brief Ustawia id gracza, który ustanowił wynik gry.
     * @param userId Nowy identyfikator użytkownika.
     */
    void setUserId(int userId);

    /**
     * @brief Oblicza punkty za grę na podstawie typu zwracanego.
     *
     * Wynik zależy od rozmiaru planszy oraz czasu gry.
     *
     * @tparam T Typ zwracany (np. int, double).
     * @return Liczba punktów w danym typie.
     */
    template<typename T>
    T calculatePoints() const;
};

template<typename T>
T GameResult::calculatePoints() const {
    T points = _boardSize * 50;
    int minutes = (_endDateTime.toMSecsSinceEpoch() -
                   _startDateTime.toMSecsSinceEpoch()) / 60000;
    points = points - (minutes * 35);
    return points;
}

#endif // GAMERESULT_H
