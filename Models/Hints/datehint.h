#ifndef DATEHINT_H
#define DATEHINT_H

#include "BaseHint.h"
#include <QDateTime>

class DateHint : public BaseHint {
private:
    QDateTime _date;

public:
    DateHint(const QDateTime &datetime);
    QString getHint() const override;
};
#endif // DATEHINT_H
