#ifndef PROJECT_COMPLEX_H
#define PROJECT_COMPLEX_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../utils/utils.h"

/*
 * Описание базовой структуры комплексных чисел.
 */
struct complex {
    double real;
    double imaginary;
};

/* Ввод комплексного числа из файла.
 *  Формат: <real> <imaginary>\n
*/
int In(complex* c_n, FILE* input_file);

// Случайное заполнение комплексного числа.
void RandIn(complex* c_n);

// Вывод комплексного числа.
void Out(const complex* c_n, FILE* output_file);

// Конвертация к типу double.
double CastToDouble(const complex* c_n);

#endif //PROJECT_COMPLEX_H
