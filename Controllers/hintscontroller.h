#ifndef HINTSCONTROLLER_H
#define HINTSCONTROLLER_H

#include "../Models/Hints/basehint.h"
#include "../Models/Hints/datehint.h"
#include "../Models/Hints/texthint.h"
#include <vector>

/**
 * @brief Klasa odpowiedzialna za zarządzanie podpowiedziami w grze.
 *
 * Klasa `HintsController` zarządza podpowiedziami, które mogą być udostępniane graczowi podczas gry.
 * Umożliwia dodawanie nowych podpowiedzi oraz losowanie jednej
 * z dostępnych podpowiedzi. Podpowiedzi mogą mieć różne typy, takie jak tekstowe lub oparte na dacie.
 */
class HintsController
{
public:
    /**
     * @brief Konstruktor klasy `HintsController`.
     *
     * Inicjalizuje kontroler podpowiedzi, tworzy pustą listę podpowiedzi oraz ustawia wartość ziarna
     * dla generatora losowego.
     */
    HintsController();

    /**
     * @brief Pobiera wszystkie dostępne podpowiedzi.
     *
     * Metoda zwraca wszystkie podpowiedzi, które zostały dodane do kontrolera w postaci wektora
     * wskaźników do obiektów klasy `BaseHint` i jej pochodnych.
     *
     * @return std::vector<BaseHint*> Wektor wskaźników do obiektów `BaseHint`, reprezentujących wszystkie dostępne podpowiedzi.
     */
    std::vector<BaseHint*> getHints();

    /**
     * @brief Dodaje podpowiedź o dacie początkowej.
     *
     * Metoda dodaje do kontrolera podpowiedź opartą na dacie początkowej. Podpowiedź ta może być użyta
     * w przypadku, gdy konieczne jest wskazanie czasu rozpoczęcia gry.
     *
     * @param dt Data i czas, które mają zostać użyte w podpowiedzi.
     */
    void AddStartDateHint(QDateTime dt);

    /**
     * @brief Losuje jedną podpowiedź.
     *
     * Metoda losuje jedną podpowiedź z dostępnych podpowiedzi w kontrolerze.
     *
     * @return BaseHint* Wskaźnik do losowo wybranej podpowiedzi.
     */
    BaseHint* GetRandom();

    /**
     * @brief Destruktor klasy `HintsController`.
     *
     * Destruktor zwalnia wszystkie zasoby związane z podpowiedziami. Usuwa obiekty podpowiedzi,
     * które zostały dynamicznie alokowane w wektorze `_hints`.
     */
    ~HintsController();

private:
    unsigned seed; /**< Ziarno dla generatora losowego. */
    std::vector<BaseHint*> _hints; /**< Wektor przechowujący wskaźniki do dostępnych podpowiedzi. */
};

#endif // HINTSCONTROLLER_H
