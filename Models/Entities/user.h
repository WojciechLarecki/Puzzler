#ifndef USER_H
#define USER_H

#include <QString>
#include <vector>
#include "../Entities/gameresult.h"

class User {
private:
    int _id;
    std::vector<GameResult> _gameResults;
    QString _name;
    int _role;

public:
    QString getName() const;
    void setName(const QString& newName);

    int getRole() const;
    void setRole(int newRole);

    int getId() const;
    void setId(int id);
    std::vector<GameResult> getGameResults() const;
};

#endif // USER_H
