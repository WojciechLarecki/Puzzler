#ifndef GAMERESULTTABLEDTO_H
#define GAMERESULTTABLEDTO_H

#include "Entities/gameresult.h"
#include <QString>

/**
 * @brief Klasa DTO (Data Transfer Object) dla wyniku gry.
 *
 * Klasa `GameResultTableDTO` jest używana do przechowywania informacji o wyniku gry
 * oraz powiązanym użytkowniku, które są używane do prezentacji wyników w tabeli wyników gry.
 */
class GameResultTableDTO
{
private:
    GameResult _game; ///< Obiekt przechowujący wynik gry.
    QString _userName; ///< Nazwa użytkownika, który osiągnął wynik.

public:
    /**
     * @brief Konstruktor klasy GameResultTableDTO.
     *
     * Tworzy obiekt DTO przechowujący wynik gry i nazwę użytkownika.
     *
     * @param game Wynik gry.
     * @param userName Nazwa użytkownika, który osiągnął ten wynik.
     */
    GameResultTableDTO(GameResult game, QString userName);

    /**
     * @brief Pobiera nazwę użytkownika.
     *
     * Metoda zwraca nazwę użytkownika przechowywaną w obiekcie.
     *
     * @return Zwraca nazwę użytkownika.
     */
    QString getUserName() const;

    /**
     * @brief Ustawia nazwę użytkownika.
     *
     * Metoda ustawia nazwę użytkownika w obiekcie DTO.
     *
     * @param newUserName Nowa nazwa użytkownika.
     */
    void setUserName(const QString& newUserName);

    /**
     * @brief Pobiera wynik gry.
     *
     * Metoda zwraca obiekt `GameResult`, który zawiera wynik gry.
     *
     * @return Zwraca obiekt `GameResult`.
     */
    GameResult getGame() const;

    /**
     * @brief Ustawia wynik gry.
     *
     * Metoda ustawia wynik gry w obiekcie DTO.
     *
     * @param game Obiekt `GameResult`, który zawiera wynik gry.
     */
    void setGame(const GameResult& game);
};

#endif // GAMERESULTTABLEDTO_H
