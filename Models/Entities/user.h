#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string _name;
    int _role;

public:
    std::string getName() const;
    void setName(const std::string& newName);

    int getRole() const;
    void setRole(int newRole);
};

#endif // USER_H
