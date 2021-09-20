#ifndef PROJECT_POLAR_H
#define PROJECT_POLAR_H

#include "point.h"
#ifndef PROJECT_UTILS_H
#include "../utils/utils.h"
#endif

/*
 * Описание базовой структуры полярных чисел.
 */
struct polar {
    double angle;
    point coords;

};

/* Ввод полярного числа из файла.
 *  Формат: <angle> <coords_x> <coords_y>\n
*/
int In(polar* pol, FILE* input_file);

// Случайное заполнение полярного числа.
void RandIn(polar* pol);

// Вывод полярного числа в файл.
void Out(const polar* pol, FILE* output_file);

// Конвертация к типу double.
double CastToDouble(const polar* pol);

#endif //PROJECT_POLAR_H
