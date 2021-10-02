#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H

#include "fraction.h"
#include "complex.h"
#include "polar.h"

/*
 * Структура, обобщающая комплексные, дробные и полярные числа.
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

/* Ввод числа из файла.
 *  Формат: <type>\n
 *         <specific input>\n
 * @param: num - указатель на объект number, который нужно заполнить из файла.
 * @param: input_file - указатель на входной файл
 * @returns: status code.
*/
int In(number* num, FILE* input_file);

/* Вывод числа в файл.
 * @param: num - указатель на объект number, который нужно вывести.
 * @param: output_file - указатель на выходной файл.
 */
void Out(const number* num, FILE* output_file);

/* Конвертация к типу double.
 * @param: num - указатель на объект number, который нужно привести к double.
 * @returns: double представление числа.
*/
double CastToDouble(const number* num);

#endif //PROJECT_NUMBER_H
