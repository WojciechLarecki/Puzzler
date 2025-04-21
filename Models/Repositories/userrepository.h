#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "baserepository.h"
#include "../Entities/user.h"
#include <vector>
#include <QSqlDatabase>

class UserRepository : public RepositoryBase<User> {
public:
    UserRepository();

    bool Add(const User& user) override;
    bool Delete(int id) override;
    std::vector<User> GetAll() override;
    bool Update(const User& newUser);

private:
    QSqlDatabase db;
};

#endif // USERREPOSITORY_H
