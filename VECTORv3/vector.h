#ifndef VECTOR1_H
#define VECTOR1_H

typedef struct {     //complex vector
    double x, y, z;
    double xi, yi, zi;
} vectorr;

typedef struct {     //real vector
    double x, y, z;
} vector2;

typedef struct {     // real + complex
    int com;

    void (*sum)();
    void (*create)();
    void (*vector_pr)();
    void (*scalar_pr)();
    
    vectorr v1[2];
    vector2 v2[2];
} vector;

typedef struct rez {

    double rez_scal, rez_scalcomplex;
} rez;



void create(vector* vec1, int m, int count);
void sum(vector* vec1, vector* vecc, int m, int n);
void scalar_pr(vector* vec1, rez* rez2, int m, int n);
void vector_pr(vector* vec1, vector* vec3, int m);

#endif