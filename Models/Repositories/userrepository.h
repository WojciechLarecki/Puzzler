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

    void Add(User user);
    std::vector<User> GetAll();
};

#endif // USERREPOSITORY_H
