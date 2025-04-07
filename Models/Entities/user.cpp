#include "user.h"

QString User::getName() const {
    return _name;
}

void User::setName(const QString& newName) {
    _name = newName;
}

int User::getRole() const {
    return _role;
}

void User::setRole(int newRole) {
    _role = newRole;
}

int User::getId() const {
    return _id;
}

void User::setId(int id) {
    _id = id;
}

std::vector<GameResult> User::getGameResults() const {
    return _gameResults;
}
