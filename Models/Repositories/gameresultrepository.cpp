#include "gameresultrepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <stdexcept>

GameResultRepository::GameResultRepository() {}

bool GameResultRepository::Add(GameResult gameResult) {
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO GameResult (points, startDateTime, endDateTime, boardSize)
        VALUES (?, ?, ?, ?)
    )");

    query.addBindValue(gameResult.getPoints());
    //query.addBindValue(_hintUsed);
    query.addBindValue(gameResult.getStartDateTime().toString(Qt::ISODate));
    query.addBindValue(gameResult.getEndDateTime().toString(Qt::ISODate));
    query.addBindValue(gameResult.getBoardSize());

    if (!query.exec()) {
        throw std::runtime_error("Error while creating Users table: " + query.lastError().text().toStdString());
    }

    return true;
}
