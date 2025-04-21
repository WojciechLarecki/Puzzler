#ifndef GAMERESULTREPOSITORY_H
#define GAMERESULTREPOSITORY_H

#include "baserepository.h"
#include "../Entities/gameresult.h"
#include "vector"

class GameResultRepository : public RepositoryBase<GameResult> {
public:
    GameResultRepository();

    bool Add(const GameResult& gameResult) override;
    bool Delete(int id) override;
    std::vector<GameResult> GetAll() override;
};

#endif // GAMERESULTREPOSITORY_H
