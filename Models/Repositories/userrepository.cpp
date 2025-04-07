#include "userrepository.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>

UserRepository::UserRepository() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("puzzler.db");

    // Sprawdzenie, czy baza danych jest otwarta
    if (!db.open()) {
        qDebug() << "Nie udało się połączyć z bazą danych: " << db.lastError().text();
    }
}

void UserRepository::Add(User user) {
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO users (name, role) VALUES (?, ?)");

    // Binding values
    insertQuery.addBindValue(user.getName());
    insertQuery.addBindValue(user.getRole());

    if (!insertQuery.exec()) {
        qDebug() << "Błąd dodawania użytkownika:" << insertQuery.lastError().text();
    }
}

std::vector<User> UserRepository::GetAll() {
    std::vector<User> users;
    QSqlQuery selectQuery("SELECT id, name, role FROM users");

    // check if query was executed fine
    if (!selectQuery.exec()) {
        qDebug() << "Error while selecting users: " << selectQuery.lastError().text();
        throw std::runtime_error("Error while selecting users:" + selectQuery.lastError().text().toStdString());
    }

    while (selectQuery.next()) {
        int id = selectQuery.value("id").toInt();
        QString name = selectQuery.value("name").toString();
        int role = selectQuery.value("role").toInt();

        // Tworzymy obiekt User
        User user;
        user.setName(name);
        user.setRole(role);

        // Można też ustawić ID, jeżeli chcesz je przechować w obiekcie User
        // Zakładając, że masz metodę setId w klasie User
        user.setId(id);

        users.push_back(user);

        qDebug() << "ID:" << id << "Nazwa:" << name << "Rola:" << role;
    }

    return users;
}
