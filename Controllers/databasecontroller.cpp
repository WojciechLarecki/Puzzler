#include "databasecontroller.h"
#include <QSqlQuery>
#include <QSqlError>
#include <stdexcept>

DatabaseController::DatabaseController() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("puzzler.db");
}

void DatabaseController::Initialize() {
    if (!db.open()) {
        throw std::runtime_error("Database not opened: " + db.lastError().text().toStdString());
    }

    QSqlQuery query;

    // Create table Users
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS Users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            role INTEGER NOT NULL
        )
    )")) {
        throw std::runtime_error("Error while creating Users table: " + query.lastError().text().toStdString());
    }

    // Create table GameResults
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS GameResults (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            userId INTEGER NOT NULL,
            points INTEGER NOT NULL,
            hintUsed TEXT,
            startDateTime TEXT,
            endDateTime TEXT,
            boardSize INTEGER NOT NULL,
            FOREIGN KEY(userId) REFERENCES users(id)
        )
    )")) {
        throw std::runtime_error("Error while creating GameResults table: " + query.lastError().text().toStdString());
    }
}
