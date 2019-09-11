/*
This matrix lib can work with 3 different types: fixed, float, and double.
just change the variable MATRIX_TYPE in the makefile
*/

#include <mat_type.h> // this include define the type of the matrix
#include <matrix.h>   // the functions under test are defined here
#include <hf-risc.h>
#include <hf-unit.h>


// list of individual tests
//void sqrt1_test();
//void sqrt4_test();
void sub_matrix_teste1();
void sum_matrix_teste2();

// main test
void hfunit_run_tests(){
	sub_matrix_teste1();
	sum_matrix_teste2();
}


void sub_matrix_teste1() {

struct Matrix M1,M5;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
//typ_var val2[16] = {val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16),val(17)};
M1 = set_values(4, 4, val1);
//M2 = set_values(4, 4, val2);

printf("Matrix 1 is:\n");
print_matrix(M1);
printf("Matrix 2 is:\n");
print_matrix(M1);
printf("Subtraction of Matrix 1 and 2 is:\n");
M5 = subtraction(M1, M1);
print_matrix(M5);
hfunit_comp_vector(M5,M1,16,"subtraction(M1,M1)");

}

void sum_matrix_teste2() {

struct Matrix M1,M2,M5;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16),val(17)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);

printf("Matrix 1 is:\n");
print_matrix(M1);
printf("Matrix 2 is:\n");
print_matrix(M2);
printf("Sum of Matrix 1 and 2 is:\n");
M5 = sum(M1, M1);
print_matrix(M5);

}
