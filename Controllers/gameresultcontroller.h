#ifndef GAMERESULTCONTROLLER_H
#define GAMERESULTCONTROLLER_H

#include "../Models/gameresulttabledto.h"
#include <vector>

/**
 * @brief Klasa odpowiedzialna za zarządzanie wynikami gry.
 *
 * Klasa `GameResultController` umożliwia pobieranie wyników gry,
 * usuwanie wyników oraz dodawanie nowych wyników. Jest to interfejs
 * kontrolera odpowiedzialny za manipulowanie danymi dotyczącymi wyników
 * gry przechowywanymi w aplikacji.
 */
class GameResultController
{
public:
    /**
     * @brief Pobiera listę wyników gier.
     *
     * Metoda zwraca wszystkie wyniki gier zapisane w systemie.
     * Wyniki są zwracane w postaci wektora obiektów `GameResultTableDTO`,
     * które zawierają dane o grze oraz nazwie użytkownika.
     *
     * @return std::vector<GameResultTableDTO> Lista wyników gier.
     */
    std::vector<GameResultTableDTO> getResults();

    /**
     * @brief Usuwa wynik gry na podstawie identyfikatora.
     *
     * Metoda umożliwia usunięcie wyniku gry na podstawie przekazanego identyfikatora.
     *
     * @param resultId Identyfikator wyniku, który ma zostać usunięty.
     * @return true, jeśli wynik został usunięty pomyślnie, w przeciwnym razie false.
     */
    bool DeleteResult(int resultId);

    /**
     * @brief Dodaje nowy wynik gry.
     *
     * Metoda umożliwia dodanie nowego wyniku gry do systemu.
     *
     * @param result - zawierający dane wyniku do dodania.
     * @return true, jeśli wynik został dodany pomyślnie, w przeciwnym razie false.
     */
    bool AddResult(GameResult result);
};

#endif // GAMERESULTCONTROLLER_H
