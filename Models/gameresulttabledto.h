#ifndef GAMERESULTTABLEDTO_H
#define GAMERESULTTABLEDTO_H

#include "Entities/gameresult.h"
#include <QString>


class GameResultTableDTO
{
private:
    GameResult _game;
    QString _userName;

public:
    GameResultTableDTO(GameResult game, QString userName);

    QString getUserName() const;
    void setUserName(const QString& newUserName);

    GameResult getGame() const;
    void setGame(const GameResult& game);
};

#endif // GAMERESULTTABLEDTO_H
