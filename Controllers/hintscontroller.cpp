#include "hintscontroller.h"
#include <random>

HintsController::HintsController() {

    seed = std::chrono::system_clock::now().time_since_epoch().count();

    _hints.push_back(new TextHint("Przerwanie gry nie zapisze twojego wyniku."));
    _hints.push_back(new TextHint("Jeśli zresetujesz grę twój czas oraz punkty zostaną wyzerowane."));
    _hints.push_back(new TextHint("Jeśli masz problem z ułożeniem kombinacji możesz zresetować grę za pomocą odpowiedniego przycisku."));
}

std::vector<BaseHint*> HintsController::getHints() {
    return _hints;
}

void HintsController::AddStartDateHint(QDateTime dt) {
    _hints.push_back(new DateHint(dt));
}

HintsController::~HintsController() {
    for (BaseHint* hint : _hints) {
        delete hint;
    }
    _hints.clear();
}

BaseHint* HintsController::GetRandom() {
    std::shuffle(_hints.begin(), _hints.end(), std::default_random_engine(seed));
    return _hints[0];
}
