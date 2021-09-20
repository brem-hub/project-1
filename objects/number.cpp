#include "number.h"

int In(number* num, FILE* input_file){
    int type = -1;
    fscanf(input_file, "%d\n", &type);

    switch (type) {
        case number::COMPLEX:
            num->number_type = number::COMPLEX;
            return In(&num->com, input_file);
        case number::FRACTION:
            num->number_type = number::FRACTION;
            return In(&num->frac, input_file);
        case number::POLAR:
            num->number_type = number::POLAR;
            return In(&num->pol, input_file);
        default:
            printf("Could not parse number type\n");
            return 1;
    }
}

void Out(const number* num, FILE* output_file){
    switch (num->number_type) {
        case number::FRACTION:
            Out(&num->frac, output_file);
            return;
        case number::COMPLEX:
            Out(&num->com, output_file);
            return;
        case number::POLAR:
            Out(&num->pol, output_file);
            return;
    }
}

double CastToDouble(const number* num){
    switch (num->number_type) {
        case number::COMPLEX:
            return CastToDouble(&num->com);
        case number::FRACTION:
            return CastToDouble(&num->frac);
        default:
            return CastToDouble(&num->pol);
    }
}