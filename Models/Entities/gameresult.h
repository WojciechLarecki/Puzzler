#ifndef GAMERESULT_H
#define GAMERESULT_H

#include <QString>
#include <QDateTime>

class GameResult {
private:
    int _id;
    int _points;
    QDateTime _startDateTime;
    QDateTime _endDateTime;
    int _boardSize;
    int _userId;

public:
    GameResult();

    int getId() const;
    void setId(int id);

    int getPoints() const;
    void setPoints(int points);

    QDateTime getStartDateTime() const;
    void setStartDateTime(const QDateTime& start);

    QDateTime getEndDateTime() const;
    void setEndDateTime(const QDateTime& end);

    int getBoardSize() const;
    void setBoardSize(int size);

    int getUserId() const;
    void setUserId(int userId);

    template<typename T>
    T calculatePoints() const;
};

template<typename T>
T GameResult::calculatePoints() const {
    T points = _boardSize * 50;
    int minutes = (_endDateTime.toMSecsSinceEpoch() -
                   _startDateTime.toMSecsSinceEpoch()) / 60000;
    points = points - (minutes * 35);

    return points;
}

#endif // GAMERESULT_H
