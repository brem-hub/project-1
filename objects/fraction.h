#ifndef PROJECT_FRACTION_H
#define PROJECT_FRACTION_H

#include <stdio.h>
#include "../utils/utils.h"

/*
 * Описание базовой структуры дробных чисел.
 */
struct fraction {
    int numerator;
    int denominator;
};

/* Ввод дробного числа из файла.
 *  Формат: <numerator> <denominator>\n
 * @param: frac - указатель на объект fraction, который нужно заполнить из файла.
 * @param: input_file - указатель на входной файл
 * @returns: status code.
*/
int In(fraction* frac, FILE* input_file);

/* Случайное заполнение дробного числа.
 * @param: frac - указатель на объект fraction, который нужно заполнить.
 */
void RandIn(fraction* frac);

/* Вывод дробного числа в файл.
 * @param: frac - указатель на объект fraction, который нужно вывести.
 * @param: output_file - указатель на выходной файл.
 */
void Out(const fraction* frac, FILE* output_file);

/* Конвертация к типу double.
 * @param: frac - указатель на объект fraction, который нужно привести к double.
 * @returns: double представление дробного числа.
*/
double CastToDouble(const fraction* frac);

#endif //PROJECT_FRACTION_H
