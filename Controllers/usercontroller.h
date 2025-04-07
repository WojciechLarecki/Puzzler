#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include <vector>
#include "../Models/Entities/user.h"

class UserController
{
public:
    std::vector<User> getUsers();
};

#endif // USERCONTROLLER_H
