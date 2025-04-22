#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

#include <vector>

/**
 * @brief Abstrakcyjna klasa bazowa dla repozytoriów.
 *
 * Klasa ta definiuje interfejs ogólnych operacji na repozytorium: dodawanie, usuwanie oraz pobieranie wszystkich obiektów.
 * Jest to szablonowa klasa, która przyjmuje typ danych, które będą przechowywane w repozytorium.
 *
 * @tparam T Typ obiektów przechowywanych w repozytorium.
 */
template <typename T>
class RepositoryBase {
public:
    /**
     * @brief Wirtualny destruktor.
     *
     * Zapewnia poprawne usuwanie obiektów pochodnych.
     */
    virtual ~RepositoryBase() = default;

    /**
     * @brief Dodaje nowy obiekt do repozytorium.
     *
     * Metoda ta służy do dodawania obiektów do repozytorium.
     *
     * @param entity Obiekt, który ma zostać dodany do repozytorium.
     * @return Zwraca true, jeśli obiekt został dodany pomyślnie, w przeciwnym razie false.
     */
    virtual bool Add(const T& entity) = 0;

    /**
     * @brief Usuwa obiekt o podanym identyfikatorze z repozytorium.
     *
     * Metoda ta służy do usuwania obiektów z repozytorium.
     *
     * @param id Identyfikator obiektu, który ma zostać usunięty.
     * @return Zwraca true, jeśli obiekt został usunięty pomyślnie, w przeciwnym razie false.
     */
    virtual bool Delete(int id) = 0;

    /**
     * @brief Zwraca wszystkie obiekty przechowywane w repozytorium.
     *
     * Metoda ta służy do pobierania wszystkich obiektów przechowywanych w repozytorium.
     *
     * @return Zwraca wektor obiektów przechowywanych w repozytorium.
     */
    virtual std::vector<T> GetAll() = 0;
};

#endif // BASEREPOSITORY_H

