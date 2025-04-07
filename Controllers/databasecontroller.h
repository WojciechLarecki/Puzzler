#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H
#include <QSqlDatabase>

class DatabaseController
{
private:
    QSqlDatabase db;
public:
    DatabaseController();
    void Initialize();
};

#endif // DATABASECONTROLLER_H
