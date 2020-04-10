#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void user(vectorr* temporarily, double* a, int m) {                     //creating a complex vector by a user

    (temporarily + m)->x = a[0];
    (temporarily + m)->y = a[1];
    (temporarily + m)->z = a[2];

    (temporarily + m)->xi = a[3];
    (temporarily + m)->yi = a[4];
    (temporarily + m)->zi = a[5];
}

void user_real(vector2* temporarily, double* a, int m) {              //creating a real vector

    (temporarily + m)->x = a[0];
    (temporarily + m)->y = a[1];
    (temporarily + m)->z = a[2];
}

void user_candr(vector* vec1, double* a, int m) {                     // candr = complex and real

    if (vec1->com == 1) {
        vec1->v1[m].x = a[0];
        vec1->v1[m].y = a[1];
        vec1->v1[m].z = a[2];
        vec1->v1[m].xi = a[3];
        vec1->v1[m].yi = a[4];
        vec1->v1[m].zi = a[5]; }
    else {
        vec1->v2[m].x = a[0];
        vec1->v2[m].y = a[1];
        vec1->v2[m].z = a[2]; }
}


int comparison_candr(vector* vec1, vectorr* vect2, vector2* vect3, int m) {      //comparison of two complex and real vectors

    if (vec1->com == 1) {
        if (vec1->v1[m].x == (vect2 + m)->x &&
            vec1->v1[m].y == (vect2 + m)->y &&
            vec1->v1[m].z == (vect2 + m)->z &&
            vec1->v1[m].xi == (vect2 + m)->xi &&
            vec1->v1[m].yi == (vect2 + m)->yi &&
            vec1->v1[m].zi == (vect2 + m)->zi)
            return 1;
        else return 0; }
    else {
        if (vec1->v2[m].x == (vect3 + m)->x &&
            vec1->v2[m].y == (vect3 + m)->y &&
            vec1->v2[m].z == (vect3 + m)->z)
            return 1;
        else return 0; }
}

int comparison_candr_2(vector* vec1, int m) {                //comparison of two complex and real vectors 

    if (vec1->com == 1) {
        if (vec1->v1[m].x == vec1->v1[m+1].x &&
            vec1->v1[m].y == vec1->v1[m+1].y &&
            vec1->v1[m].z == vec1->v1[m+1].z &&
            vec1->v1[m].xi == vec1->v1[m+1].xi &&
            vec1->v1[m].yi == vec1->v1[m+1].yi &&
            vec1->v1[m].zi == vec1->v1[m+1].zi)
            return 1;
        else return 0;
    }
    else {
        if (vec1->v2[m].x == vec1->v2[m+1].x &&
            vec1->v2[m].y == vec1->v2[m+1].y &&
            vec1->v2[m].z == vec1->v2[m+1].z)
            return 1;
        else return 0;
    }
}






Error create_test_complex_and_real() {                          //test for creating a vector by a program 
                                                                //(function in vector.c)

    int quantity_v = 24;
    double* a;                                                  //array of user values
    double arr[] = { 0.5, 1, 2, 1, 0, 3.5 };                    // user values ​​for x,y,z,xi,yi,zi and x,y,z
    a = arr;
    double arr2[] = { 0.5, 1, 2 };
    double* a2 = arr2;
  
    int i = 0;                                                 //count

    vector* vec1;                                              //vector for program
    vectorr* vec_user=NULL;                                    //for user
    vector2* vec_user2=NULL;

    vec1 = (vector*)calloc(quantity_v, sizeof(double));
    vec_user = (vectorr*)calloc(quantity_v/3, sizeof(double));
    vec_user2 = (vector2*)calloc(quantity_v/8, sizeof(double));
    
    vec1[i].com = 1;
    vec1[i].create = &create;
    vec1[i].create(vec1, i, i + 1);

    user(vec_user, a, i);                                       //user vector creation

    Error result = OK;
    if (comparison_candr(vec1, vec_user, vec_user2, i) != 1)  
        result = ERROR;

    vec1[i].com = 0;
    vec1[i].create(vec1, i, i + 1);
    user_real(vec_user2, a2, i);

    if (comparison_candr(vec1, vec_user, vec_user2, i) != 1)
        result = ERROR;

    free(vec1);
    free(vec_user);
    free(vec_user2);
    return result;
}



Error sum_test_complex_and_real() {                             //sum of two vectors


    vector* vec1;
    vector* rez_sum;
    int quantity_v = 24;
    double* a;
    int i = 0;
    double arr[] = { 3,4,6,4,4,9 };  
    double arr2[] = { 3,4,6 }; 
    a = arr;

    vec1 = (vector*)calloc(quantity_v, sizeof(double));
    rez_sum = (vector*)calloc(quantity_v, sizeof(double));
    vec1[i].com = 1;
    rez_sum[i].com = 1;
    user_candr(rez_sum, a, i);

    vec1[i].create = &create;
    vec1[i].create(vec1, i, i + 1);                   //create
    vec1[i].create(vec1, i + 1, i + 2);

    vec1[i].sum = &sum;
    vec1[i].sum(vec1, rez_sum, i, 1);                 //add two vectors(function in vector.c)

    Error result = OK;
    if (comparison_candr_2(rez_sum, i) == 0)         //compare the user vector of the sum with the received
        result = ERROR;

    a = arr2;
    vec1[i].com = 0;
    rez_sum[i].com = 0;
    user_candr(rez_sum, a, i);
    vec1[i].create(vec1, i, i + 1);                   //create
    vec1[i].create(vec1, i + 1, i + 2);

    vec1[i].sum(vec1, rez_sum, i, 1);
   
    if (comparison_candr_2(rez_sum, i) == 0)         //compare the user vector of the sum with the received
        result = ERROR;

    free(vec1);
    free(rez_sum);
    return result;
}


Error scalar_pr_test_complex_and_real() {

    vector* vec1;
    rez* rezult;                                                         //multiplication result
    int quantity_v = 24;
    double* a;
    int i = 0;
    double arr[] = { -10,33 };                                          //scalar product user result
    double arr2[] = { 12.25 };
    a = arr;

    rezult = (rez*)calloc(quantity_v/2, sizeof(double));
    vec1 = (vector*)calloc(quantity_v, sizeof(double));
                                                 
    vec1[i].com = 1;

    vec1[i].create = &create;
    vec1[i].scalar_pr = &scalar_pr;

    vec1[i].create(vec1, i, i + 1);
    vec1[i].create(vec1, i + 1, i + 2);
    vec1[i].scalar_pr(vec1, rezult, i, i);                                  //vector.c

    Error result = OK;
    if (rezult[i].rez_scal != a[0] || rezult[i].rez_scalcomplex != a[1]) // compare directly
        result = ERROR;

    a = arr2;
    vec1[i].com = 0;

    vec1[i].create(vec1, i, i + 1);
    vec1[i].create(vec1, i + 1, i + 2);

    vec1[i].scalar_pr(vec1, rezult, i, 1);

    if (rezult[i + 1].rez_scal != a[0])                                  // compare directly
        result = ERROR;


    free(vec1);
    free(rezult);
    return result;
}



Error vector_pr_test_complex_and_real() {                                 //vector product of complex and real vectors


    vector* vec1;
    int quantity_v = 24;
    double* a;
    vector* rez_pr;                                                      //just the result
    int i = 0;
    double arr[] = { 12,-2,-5,-13,8,2 };                                 //user coordinate values
    double arr2[] = { -2,3,-1 };
    a = arr;

    vec1 = (vector*)calloc(quantity_v, sizeof(double));
    rez_pr = (vector*)calloc(quantity_v, sizeof(double));

    vec1[i].com = 1;
    rez_pr[i].com = 1;

    vec1[i].create = &create;
    vec1[i].vector_pr = &vector_pr;

    vec1[i].create(vec1, i, i + 1);
    vec1[i].create(vec1, i + 1, i + 2);
    vec1[i].vector_pr(vec1, rez_pr, i);                                  //vector.c

    user_candr(rez_pr, a, i + 1);                                        //creating a user product - result vector

    Error result = OK;
    if (comparison_candr_2(rez_pr, i) == 0)
        result = ERROR;

    a = arr2;
    vec1[i].com = 0;
    rez_pr[i].com = 0;

    vec1[i].create(vec1, i, i + 1);
    vec1[i].create(vec1, i + 1, i + 2);
    vec1[i].vector_pr(vec1, rez_pr, i);

    user_candr(rez_pr, a, i + 1);

    if (comparison_candr_2(rez_pr, i) == 0)
        result = ERROR;

    free(vec1);
    free(rez_pr);
    return result;
}



int main()
{
    test_function functions[] = {
        {create_test_complex_and_real, "vector_complex_or_real_create"},
        {sum_test_complex_and_real, "sum_vector_complex_or_real"},
        {scalar_pr_test_complex_and_real, "scalar_pr_vector_complex_or_real"},
        {vector_pr_test_complex_and_real, "vector_pr_vector_complex"},
    };
    const unsigned short n = sizeof(functions) / sizeof(test_function);
    unsigned short errors = 0;

    for (int i = 0; i < n; i++) {
        printf("%d/%d: test %s: ", i + 1, n, functions[i].name);

        Error result = functions[i].function();

        if (result == ERROR) {
            errors += 1;
            printf("ERROR!");
        }
        else
            printf("OK");


        printf("\n");
    }
    printf("\n\ntests: %d, errors: %d\n", n, errors);
    if (errors == 0)
        printf("GOOD\n");

    return 0;
}
