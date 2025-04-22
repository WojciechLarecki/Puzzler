#include "gamecontroller.h"
#include <chrono>
#include <random>
#include <stdexcept>

QVector<int> GameController::getGameCombination(int size) {
    QVector<int> numbers;
    for (int i = 1; i < size * size; ++i) {
        numbers.append(i);
    }
    numbers.append(0); // 0 represents the empty tile

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);

    // Try up to 30 times to generate a solvable and not-already-solved board
    for (int i = 0; i < 30; ++i) {
        std::shuffle(numbers.begin(), numbers.end(), rng);
        if (isSolvable(numbers, size) && !isAlreadySolved(numbers)) {
            break;
        } else if (i == 29) {
            throw std::runtime_error("Failed to generate a solvable and unsolved board after 30 attempts.");
        }
    }

    return numbers;
}

bool GameController::isSolvable(const QVector<int>& oneDArray, int size) {
    int inversions = 0;

    // Count the number of inversions (pairs where a higher number precedes a lower one)
    for (int i = 0; i < oneDArray.size(); ++i) {
        for (int j = i + 1; j < oneDArray.size(); ++j) {
            if (oneDArray[i] != 0 && oneDArray[j] != 0 && oneDArray[i] > oneDArray[j]) {
                ++inversions;
            }
        }
    }

    // Find the row of the empty tile (0) from the bottom
    int zeroIndex = oneDArray.indexOf(0);
    int zeroRowFromBottom = size - (zeroIndex / size);

    // Solvability rules:
    // For odd grid sizes: solvable if number of inversions is even
    // For even grid sizes: solvable if
    //  empty row from bottom is even and inversions is odd
    //  OR empty row from bottom is odd and inversions is even
    if (size % 2 == 1) {
        return inversions % 2 == 0;
    } else {
        return (zeroRowFromBottom % 2 == 0) ? (inversions % 2 == 1)
                                            : (inversions % 2 == 0);
    }
}

bool GameController::isAlreadySolved(const QVector<int>& array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        if (array[i] != i + 1)
            return false;
    }
    // Last element should be 0
    return array[array.size() - 1] == 0;
}
