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

int comparison(vectorr* vect1, vectorr* vect2, int m) {                //comparison of two complex vectors

    if ((vect1 + m)->x == (vect2 + m)->x &&
        (vect1 + m)->y == (vect2 + m)->y &&
        (vect1 + m)->z == (vect2 + m)->z &&
        (vect1 + m)->xi == (vect2 + m)->xi &&
        (vect1 + m)->yi == (vect2 + m)->yi &&
        (vect1 + m)->zi == (vect2 + m)->zi)

        return 1;
    else return 0;
}


void user_real(vector2* temporarily, double* a, int m) {              //creating a real vector

    (temporarily + m)->x = a[0];
    (temporarily + m)->y = a[1];
    (temporarily + m)->z = a[2];
}


int comparison_real(vector2* vect1, vector2* vect2, int m) {          //comparison of real vectors
    if ((vect1 + m)->x == (vect2 + m)->x &&
        (vect1 + m)->y == (vect2 + m)->y &&
        (vect1 + m)->z == (vect2 + m)->z)
        return 1;
    else return 0;
}



Error create_test_complex() {                                         //test for creating a complex vector by a program 
                                                                      //(function in vector.c)

    int quantity_v = 6;
    double* a;                                                  //array of user values

    int i = 0;                                                         //count

    vectorr* vec1;                                              //vector for program
    vectorr* vec_user;                                          //дfor user

    vec1 = (vectorr*)calloc(quantity_v, sizeof(double));
    vec_user = (vectorr*)calloc(quantity_v, sizeof(double));
    a = (double*)calloc(quantity_v, sizeof(double));

    a[0] = 0.5; a[1] = 1; a[2] = 2; a[3] = 1; a[4] = 0; a[5] = 3.5; // user values ​​for x,y,z,xi,yi,zi
    vec1[i] = create(vec1, i, i + 1);

    user(vec_user, a, i);                                           //user vector creation

    Error result = OK;
    if (comparison(vec1, vec_user, i) != 1)
        result = ERROR;

    free(vec1);
    free(vec_user);
    free(a);
    return result;
}


Error create_test_real() {                              //test for creating a valid vector by a program (function in vector.c)

    int quantity_v = 3;
    double* a2;
    int i = 0;
    vector2* vec2;
    vector2* vec2_user;

    vec2 = (vector2*)calloc(quantity_v, sizeof(double));
    vec2_user = (vector2*)calloc(quantity_v, sizeof(double));
    a2 = (double*)calloc(quantity_v, sizeof(double));

    a2[0] = 0.5; a2[1] = 1; a2[2] = 2;                 //user values ​​for х,y,z

    vec2[i] = create_real(vec2, i, i + 1);

    user_real(vec2_user, a2, i);                       //user vector creation

    Error result = OK;
    if (comparison_real(vec2, vec2_user, i) != 1)
        result = ERROR;

    free(vec2);
    free(vec2_user);
    free(a2);
    return result;
}

Error sum_test_complex() {                             //sum of two vectors


    vectorr* vec1;
    vectorr* rez_sum;
    vectorr* rez_user;
    int quantity_v = 12;
    double* a;
    int i = 0;

    rez_user = (vectorr*)calloc(quantity_v / 2, sizeof(double));
    vec1 = (vectorr*)calloc(quantity_v, sizeof(double));
    rez_sum = (vectorr*)calloc(quantity_v / 2, sizeof(double));
    a = (double*)calloc(quantity_v / 2, sizeof(double));

    a[0] = 3; a[1] = 4; a[2] = 6; a[3] = 4; a[4] = 4; a[5] = 9;
    user(rez_user, a, i);

    vec1[i] = create(vec1, i, i + 1);                //create
    vec1[i + 1] = create(vec1, i + 1, i + 2);

    sum_c(vec1, rez_sum, i);                            //add two vectors(function in vector.c)

    Error result = OK;
    if (comparison(rez_user, rez_sum, i) == 0)         //compare the user vector of the sum with the received
        result = ERROR;

    free(vec1);
    free(rez_user);
    free(rez_sum);
    return result;
}

Error sum_test_real() {


    vector2* vec1;
    vector2* rez_sum;                             //vector storing the result of addition
    vector2* rez_user;
    double* a;
    int quantity_v = 6;
    int i = 0;

    rez_user = (vector2*)calloc(quantity_v / 2, sizeof(double));
    vec1 = (vector2*)calloc(quantity_v, sizeof(double));
    rez_sum = (vector2*)calloc(quantity_v / 2, sizeof(double));
    a = (double*)calloc(quantity_v / 2, sizeof(double));

    a[0] = 3; a[1] = 4; a[2] = 6;
    user_real(rez_user, a, i);

    vec1[i] = create_real(vec1, i, i + 1);
    vec1[i + 1] = create_real(vec1, i + 1, i + 2);
    rez_sum[i] = sum_real(vec1, rez_sum, i);

    Error result = OK;
    if (comparison_real(rez_user, rez_sum, i) == 0)
        result = ERROR;

    free(vec1);
    free(rez_user);
    free(rez_sum);
    return result;

}


Error scalar_pr_test_complex() {

    vectorr* vec1;
    rez* rezult;                                                    //multiplication result
    int quantity_v = 12;
    double* a;
    int i = 0;

    rezult = (rez*)calloc(quantity_v / 2, sizeof(double));
    vec1 = (vectorr*)calloc(quantity_v, sizeof(double));
    a = (double*)calloc(quantity_v / 6, sizeof(double));

    a[0] = -10; a[1] = 33;                                               //scalar product user result

    vec1[i] = create(vec1, i, i + 1);
    vec1[i + 1] = create(vec1, i + 1, i + 2);
    rezult[i] = scalar_pr_c(vec1, rezult, i);                              //vector.c

    Error result = OK;
    if (rezult[i].rez_scal != a[0] || rezult[i].rez_scalcomplex != a[1]) // compare directly
        result = ERROR;

    free(vec1);
    free(a);
    free(rezult);
    return result;
}

Error scalar_pr_test_real() {

    vector2* vec1;
    double* rezult;
    int quantity_v = 6;
    double* a;
    int i = 0;

    rezult = (double*)calloc(quantity_v / 2, sizeof(double));
    vec1 = (vector2*)calloc(quantity_v, sizeof(double));
    a = (double*)calloc(quantity_v / 3, sizeof(double));

    a[0] = 12.25;

    vec1[i] = create_real(vec1, i, i + 1);
    vec1[i + 1] = create_real(vec1, i + 1, i + 2);
    rezult[i] = scalar_pr_real(vec1, rezult, i);

    Error result = OK;
    if (rezult[i] != a[0])
        result = ERROR;

    free(vec1);
    free(rezult);
    free(a);
    return result;
}

Error vector_pr_test_complex() {                                    //vector product of complex vectors


    vectorr* vec1;
    vectorr* rez_user;                                         //user result
    int quantity_v = 12;
    double* a;
    vectorr* rez_pr;                                          //just the result
    int i = 0;

    vec1 = (vectorr*)calloc(quantity_v, sizeof(double));
    rez_user = (vectorr*)calloc(quantity_v / 2, sizeof(double));
    rez_pr = (vectorr*)calloc(quantity_v, sizeof(double));
    a = (double*)calloc(6, sizeof(double));

    a[0] = 12; a[1] = -2; a[2] = -5; a[3] = -13; a[4] = 8; a[5] = 2; //user coordinate values

    vec1[i] = create(vec1, i, i + 1);
    vec1[i + 1] = create(vec1, i + 1, i + 2);
    rez_pr[i] = vector_pr_c(vec1, rez_pr, i);                      //vector.c

    user(rez_user, a, i);                                          //creating a user product - result vector

    Error result = OK;
    if (comparison(rez_user, rez_pr, i) == 0)
        result = ERROR;

    free(vec1);
    free(rez_pr);
    free(rez_user);
    free(a);
    return result;
}

Error vector_pr_test_real() {


    vector2* vec1;
    vector2* rez_user;
    int quantity_v = 6;
    double* a;
    vector2* rez_pr;
    int i = 0;

    vec1 = (vector2*)calloc(quantity_v, sizeof(double));
    rez_user = (vector2*)calloc(quantity_v / 2, sizeof(double));
    rez_pr = (vector2*)calloc(quantity_v, sizeof(double));
    a = (double*)calloc(3, sizeof(double));

    a[0] = -2; a[1] = 3; a[2] = -1;

    vec1[i] = create_real(vec1, i, i + 1);
    vec1[i + 1] = create_real(vec1, i + 1, i + 2);
    rez_pr[i] = vector_pr_real(vec1, rez_pr, i);

    user_real(rez_user, a, i);

    Error result = OK;
    if (comparison_real(rez_user, rez_pr, i) == 0)
        result = ERROR;

    free(vec1);
    free(rez_pr);
    free(rez_user);
    free(a);
    return result;
}



int main()
{
    test_function functions[] = {
        {create_test_complex, "vector_complex_create"},
        {create_test_real, "vector_real_create"},
        {sum_test_complex, "sum_vector_complex"},
        {sum_test_real, "sum_vector_real"},
        {scalar_pr_test_complex, "scalar_pr_vector_complex"},
        {scalar_pr_test_real, "scalar_pr_vector_real"},
        {vector_pr_test_complex, "vector_pr_vector_complex"},
        {vector_pr_test_real, "vector_pr_vector_real"}
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
