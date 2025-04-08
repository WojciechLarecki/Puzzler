#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include <vector>
#include "../Models/Entities/user.h"

class UserController
{
public:
    std::vector<User> getUsers();
    bool AddUser(User user);
    bool DeleteUser(int userId);
    bool UpdateUser(User newUser);
};

#endif // USERCONTROLLER_H
