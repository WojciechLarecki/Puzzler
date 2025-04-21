#ifndef GAMERESULTCONTROLLER_H
#define GAMERESULTCONTROLLER_H

#include "../Models//Entities/gameresult.h"
#include "vector"

class GameResultController
{
public:
    GameResultController();

    std::vector<GameResult> getResults();
    bool DeleteResult(int resultId);
};

#endif // GAMERESULTCONTROLLER_H
