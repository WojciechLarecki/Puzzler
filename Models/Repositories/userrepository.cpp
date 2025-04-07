#include "userrepository.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>  // Dodaj nagłówek dla std::vector

UserRepository::UserRepository() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db"); // lub pełna ścieżka: "C:/path/to/mydb.db"

    if (!db.open()) {
        qDebug() << "Błąd otwarcia bazy danych:" << db.lastError().text();
    } else {
        qDebug() << "Połączono z bazą danych.";
    }

    QSqlQuery query;
    QString createTable = R"(
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        age INTEGER
    ))";

    if (!query.exec(createTable)) {
        qDebug() << "Błąd tworzenia tabeli:" << query.lastError().text();
    }
}

void UserRepository::Add(User user) {
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO users (name, age) VALUES (?, ?)");
    //insertQuery.addBindValue(user.getName());
    insertQuery.addBindValue(user.getRole());
    if (!insertQuery.exec()) {
        qDebug() << "Błąd dodawania danych:" << insertQuery.lastError().text();
    }
}

std::vector<User> UserRepository::GetAll() {
    std::vector<User> users;
    QSqlQuery selectQuery("SELECT id, name, age FROM users");
    while (selectQuery.next()) {
        int id = selectQuery.value("id").toInt();
        QString name = selectQuery.value("name").toString();
        int age = selectQuery.value("age").toInt();

        // Tworzymy obiekt User i dodajemy do wektora
        User user;
        user.setName(name.toStdString());
        user.setRole(age);
        users.push_back(user);
        qDebug() << id << name << age;
    }

    return users;  // Zwracamy wektor
}

