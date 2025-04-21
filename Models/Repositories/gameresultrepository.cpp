#include "gameresultrepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <stdexcept>

GameResultRepository::GameResultRepository() {}

bool GameResultRepository::Add(GameResult gameResult) {
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO GameResults (points, startDateTime, endDateTime, boardSize, userId)
        VALUES (?, ?, ?, ?, ?)
    )");

    query.addBindValue(gameResult.getPoints());
    query.addBindValue(gameResult.getStartDateTime().toString(Qt::ISODate));
    query.addBindValue(gameResult.getEndDateTime().toString(Qt::ISODate));
    query.addBindValue(gameResult.getBoardSize());
    query.addBindValue(gameResult.getUserId());

    if (!query.exec()) {
        throw std::runtime_error("Error while creating Users table: " + query.lastError().text().toStdString());
    }

    return true;
}

bool GameResultRepository::Delete(int id) {
    QSqlQuery query;
    query.prepare(R"(
        DELETE FROM GameResults WHERE id = ?
    )");
    query.addBindValue(id);

    if (!query.exec()) {
        throw std::runtime_error("Error while deleting GameResults: " + query.lastError().text().toStdString());
    }

    return query.numRowsAffected() > 0;
}

std::vector<GameResult> GameResultRepository::GetAll() {
    std::vector<GameResult> results;

    QSqlQuery query("SELECT id, points, startDateTime, endDateTime, boardSize, userId FROM GameResults");

    while (query.next()) {
        GameResult result;

        result.setId(query.value("id").toInt());
        result.setPoints(query.value("points").toInt());
        result.setStartDateTime(QDateTime::fromString(query.value("startDateTime").toString(), Qt::ISODate));
        result.setEndDateTime(QDateTime::fromString(query.value("endDateTime").toString(), Qt::ISODate));
        result.setBoardSize(query.value("boardSize").toInt());
        result.setUserId(query.value("userId").toInt());

        results.push_back(result);
    }

    return results;
}
