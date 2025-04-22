#include "texthint.h"

TextHint::TextHint(const QString &text) : hintText(text) {}

QString TextHint::getHint() const {
    return hintText;
}
