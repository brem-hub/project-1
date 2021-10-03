#include "polar.h"
#include "math.h"

int In(polar* pol, FILE* input_file){
    double angle;

    int res = fscanf(input_file, "%lf", &angle);

    if (res != 1){
        printf("Could not parse polar number angle\n");
        return 1;
    }

    pol->angle = angle;

    res = In(&pol->coords, input_file);

    return res;
}

void RandIn(polar* pol){
    pol->angle = DoubleRand(0, 10);
    pol->coords.x = Random(-100, 100);
    pol->coords.y = Random(-100, 100);
}

void Out(const polar* pol, FILE* output_file){
    fprintf(output_file, "polar: w=%lf; coords=", pol->angle);
    Out(&pol->coords, output_file);
    fprintf(output_file, " ; double representation: %lf\n", CastToDouble(pol));
}

double CastToDouble(const polar* pol){
    return sqrt(pol->coords.x * pol->coords.x + pol->coords.y * pol->coords.y);
}