#include <stdio.h>
#include "math.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include "vector.h"

vectorr create(vectorr* vec1, int m, int countt) {

    vectorr* temporarily = vec1 + m;
    (temporarily)->x = m * countt + 0.5;
    (temporarily)->y = m * countt + 1;
    (temporarily)->z = m * countt + 2;

    (temporarily)->xi = m * countt + 1;
    (temporarily)->yi = m * countt * 2;
    (temporarily)->zi = m * countt + 3.5;

    return *temporarily;

}


vector2 create_real(vector2* vec1, int m, int countt) {

    vector2* temporarily = vec1 + m;
    (temporarily)->x = m * countt + 0.5;
    (temporarily)->y = m * countt + 1;
    (temporarily)->z = m * countt + 2;

    return *temporarily;

}


void sum_c(vectorr* vec1, vectorr* vecc, int i) {

    (vecc + i / 2)->x = (vec1 + i)->x + (vec1 + i + 1)->x;
    (vecc + i / 2)->y = (vec1 + i)->y + (vec1 + i + 1)->y;
    (vecc + i / 2)->z = (vec1 + i)->z + (vec1 + i + 1)->z;
    (vecc + i / 2)->xi = (vec1 + i)->xi + (vec1 + i + 1)->xi;
    (vecc + i / 2)->yi = (vec1 + i)->yi + (vec1 + i + 1)->yi;
    (vecc + i / 2)->zi = (vec1 + i)->zi + (vec1 + i + 1)->zi;

}



vector2 sum_real(vector2* vec1, vector2* vec_sum, int i) {

    vector2* vecc = vec_sum + i / 2;
    (vecc)->x = (vec1 + i)->x + (vec1 + i + 1)->x;
    (vecc)->y = (vec1 + i)->y + (vec1 + i + 1)->y;
    (vecc)->z = (vec1 + i)->z + (vec1 + i + 1)->z;

    return *vecc;
}







rez scalar_pr_c(vectorr* vec1, rez* rez2, int i) {

    rez* rez1 = rez2 + i;
    (rez1)->rez_scal = (vec1 + i)->x * (vec1 + i + 1)->x + (vec1 + i)->y * (vec1 + i + 1)->y +
        (vec1 + i)->z * (vec1 + i + 1)->z - (vec1 + i)->xi * (vec1 + i + 1)->xi -
        (vec1 + i)->yi * (vec1 + i + 1)->yi - (vec1 + i)->zi * (vec1 + i + 1)->zi;
    (rez1)->rez_scalcomplex = (vec1 + i)->x * (vec1 + i + 1)->xi + (vec1 + i)->xi * (vec1 + i + 1)->x +
        (vec1 + i)->y * (vec1 + i + 1)->yi + (vec1 + i)->yi * (vec1 + i + 1)->y +
        (vec1 + i)->z * (vec1 + i + 1)->zi + (vec1 + i)->zi * (vec1 + i + 1)->z;

    return *rez1;
}

double scalar_pr_real(vector2* vec1, double* rezz, int i) {

    double* rez1 = rezz + i / 2;
    *(rez1 + i / 2) = (vec1 + i)->x * (vec1 + i + 1)->x + (vec1 + i)->y *
        (vec1 + i + 1)->y + (vec1 + i)->z * (vec1 + i + 1)->z;

    return *(rez1 + i / 2);
}

vectorr vector_pr_c(vectorr* vec1, vectorr* vec_pr, int i) {

    vectorr* vec3 = vec_pr + i / 2;
    vec3->x = (vec1 + i)->y * (vec1 + i + 1)->z - (vec1 + i)->z * (vec1 + i + 1)->y -
        (vec1 + i)->yi * (vec1 + i + 1)->zi + (vec1 + i)->zi * (vec1 + i + 1)->yi;
    vec3->xi = (vec1 + i)->y * (vec1 + i + 1)->zi + (vec1 + i)->yi * (vec1 + i + 1)->z -
        (vec1 + i)->z * (vec1 + i + 1)->yi - (vec1 + i)->zi * (vec1 + i + 1)->y;
    vec3->y = (vec1 + i)->z * (vec1 + i + 1)->x - (vec1 + i)->x * (vec1 + i + 1)->z -
        (vec1 + i)->zi * (vec1 + i + 1)->xi + (vec1 + i)->xi * (vec1 + i + 1)->zi;
    vec3->yi = (vec1 + i)->z * (vec1 + i + 1)->xi + (vec1 + i)->zi * (vec1 + i + 1)->x -
        (vec1 + i)->x * (vec1 + i + 1)->zi - (vec1 + i)->xi * (vec1 + i + 1)->z;
    vec3->z = (vec1 + i)->x * (vec1 + i + 1)->y - (vec1 + i)->y * (vec1 + i + 1)->x -
        (vec1 + i)->xi * (vec1 + i + 1)->yi + (vec1 + i)->yi * (vec1 + i + 1)->xi;
    vec3->zi = (vec1 + i)->x * (vec1 + i + 1)->yi + (vec1 + i)->xi * (vec1 + i + 1)->y -
        (vec1 + i)->y * (vec1 + i + 1)->xi - (vec1 + i)->yi * (vec1 + i + 1)->x;

    return *vec3;
}

vector2 vector_pr_real(vector2* vec1, vector2* vec_pr, int i) {

    vector2* vec3 = vec_pr + i / 2;
    vec3->x = (vec1 + i)->y * (vec1 + i + 1)->z - (vec1 + i)->z * (vec1 + i + 1)->y;
    vec3->y = (vec1 + i)->z * (vec1 + i + 1)->x - (vec1 + i)->x * (vec1 + i + 1)->z;
    vec3->z = (vec1 + i)->x * (vec1 + i + 1)->y - (vec1 + i)->y * (vec1 + i + 1)->x;

    return *vec3;
}