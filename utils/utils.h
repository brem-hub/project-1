#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include "random"

/*
 * Сгенерировать случайное число с плавающей запятой в полуинтервале [d_min, d_max).
 */
static double DoubleRand(double d_min, double d_max){
    double f = (double)rand() / RAND_MAX;
    return d_min + f * (d_max - d_min);
}

/*
 * Сгенерировать случайное целое число в полуинтервале [min, max).
 */
static int Random(int min, int max){
    return rand() % max + min;
}

#endif //PROJECT_UTILS_H
