#ifndef TEXTHINT_H
#define TEXTHINT_H

#include "BaseHint.h"

/**
 * @brief Klasa reprezentująca tekstową podpowiedź.
 *
 * Dziedziczy po klasie BaseHint i implementuje metodę `getHint()`,
 * która zwraca tekstową treść podpowiedzi.
 */
class TextHint : public BaseHint {
private:
    QString hintText; /**< Tekst podpowiedzi. */

public:
    /**
     * @brief Konstruktor klasy TextHint.
     *
     * Inicjalizuje obiekt z podanym tekstem podpowiedzi.
     *
     * @param text Tekst, który ma zostać użyty jako treść podpowiedzi.
     */
    TextHint(const QString &text);

    /**
     * @brief Zwraca treść podpowiedzi jako tekst.
     *
     * @return QString zawierający tekstową podpowiedź.
     */
    QString getHint() const override;
};

#endif // TEXTHINT_H
