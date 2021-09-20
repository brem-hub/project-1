#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include "random"

static double DoubleRand(double f_min, double f_max){
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}

static int Random(int min, int max){
    return rand() % max + min;
}
#endif //PROJECT_UTILS_H
