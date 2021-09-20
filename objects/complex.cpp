#include "complex.h"

int In(complex* c_n, FILE* input_file){
    double in_real, in_imaginary;

    int res = fscanf(input_file, "%lf %lf", &in_real, &in_imaginary);
    if (res != 2){
        printf("Could not parse complex number\n");
        return 1;
    }

    c_n->real = in_real;
    c_n->imaginary = in_imaginary;
    return 0;
}

void RandIn(complex* c_n){
    c_n->real = DoubleRand(-100, 100);
    c_n->imaginary = DoubleRand(-100, 100);
}

void Out(const complex* c_n, FILE* output_file){
    fprintf(output_file, "complex number: (%lf, %lf)\n", c_n->real, c_n->imaginary);
}

double CastToDouble(const complex* c_n){
    return sqrt(c_n->real * c_n->real + c_n->imaginary * c_n->imaginary);
}