#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void create(vector* vec1, int m, int count) {
    
    if (vec1->com == 1) {
        vec1->v1[m].x = m * count + 0.5;
        vec1->v1[m].y = m * count + 1;
        vec1->v1[m].z = m * count + 2;

        vec1->v1[m].xi = m * count + 1;
        vec1->v1[m].yi = m * count * 2;
        vec1->v1[m].zi = m * count + 3.5;
    }

    else {
        vec1->v2[m].x = m * count + 0.5;
        vec1->v2[m].y = m * count + 1;
        vec1->v2[m].z = m * count + 2;
    }
 }

void sum(vector* vec1, vector* vecc, int m, int n) {

    if (vec1->com == 1) {
        (vecc)->v1[n].x = vec1->v1[m].x + vec1->v1[1 + m].x;
        (vecc)->v1[n].y = vec1->v1[m].y + vec1->v1[1 + m].y;
        (vecc)->v1[n].z = vec1->v1[m].z + vec1->v1[1 + m].z;

        (vecc)->v1[n].xi = vec1->v1[m].xi + vec1->v1[1 + m].xi;
        (vecc)->v1[n].yi = vec1->v1[m].yi + vec1->v1[1 + m].yi;
        (vecc)->v1[n].zi = vec1->v1[m].zi + vec1->v1[1 + m].zi; }

    else {
        (vecc)->v2[n].x = vec1->v2[m].x + vec1->v2[1 + m].x;
        (vecc)->v2[n].y = vec1->v2[m].y + vec1->v2[1 + m].y;
        (vecc)->v2[n].z = vec1->v2[m].z + vec1->v2[1 + m].z; }

}



void scalar_pr(vector* vec1, rez* rez2, int m, int n) {

    if (vec1->com == 1) {

        (rez2+n)->rez_scal = vec1->v1[m].x * vec1->v1[1 + m].x + vec1->v1[m].y * vec1->v1[1 + m].y +
            vec1->v1[m].z * vec1->v1[1 + m].z - vec1->v1[m].xi * vec1->v1[1 + m].xi -
            vec1->v1[m].yi * vec1->v1[1 + m].yi - vec1->v1[m].zi * vec1->v1[1 + m].zi;

        (rez2+n)->rez_scalcomplex = vec1->v1[m].x * vec1->v1[1 + m].xi + vec1->v1[m].xi * vec1->v1[1 + m].x +
            vec1->v1[m].y * vec1->v1[1 + m].yi + vec1->v1[m].yi * vec1->v1[1 + m].y +
            vec1->v1[m].z * vec1->v1[1 + m].zi + vec1->v1[m].zi * vec1->v1[1 + m].z; }

    else {
        (rez2+n)->rez_scal = vec1->v2[m].x * vec1->v1[1 + m].x + vec1->v2[m].y *
            vec1->v2[1 + m].y + vec1->v2[m].z * vec1->v2[1 + m].z; }
}


void vector_pr(vector* vec1, vector* vec3, int m) {


    if (vec1->com == 1) {

        vec3->v1[m].x = vec1->v1[m].y * vec1->v1[1 + m].z - vec1->v1[m].z * vec1->v1[1 + m].y -
            vec1->v1[m].yi * vec1->v1[1 + m].zi + vec1->v1[m].zi * vec1->v1[1 + m].yi;

        vec3->v1[m].xi = vec1->v1[m].y * vec1->v1[1 + m].zi + vec1->v1[m].yi * vec1->v1[1 + m].z -
            vec1->v1[m].z * vec1->v1[1 + m].yi - vec1->v1[m].zi * vec1->v1[1 + m].y;

        vec3->v1[m].y = vec1->v1[m].z * vec1->v1[1 + m].x - vec1->v1[m].x * vec1->v1[1 + m].z -
            vec1->v1[m].zi * vec1->v1[1 + m].xi + vec1->v1[m].xi * vec1->v1[1 + m].zi;

        vec3->v1[m].yi = vec1->v1[m].z * vec1->v1[1 + m].xi + vec1->v1[m].zi * vec1->v1[1 + m].x -
            vec1->v1[m].x * vec1->v1[1 + m].zi - vec1->v1[m].xi * vec1->v1[1 + m].z;

        vec3->v1[m].z = vec1->v1[m].x * vec1->v1[1 + m].y - vec1->v1[m].y * vec1->v1[1 + m].x -
            vec1->v1[m].xi * vec1->v1[1 + m].yi + vec1->v1[m].yi * vec1->v1[1 + m].xi;

        vec3->v1[m].zi = vec1->v1[m].x * vec1->v1[1 + m].yi + vec1->v1[m].xi * vec1->v1[1 + m].y -
            vec1->v1[m].y * vec1->v1[1 + m].xi - vec1->v1[m].yi * vec1->v1[1 + m].x;       }

    else {
        vec3->v2[m].x = vec1->v2[m].y * vec1->v2[1 + m].z - vec1->v2[m].z * vec1->v2[1 + m].y;
        vec3->v2[m].y = vec1->v2[m].z * vec1->v2[1 + m].x - vec1->v2[m].x * vec1->v2[1 + m].z;
        vec3->v2[m].z = vec1->v2[m].x * vec1->v2[1 + m].y - vec1->v2[m].y * vec1->v2[1 + m].x;   }

}