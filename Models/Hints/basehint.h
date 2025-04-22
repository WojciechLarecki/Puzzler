#ifndef BASEHINT_H
#define BASEHINT_H

#include <QString>

/**
 * @brief Klasa bazowa dla wszystkich podpowiedzi w grze.
 *
 * Klasa abstrakcyjna definiująca wspólny interfejs dla różnych typów podpowiedzi.
 * Każda podklasa musi zaimplementować metodę `getHint()`, która zwraca treść podpowiedzi jako QString.
 */
class BaseHint {
public:
    /**
     * @brief Zwraca treść podpowiedzi.
     *
     * Metoda abstrakcyjna, zaimplementowana w klasach dziedziczących.
     *
     * @return Treść podpowiedzi jako QString.
     */
    virtual QString getHint() const = 0;

    /**
     * @brief Wirtualny destruktor.
     *
     * Zapewnia poprawne zwolnienie zasobów podczas usuwania obiektów przez wskaźnik do klasy bazowej.
     */
    virtual ~BaseHint() {}
};

#endif // BASEHINT_H
