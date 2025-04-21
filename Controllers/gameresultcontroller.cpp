#include "gameresultcontroller.h"
#include "../Models/Repositories/gameresultrepository.h"
#include "../Models/Repositories/userrepository.h"
#include <stdexcept>

std::vector<GameResultTableDTO> GameResultController::getResults() {
    GameResultRepository repo;
    auto results = repo.GetAll();

    UserRepository repo2;
    auto users = repo2.GetAll();

    std::vector<GameResultTableDTO> outputResult;

    for (auto& res: results) {
        for (auto& usr : users) {
            if (res.getUserId() == usr.getId()) {
                GameResultTableDTO dto(res, usr.getName());
                outputResult.push_back(dto);
            }
        }
    }

    return outputResult;
}

bool GameResultController::DeleteResult(int resultId) {
    GameResultRepository repo;
    return repo.Delete(resultId);
}

bool GameResultController::AddResult(GameResult result) {
    GameResultRepository repo;
    return repo.Add(result);
}
