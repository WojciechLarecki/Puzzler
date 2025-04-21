#include "gameresultcontroller.h"
#include "../Models/Repositories/gameresultrepository.h"
#include "../Models/Repositories/userrepository.h"
#include <stdexcept>

std::vector<GameResult> GameResultController::getResults() {
    GameResultRepository repo;
    UserRepository repo2;

    auto results = repo.GetAll();
    auto users = repo2.GetAll();

    return results;
}

bool GameResultController::DeleteResult(int resultId) {
    GameResultRepository repo;
    return repo.Delete(resultId);
}
