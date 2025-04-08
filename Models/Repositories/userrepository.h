#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "../Entities/user.h"
#include <vector>
#include <QSqlDatabase>

class UserRepository
{
private:
    QSqlDatabase db;

public:
    UserRepository();

    bool Add(User user);
    std::vector<User> GetAll();
    bool Delete(int id);
    bool Update(User newUser);
};

#endif // USERREPOSITORY_H
