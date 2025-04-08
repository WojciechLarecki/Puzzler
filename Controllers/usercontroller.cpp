#include "usercontroller.h"
#include "../Models/Repositories/userrepository.h"
#include <stdexcept>

std::vector<User> UserController::getUsers() {
    UserRepository repo;
    return repo.GetAll();
}

bool UserController::DeleteUser(int userId) {
    UserRepository repo;
    return repo.Delete(userId);
}

bool UserController::UpdateUser(User newUser) {
    UserRepository repo;
    return repo.Update(newUser);
}

bool UserController::AddUser(User user) {
    UserRepository repo;
    return repo.Add(user);
}
