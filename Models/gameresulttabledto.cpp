#include "gameresulttabledto.h"

GameResultTableDTO::GameResultTableDTO(GameResult game, QString userName) {
    setUserName(userName);
    setGame(game);
}

GameResult GameResultTableDTO::getGame() const { return _game; }
void GameResultTableDTO::setGame(const GameResult& game) { _game = game; }

QString  GameResultTableDTO::getUserName() const { return _userName; }
void  GameResultTableDTO::setUserName(const QString& newUserName) { _userName = newUserName; }
