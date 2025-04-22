#include "datehint.h"

DateHint::DateHint(const QDateTime &datetime) : _date(datetime) {}

QString DateHint::getHint() const {
    return "Twoja gra rozpoczęła się o " + _date.toString("hh:mm:ss");
}
