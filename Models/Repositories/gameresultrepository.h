#ifndef GAMERESULTREPOSITORY_H
#define GAMERESULTREPOSITORY_H

#include "baserepository.h"
#include "../Entities/gameresult.h"
#include "vector"

/**
 * @brief Klasa repozytorium dla obiektów typu GameResult.
 *
 * Klasa `GameResultRepository` implementuje interfejs klasy bazowej `RepositoryBase<GameResult>`.
 * Odpowiada za przechowywanie, dodawanie i usuwanie wyników gry w repozytorium bazy danych.
 *
 * @see RepositoryBase
 */
class GameResultRepository : public RepositoryBase<GameResult> {
public:
    /**
     * @brief Konstruktor klasy GameResultRepository.
     *
     * Inicjalizuje obiekt repozytorium dla wyników gry.
     */
    GameResultRepository();

    /**
     * @brief Dodaje nowy wynik gry do repozytorium.
     *
     * Metoda ta dodaje nowy obiekt typu `GameResult` do repozytorium.
     *
     * @param gameResult Obiekt `GameResult`, który ma zostać dodany do repozytorium.
     * @return Zwraca true, jeśli obiekt został pomyślnie dodany, w przeciwnym razie false.
     */
    bool Add(const GameResult& gameResult) override;

    /**
     * @brief Usuwa wynik gry o podanym identyfikatorze z repozytorium.
     *
     * Metoda ta usuwa obiekt typu `GameResult` na podstawie jego identyfikatora.
     *
     * @param id Identyfikator wyniku gry, który ma zostać usunięty.
     * @return Zwraca true, jeśli obiekt został pomyślnie usunięty, w przeciwnym razie false.
     */
    bool Delete(int id) override;

    /**
     * @brief Zwraca wszystkie wyniki gry przechowywane w repozytorium.
     *
     * Metoda ta pobiera wszystkie obiekty typu `GameResult` przechowywane w repozytorium.
     *
     * @return Zwraca wektor obiektów typu `GameResult`.
     */
    std::vector<GameResult> GetAll() override;
};

#endif // GAMERESULTREPOSITORY_H

