#ifndef HINTSCONTROLLER_H
#define HINTSCONTROLLER_H

#include "../Models/Hints/basehint.h"
#include "../Models/Hints/datehint.h"
#include "../Models/Hints/texthint.h"
#include "vector"


class HintsController
{
public:
    HintsController();
    std::vector<BaseHint*> getHints();
    void AddStartDateHint(QDateTime dt);
    BaseHint* GetRandom();
    ~HintsController();
private:
    unsigned seed;
    std::vector<BaseHint*> _hints;
};

#endif // HINTSCONTROLLER_H
