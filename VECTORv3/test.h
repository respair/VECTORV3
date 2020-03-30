#ifndef TESTS_H
#define TESTS_H

typedef enum {
	OK,
	ERROR
} Error;

typedef struct {
	Error(*function)();
	const char* name;
} test_function;

#endif 
