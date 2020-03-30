#ifndef VECTOR1_H
#define VECTOR1_H

typedef struct {     //complex vector
    double x, y, z;
    double xi, yi, zi;
} vectorr;

typedef struct {     //real vector
    double x, y, z;
} vector2;

typedef struct rez {
    double rez_scal, rez_scalcomplex;
} rez;



vectorr create(vectorr* vec1, int m, int countt);
vector2 create_real(vector2* vec1, int m, int countt);

void sum_c(vectorr* vec1, vectorr* vecc, int i);
vector2 sum_real(vector2* vec1, vector2* vec_sum, int i);
rez scalar_pr_c(vectorr* vec1, rez* rez2, int i);
double scalar_pr_real(vector2* vec1, double* rezz, int i);
vectorr vector_pr_c(vectorr* vec1, vectorr* vec_pr, int i);
vector2 vector_pr_real(vector2* vec1, vector2* vec_pr, int i);

#endif