#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include "../objects/number.h"

#define MAX_CONTAINER_SIZE 10000

/*
 * Контейнер, хранящий разные виды чисел: комплексные, дроби и радиальные.
 */
struct container {
    int length;
    number* numbers[MAX_CONTAINER_SIZE+1];
};

// Конструктор контейнера.
container* Ctor();

// Добавить число в контейнер.
int Add(container* ct,const number* num);

// Заполнить контейнер из файла.
int Fill(container* ct, FILE* input_file);

// Заполнить контейнер случайными числами.
int RandomFill(container* ct, int size, FILE* generator_output_file = NULL);

// Деструктор контейнера.
void Dtor(container* ct);

// Сортировка контейнера вставками.
void StraightSort(container* ct);

// Вывод контейнера в файл.
void Out(const container* ct, FILE* output_file);

#endif //PROJECT_CONTAINER_H
