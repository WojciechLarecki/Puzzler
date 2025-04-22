#ifndef BASEHINT_H
#define BASEHINT_H

#include <QString>

class BaseHint {
public:
    virtual QString getHint() const = 0;
    virtual ~BaseHint() {}
};

#endif // BASEHINT_H
