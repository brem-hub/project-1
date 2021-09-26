#ifndef PROJECT_FRACTION_H
#define PROJECT_FRACTION_H

#include <stdio.h>
#include "../utils/utils.h"

/*
 * Описание базовой структуры дробей.
 */
struct fraction {
    int numerator;
    int denominator;
};

// Ввод дроби из файла.
// Формат: <numerator> <denominator>\n
 int In(fraction* frac, FILE* input_file);

// Случайное заполнение дроби.
void RandIn(fraction* frac);

// Вывод дроби.
void Out(const fraction* frac, FILE* output_file);

// Конвертация к типу double.
double CastToDouble(const fraction* frac);

#endif //PROJECT_FRACTION_H
