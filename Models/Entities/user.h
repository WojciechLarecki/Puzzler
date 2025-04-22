#ifndef USER_H
#define USER_H

#include <QString>
#include <vector>
#include "../Entities/gameresult.h"

/**
 * @brief Klasa reprezentująca użytkownika aplikacji.
 *
 * Przechowuje dane użytkownika takie jak imię, rola, identyfikator oraz lista wyników gier.
 */
class User {
private:
    int _id; ///< Identyfikator użytkownika.
    std::vector<GameResult> _gameResults; ///< Lista wyników gier danego użytkownika.
    QString _name; ///< Nazwa użytkownika.
    int _role; ///< Rola użytkownika (zwykły gracz, administrator).

public:
    /**
     * @brief Pobiera nazwę użytkownika.
     * @return Nazwa użytkownika jako QString.
     */
    QString getName() const;

    /**
     * @brief Ustawia nazwę użytkownika.
     * @param newName Nowa nazwa użytkownika.
     */
    void setName(const QString& newName);

    /**
     * @brief Pobiera rolę użytkownika.
     * @return Rola użytkownika (np. 0 - gracz, 1 - administrator).
     */
    int getRole() const;

    /**
     * @brief Ustawia rolę użytkownika.
     * @param newRole Nowa rola (np. 0 - gracz, 1 - administrator).
     */
    void setRole(int newRole);

    /**
     * @brief Pobiera identyfikator użytkownika.
     * @return Identyfikator użytkownika.
     */
    int getId() const;

    /**
     * @brief Ustawia identyfikator użytkownika.
     * @param id Nowy identyfikator użytkownika.
     */
    void setId(int id);

    /**
     * @brief Pobiera listę wyników gier użytkownika.
     * @return Wektor wyników gier.
     */
    std::vector<GameResult> getGameResults() const;
};

#endif // USER_H
