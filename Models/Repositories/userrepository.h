#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "baserepository.h"
#include "../Entities/user.h"
#include <vector>
#include <QSqlDatabase>

/**
 * @brief Klasa repozytorium dla obiektów typu User.
 *
 * Klasa `UserRepository` implementuje interfejs klasy bazowej `RepositoryBase<User>`.
 * Odpowiada za przechowywanie, dodawanie, usuwanie oraz aktualizowanie danych użytkowników
 * w repozytorium bazy danych.
 *
 * @see RepositoryBase
 */
class UserRepository : public RepositoryBase<User> {
public:
    /**
     * @brief Konstruktor klasy UserRepository.
     *
     * Inicjalizuje obiekt repozytorium dla użytkowników.
     */
    UserRepository();

    /**
     * @brief Dodaje nowego użytkownika do repozytorium.
     *
     * Metoda ta dodaje nowy obiekt typu `User` do repozytorium.
     *
     * @param user Obiekt `User`, który ma zostać dodany do repozytorium.
     * @return Zwraca true, jeśli użytkownik został pomyślnie dodany, w przeciwnym razie false.
     */
    bool Add(const User& user) override;

    /**
     * @brief Usuwa użytkownika o podanym identyfikatorze z repozytorium.
     *
     * Metoda ta usuwa obiekt typu `User` z repozytorium na podstawie jego identyfikatora.
     *
     * @param id Identyfikator użytkownika, który ma zostać usunięty.
     * @return Zwraca true, jeśli użytkownik został pomyślnie usunięty, w przeciwnym razie false.
     */
    bool Delete(int id) override;

    /**
     * @brief Zwraca wszystkich użytkowników przechowywanych w repozytorium.
     *
     * Metoda ta pobiera wszystkie obiekty typu `User` przechowywane w repozytorium.
     *
     * @return Zwraca wektor obiektów typu `User`.
     */
    std::vector<User> GetAll() override;

    /**
     * @brief Aktualizuje dane istniejącego użytkownika.
     *
     * Metoda ta pozwala zaktualizować dane użytkownika w repozytorium.
     *
     * @param newUser Obiekt `User`, który zawiera zaktualizowane dane.
     * @return Zwraca true, jeśli dane użytkownika zostały pomyślnie zaktualizowane, w przeciwnym razie false.
     */
    bool Update(const User& newUser);

private:
    QSqlDatabase db; ///< Obiekt reprezentujący bazę danych.
};

#endif // USERREPOSITORY_H
