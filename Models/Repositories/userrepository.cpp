#include "userrepository.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>

UserRepository::UserRepository() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("puzzler.db");

    if (!db.open()) {
        qDebug() << "Error while try to open database: " << db.lastError().text();
        throw std::runtime_error("Error while try to open databases:" + db.lastError().text().toStdString());
    }
}

bool UserRepository::Add(User user) {
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO users (name, role) VALUES (?, ?)");

    // Binding values
    insertQuery.addBindValue(user.getName());
    insertQuery.addBindValue(user.getRole());

    if (!insertQuery.exec()) {
        qDebug() << "Error while inserting users:" << insertQuery.lastError().text();
        throw std::runtime_error("Error while inserting users:" + insertQuery.lastError().text().toStdString());
    }

    return true;
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

        User user;
        user.setName(name);
        user.setRole(role);
        user.setId(id);

        users.push_back(user);

        qDebug() << "ID:" << id << "Nazwa:" << name << "Rola:" << role;
    }

    return users;
}

bool UserRepository::Delete(int id) {
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM users WHERE id = ?");
    deleteQuery.addBindValue(id);

    if (!deleteQuery.exec()) {
        QString error = deleteQuery.lastError().text();
        qDebug() << "Error while deleting user:" << error;
        throw std::runtime_error("Error while deleting user: " + error.toStdString());
    }

    return true;
}

bool UserRepository::Update(User newUser) {
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE users SET name = ?, role = ? WHERE id = ?");
    updateQuery.addBindValue(newUser.getName());
    updateQuery.addBindValue(newUser.getRole());
    updateQuery.addBindValue(newUser.getId());

    if (!updateQuery.exec()) {
        QString error = updateQuery.lastError().text();
        qDebug() << "Error while updating user:" << error;
        throw std::runtime_error("Error while updating user: " + error.toStdString());
    }

    return true;
}
