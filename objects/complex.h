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
 * @param: c_n - указатель на объект complex, который нужно заполнить из файла.
 * @param: input_file - указатель на входной файл
 * @returns: status code.
*/
int In(complex* c_n, FILE* input_file);

/* Случайное заполнение комплексного числа.
 * @param: c_n - указатель на объект complex, который нужно заполнить.
 */
void RandIn(complex* c_n);

/* Вывод комплексного числа в файл.
 * @param: c_n - указатель на объект complex, который нужно вывести.
 * @param: output_file - указатель на выходной файл.
 */
void Out(const complex* c_n, FILE* output_file);

/* Конвертация к типу double.
 * @param: c_n - указатель на объект complex, который нужно привести к double.
 * @returns: double представление комплексного числа.
*/
double CastToDouble(const complex* c_n);

#endif //PROJECT_COMPLEX_H
