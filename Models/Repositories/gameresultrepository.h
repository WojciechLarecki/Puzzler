#ifndef GAMERESULTREPOSITORY_H
#define GAMERESULTREPOSITORY_H
#include "../Entities/gameresult.h"

class GameResultRepository
{
public:
    GameResultRepository();
    bool Add(GameResult gameResult);
};

#endif // GAMERESULTREPOSITORY_H
