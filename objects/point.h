#ifndef PROJECT_POINT_H
#define PROJECT_POINT_H

#include <stdio.h>

/*
 * Описание базовой структуры точки.
 */
struct point{
    int x;
    int y;
};

/* Ввод точки из файла.
 *  Формат: <x> <y>\n
*/
 int In(point* pt, FILE* input_file);

// Вывод точки в файл.
void Out(const point* pt, FILE* output_file);

#endif //PROJECT_POINT_H
