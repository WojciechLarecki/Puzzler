#ifndef GAMERESULT_H
#define GAMERESULT_H

#include <QString>
#include <QDateTime>

class GameResult {
private:
    int _id;
    int _points;
    //QString _hintUsed; // np. "1,0,1" jako ciąg znaków
    QDateTime _startDateTime;
    QDateTime _endDateTime;
    int _boardSize;

public:
    GameResult();

    int getId() const;
    void setId(int id);

    int getPoints() const;
    void setPoints(int points);

    //QString getHintUsed() const;
    QDateTime getStartDateTime() const;
    void setStartDateTime(const QDateTime& start);

    QDateTime getEndDateTime() const;
    void setEndDateTime(const QDateTime& end);

    int getBoardSize() const;
    void setBoardSize(int size);
};

#endif // GAMERESULT_H
