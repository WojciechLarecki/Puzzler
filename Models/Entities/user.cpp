#include "user.h"

// Definicja metod klasy User
std::string User::getName() const {
    return _name;
}

void User::setName(const std::string& newName) {
    _name = newName;
}

int User::getRole() const {
    return _role;
}

void User::setRole(int newRole) {
    _role = newRole;
}
