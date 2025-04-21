#ifndef GAMERESULTCONTROLLER_H
#define GAMERESULTCONTROLLER_H

#include "../Models/gameresulttabledto.h"
#include "vector"

class GameResultController
{
public:
    std::vector<GameResultTableDTO> getResults();
    bool DeleteResult(int resultId);
    bool AddResult(GameResult result);
};

#endif // GAMERESULTCONTROLLER_H
