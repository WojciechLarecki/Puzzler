#include "gameresult.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

GameResult::GameResult() {}

int GameResult::getId() const { return _id; }
int GameResult::getPoints() const { return _points; }
QDateTime GameResult::getStartDateTime() const { return _startDateTime; }
QDateTime GameResult::getEndDateTime() const { return _endDateTime; }
int GameResult::getBoardSize() const { return _boardSize; }

void GameResult::setId(int id) { _id = id; }
void GameResult::setPoints(int points) { _points = points; }
void GameResult::setStartDateTime(const QDateTime& start) { _startDateTime = start; }
void GameResult::setEndDateTime(const QDateTime& end) { _endDateTime = end; }
void GameResult::setBoardSize(int size) { _boardSize = size; }

int GameResult::getUserId() const { return _userId; }
void GameResult::setUserId(int userId) { _userId = userId; }
