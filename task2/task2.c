#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
int exitOperation (int a, int b);


typedef int (*Operation) (int a, int b);
int myOperation (int a, int b);


int main (int argc, char *argv[]){
	int a = 6;
	int b = 3;
	fprintf(stderr, "Operand ‘a’ :%d |Operand ‘b’ :%d\n", a, b);
	fprintf(stderr, "Specify the operand to perform (0 : add | 1 : subtract | 2 : multiply | 3 : divide | 4 : exit)");


	if (argc < 2) {
			fprintf(stderr, "Usage: ./func-ptr <input-integer>\n");
			fflush(stdout);
			return 1;
	}

	Operation operations[5];
	operations[0] = add;
	operations[1] = subtract;
	operations[2] = multiply;
	operations[3] = divide;
	operations[4] = exitOperation;

	int i = atoi(argv[1]);

	if (i < 0 || i >= 4) {
        fprintf(stderr, "Invalid operation index.\n");
        return 1;
    }

	int result = operations[i](a, b);
	printf("x = %d\n", result);
	
	return result;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { 
	fprintf(stderr, "0\nAdding ‘a’ and ‘b’\n");
	return a + b; 
}
int subtract (int a, int b){
	fprintf(stderr, "1\nSubtracting ‘b’ from ‘a’\n");
	return a - b;
}
int multiply (int a, int b){
	fprintf(stderr, "2\nMultiplying ‘a’ and ‘b’\n");
	return a * b;
}
int divide (int a, int b){
	fprintf(stderr, "3\nDividing ‘a’ by ‘b’\n");
	return a / b;
}
int exitOperation (int a, int b){
	exit(0);
}