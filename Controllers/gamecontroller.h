#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QVector>

/**
 * @brief Klasa odpowiedzialna za tworzenie ustawienia gry.
 *
 * Klasa `GameController` zarządza generowaniem kombinacji gry oraz sprawdza,
 * czy dany układ planszy jest rozwiązywalny lub już rozwiązany.
 */
class GameController
{
public:
    /**
     * @brief Generuje kombinację gry w formie jednowymiarowej tablicy.
     *
     * Metoda ta generuje kombinację układu gry o
     * rozmiarze `size x size`. Kombinacja jest losowa, ale sprawdzona pod kątem
     * rozwiązywalności.
     *
     * @param size Rozmiar planszy (liczba pól na planszy).
     * @return QVector<int> Jednowymiarowa tablica reprezentująca kombinację gry.
     */
    QVector<int> getGameCombination(int size);

private:
    /**
     * @brief Sprawdza, czy dana kombinacja układu jest rozwiązywalna.
     *
     * Sprawdza, czy kombinacja jednowymiarowej tablicy jest rozwiązywalna,
     * bazując na liczbie odwróconych par (inversions).
     *
     * @param oneDArray Jednowymiarowa tablica reprezentująca układ planszy.
     * @param size Rozmiar planszy (liczba pól na planszy).
     * @return true, jeśli kombinacja jest rozwiązywalna, w przeciwnym razie false.
     */
    bool isSolvable(const QVector<int>& oneDArray, int size);

    /**
     * @brief Sprawdza, czy układ planszy jest już rozwiązany.
     *
     * Metoda sprawdza, czy tablica reprezentująca układ planszy jest już w
     * rozwiązanej formie, tzn. czy elementy są uporządkowane w kolejności rosnącej.
     *
     * @param array Jednowymiarowa tablica reprezentująca układ planszy.
     * @return true, jeśli plansza jest już rozwiązana, w przeciwnym razie false.
     */
    bool isAlreadySolved(const QVector<int>& array);
};

#endif // GAMECONTROLLER_H
