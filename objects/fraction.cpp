#include "fraction.h"

int In(fraction *frac, FILE* input_file){
    int numerator, denominator;

    int res = fscanf(input_file, "%d %d", &numerator, &denominator);

    if (res != 2){
        printf("Could not parse fraction\n");
        return 1;
    }

    if (denominator == 0){
        printf("Denominator cannot be 0\n");
        return 1;
    }

    frac->numerator = numerator;
    frac->denominator = denominator;

    return 0;
}

void RandIn(fraction* frac){
    frac->numerator = Random(-100, 100);
    frac->denominator = Random(1, 100);
}

void Out(const fraction* frac, FILE* output_file){
    fprintf(output_file, "fraction: %d/%d\n", frac->numerator, frac->denominator);
}

double CastToDouble(const fraction* frac){
    return (frac->numerator + 0.0) / frac->denominator;
}