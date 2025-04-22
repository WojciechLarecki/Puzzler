#ifndef DATEHINT_H
#define DATEHINT_H

#include "BaseHint.h"
#include <QDateTime>

/**
 * @brief Klasa reprezentująca podpowiedź zawierającą datę i czas.
 *
 * Dziedziczy po klasie BaseHint i implementuje metodę `getHint()`,
 * która zwraca datę i czas w formacie tekstowym.
 */
class DateHint : public BaseHint {
private:
    QDateTime _date; /**< Data i czas, które będą używane jako treść podpowiedzi. */

public:
    /**
     * @brief Konstruktor klasy DateHint.
     *
     * Inicjalizuje obiekt z podaną datą i czasem.
     *
     * @param datetime Obiekt QDateTime reprezentujący datę i czas.
     */
    DateHint(const QDateTime &datetime);

    /**
     * @brief Zwraca treść podpowiedzi w formie sformatowanej daty i czasu.
     *
     * @return QString zawierający datę i czas.
     */
    QString getHint() const override;
};

#endif // DATEHINT_H
