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
 * @param: pt - указатель на объект point, который нужно заполнить из файла.
 * @param: input_file - указатель на входной файл
 * @returns: status code.
*/
int In(point* pt, FILE* input_file);

/* Вывод точки в файл.
 * @param: pt - указатель на объект point, который нужно вывести.
 * @param: output_file - указатель на выходной файл.
*/
void Out(const point* pt, FILE* output_file);

#endif //PROJECT_POINT_H
