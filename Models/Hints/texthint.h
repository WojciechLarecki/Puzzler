#ifndef TEXTHINT_H
#define TEXTHINT_H

#include "BaseHint.h"

class TextHint : public BaseHint {
private:
    QString hintText;

public:
    TextHint(const QString &text);
    QString getHint() const override;
};

#endif // TEXTHINT_H
