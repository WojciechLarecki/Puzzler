#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QSqlDatabase>

/**
 * @brief Klasa do stworzenia bazy danych.
 *
 * Klasa `DatabaseController` odpowiada za wygenerowanie pliku do przechowywania danych aplikacji.
 */
class DatabaseController
{
private:
    QSqlDatabase db; ///< Obiekt reprezentujący połączenie z bazą danych.

public:
    /**
     * @brief Konstruktor klasy DatabaseController.
     *
     * Tworzy instancję klasy `DatabaseController`, inicjalizując połączenie z bazą danych.
     */
    DatabaseController();

    /**
     * @brief Inicjalizuje połączenie z bazą danych.
     *
     * Metoda ta konfiguruje połączenie z bazą danych.
     * Dba o sprawdzenie, czy połączenie zostało pomyślnie nawiązane.
     */
    void Initialize();
};

#endif // DATABASECONTROLLER_H
