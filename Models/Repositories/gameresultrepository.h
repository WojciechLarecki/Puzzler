#ifndef GAMERESULTREPOSITORY_H
#define GAMERESULTREPOSITORY_H
#include "../Entities/gameresult.h"
#include "vector"

class GameResultRepository
{
public:
    GameResultRepository();
    bool Add(GameResult gameResult);
    bool Delete(int resultId);
    std::vector<GameResult> GetAll();
};

#endif // GAMERESULTREPOSITORY_H
