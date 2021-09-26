#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H

#include "fraction.h"
#include "complex.h"
#include "polar.h"

/*
 * Структура, обобщающая различные числа.
 */
struct number {
    // тип числа.
    enum number_type {COMPLEX, FRACTION, POLAR} number_type;
    union {
        complex com;
        fraction frac;
        polar pol;
    };
};

// Ввод числа из файла.
// Формат: <type>\n
//         <specific input>\n
int In(number* num, FILE* input_file);

void Out(const number* num, FILE* output_file);

double CastToDouble(const number* num);

#endif //PROJECT_NUMBER_H
