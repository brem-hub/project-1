#ifndef PROJECT_POLAR_H
#define PROJECT_POLAR_H

#include "point.h"
#include "../utils/utils.h"

/*
 * Описание базовой структуры полярных чисел.
 */
struct polar {
    double angle;
    point coords;
};

/* Ввод полярного числа из файла.
 *  Формат: <angle> <coords_x> <coords_y>\n
 * @param: pol - указатель на объект polar, который нужно заполнить из файла.
 * @param: input_file - указатель на входной файл
 * @returns: status code.
*/
int In(polar* pol, FILE* input_file);

/* Случайное заполнение полярного числа.
 * @param: pol - указатель на объект polar, который нужно заполнить.
 */
void RandIn(polar* pol);

/* Вывод полярного числа в файл.
 * @param: pol - указатель на объект polar, который нужно вывести.
 * @param: output_file - указатель на выходной файл.
 */
void Out(const polar* pol, FILE* output_file);

/* Конвертация к типу double.
 * @param: pol - указатель на объект polar, который нужно привести к double.
 * @returns: double представление полярного числа.
*/
double CastToDouble(const polar* pol);

#endif //PROJECT_POLAR_H
