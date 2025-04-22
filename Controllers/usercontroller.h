#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <vector>
#include "../Models/Entities/user.h"

/**
 * @brief Klasa kontrolera użytkowników.
 *
 * Klasa `UserController` odpowiada za zarządzanie użytkownikami w systemie. Umożliwia dodawanie,
 * usuwanie, aktualizowanie oraz pobieranie listy wszystkich użytkowników.
 */
class UserController
{
public:
    /**
     * @brief Pobiera wszystkich użytkowników.
     *
     * Metoda zwraca listę wszystkich użytkowników przechowywanych w systemie.
     *
     * @return std::vector<User> Wektor zawierający wszystkie obiekty typu `User`.
     */
    std::vector<User> getUsers();

    /**
     * @brief Dodaje nowego użytkownika.
     *
     * Metoda dodaje nowego użytkownika do systemu.
     *
     * @param user Obiekt typu `User`, który ma zostać dodany do systemu.
     * @return bool Zwraca `true`, jeśli użytkownik został pomyślnie dodany, w przeciwnym razie `false`.
     */
    bool AddUser(User user);

    /**
     * @brief Usuwa użytkownika na podstawie jego identyfikatora.
     *
     * Metoda usuwa użytkownika z systemu na podstawie jego unikalnego identyfikatora.
     *
     * @param userId Identyfikator użytkownika, który ma zostać usunięty.
     * @return bool Zwraca `true`, jeśli użytkownik został pomyślnie usunięty, w przeciwnym razie `false`.
     */
    bool DeleteUser(int userId);

    /**
     * @brief Aktualizuje dane użytkownika.
     *
     * Metoda aktualizuje dane użytkownika na podstawie podanego obiektu `User`.
     *
     * @param newUser Obiekt typu `User` zawierający zaktualizowane dane użytkownika.
     * @return bool Zwraca `true`, jeśli dane użytkownika zostały pomyślnie zaktualizowane, w przeciwnym razie `false`.
     */
    bool UpdateUser(User newUser);
};

#endif // USERCONTROLLER_H
