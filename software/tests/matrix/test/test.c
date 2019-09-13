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
void sum_matrix_teste3();
void sum_matrix_teste4();

// main test
void hfunit_run_tests(){
	sub_matrix_teste1();
	sum_matrix_teste2();
	sub_matrix_teste3();
	sub_matrix_teste4();
}


void sub_matrix_teste1() {
/*Esse teste faz a subtração de 2 matrizes iguais[M1];
A matriz [M0] é uma matriz totalmente zerada, que é o resultado esperado;
A subtraçao de [M1]-[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [MO] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M5,M0,MI,mulI;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val0[16] = {val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0)};
M1 = set_values(4, 4, val1);
M0 = set_values(4, 4, val0);

//printf("Matrix 1 is:\n");
//print_matrix(M1);
//printf("Matrix 2 is:\n");
//print_matrix(M1);
//printf("Subtraction of Matrix 1 and 2 is:\n");
M5 = subtraction(M1, M1);
MI = Invert(M5);
mulI= multiplication(M5,MI);
//print_matrix(M5);
//print_matrix(MI);
//print_matrix(mulI);
//print_matrix(M5);
//print_matrix(M0);
hfunit_comp_vector(&M0,&M5,sizeof(int),"subtraction(M1,M1)");

}

void sum_matrix_teste2() {
/*Esse teste faz a subtração de 2 matrizes iguais[M1];
A matriz [M2] é uma matriz ja setada anteriormente com o resultado esperado;
A soma de [M1]+[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [M2] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M2,M5,MI,mulI,MT;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(2),val(4),val(6),val(8),val(10),val(12),val(14),val(16),val(18),val(20),val(22),val(24),val(26),val(28),val(30),val(32)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);

//printf("Matrix 1 is:\n");
//print_matrix(M1);
//printf("Matrix 2 is:\n");
//print_matrix(M2);
//printf("Sum of Matrix 1 and 2 is:\n");
M5 = sum(M1, M2);
MI = Invert(M5);
MT=transposed(MI);
mulI= multiplication(M5,MT);
//print_matrix(M5);
//print_matrix(MI);
//print_matrix(MT);
//print_matrix(mulI);
hfunit_comp_vector(&M2,&M5,sizeof(int),"sum(M1,M1)");

}

void sub_matrix_teste3() {
/*Esse teste faz a subtração de 2 matrizes iguais[M1];
A matriz [M2] é uma matriz ja setada anteriormente com o resultado esperado;
A soma de [M1]+[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [M2] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M2,M3,M5,MI,MT,mulT,mulI;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(2),val(4),val(6),val(8),val(10),val(12),val(14),val(16),val(18),val(20),val(22),val(24),val(26),val(28),val(30),val(32)};
typ_var val3[16] = {val(0),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);
M3 = set_values(4, 4, val3);

//printf("Matrix 1 is:\n");
//print_matrix(M1);
//printf("Matrix 2 is:\n");
//print_matrix(M2);
//printf("Sum of Matrix 1 and 2 is:\n");
//M5 = subtraction(M2, M1);
MI = Invert(M2);
//MT = transposed(M5);
mulI= multiplication(M2,MI);
//mulT= blkdiag2(M5,MT);
print_matrix(M2);
print_matrix(MI);
print_matrix(mulI);
//print_matrix(MT);
//print_matrix(mulT);
hfunit_comp_vector(&mulI,&M2,sizeof(typ_var),"subtraction(M1,M1)");

}

void sub_matrix_teste4() {
/*Esse teste faz a subtração de 2 matrizes iguais[M1];
A matriz [M2] é uma matriz ja setada anteriormente com o resultado esperado;
A soma de [M1]+[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [M2] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M2,M3,M5;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(1),val(4),val(6),val(8),val(10),val(12),val(14),val(16),val(18),val(20),val(22),val(24),val(26),val(28),val(30),val(32)};
typ_var val3[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);
M3 = set_values(4, 4, val3);

//printf("Matrix 1 is:\n");
//print_matrix(M1);
//printf("Matrix 2 is:\n");
//print_matrix(M2);
//printf("Sum of Matrix 1 and 2 is:\n");
M5 = subtraction(M1, M2);
//print_matrix(M5);
//print_matrix(M3);
hfunit_comp_vector(&M3,&M5,sizeof(int),"subtraction(M2,M1)");

}