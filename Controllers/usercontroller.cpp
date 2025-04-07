#include "usercontroller.h"
#include "../Models/Repositories/userrepository.h"

std::vector<User> UserController::getUsers() {
    UserRepository repo;
    return repo.GetAll();
}
