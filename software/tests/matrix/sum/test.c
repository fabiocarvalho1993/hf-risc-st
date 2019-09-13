/*Teste-------Esperado-----------Resultado
sum(M1, M1)     M5=M2             PASSED

sum(M2, M1)     M5=M2             PASSED

sum(M1, M2)     M5=M2              ERRO

sum(M2, M1)     M5=M0             PASSED

sum(M1, M2)     M5=M2              ERRO

sum(M1, M2)     M5=M2              ERRO*/
#include <mat_type.h> // this include define the type of the matrix
#include <matrix.h>   // the functions under test are defined here
#include <hf-risc.h>
#include <hf-unit.h>


// list of individual tests
//void sqrt1_test();
//void sqrt4_test();
void sum_matrix_teste1();
void sum_matrix_teste2();
void sum_matrix_teste3();
void sum_matrix_teste0();
void sum_matrix_teste4();
void sum_matrix_teste5();

/*Teste de comparação entre a matriz resultante e a matrix esperada*/
void matrix_compare(struct Matrix  *m1/*matix resultado*/, struct Matrix  *m2/*matrix experada*/, int tam){
	int x,y,flag=0;
	for (x=0; x<tam; x++){
		for(y=0; y<tam;y++){
			if(flag==0){
				if(m1->str[x][y] != m2->str[x][y]){
					hfunit_comp_float(m1->str[x][y],m2->str[x][y],"ERRO no Teste de igualdade\n");
					printf("matrix resultado\n");
					print_matrix(*m1);
					printf("\n");
					printf("matrix esperada\n");
					print_matrix(*m2);
					flag=1;
					break;
				}
			}
		}
	}
	if(flag == 0){
		hfunit_comp_float(m1->str[x][y],m2->str[x][y],"Teste de igualdade Correto\n");
		printf("matrix resultado\n");
		print_matrix(*m1);
		printf("\n");
		printf("matrix esperada\n");
		print_matrix(*m2);
	}

}
// main test
void hfunit_run_tests(){
	sum_matrix_teste1();
	sum_matrix_teste2();
	sum_matrix_teste3();
	sum_matrix_teste0();
	sum_matrix_teste4();
	sum_matrix_teste5();

}


void sum_matrix_teste1() {
/*Esse teste faz a soma de 2 matrizes iguais[M1];
A matriz [M2] é uma matriz ja setada anteriormente com o resultado esperado;
A soma de [M1]+[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [M2] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M2,M5;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(2),val(4),val(6),val(8),val(10),val(12),val(14),val(16),val(18),val(20),val(22),val(24),val(26),val(28),val(30),val(32)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);

//printf("Matrix 1 is:\n");
//print_matrix(M1);
//printf("Matrix 2 is:\n");
//print_matrix(M2);
//printf("Sum of Matrix 1 and 2 is:\n");
M5 = sum(M1, M1);
//print_matrix(M5);
printf("sum(M1,M1)\n");
matrix_compare(&M5,&M2,4);

}

void sum_matrix_teste2() {
/*Esse teste faz a soma de 2 matrizes iguais[M1], com valores negativos;
A matriz [M2] é uma matriz ja setada anteriormente com o resultado esperado;
A soma de [M1]+[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [M2] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M2,M5;

typ_var val1[16] = {val(-1),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
typ_var val2[16] = {val(-2),val(-4),val(-6),val(-8),val(-10),val(-12),val(-14),val(-16),val(-18),val(-20),val(-22),val(-24),val(-26),val(-28),val(-30),val(-32)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);

M5 = sum(M1, M1);
printf("sum(M1,M1)\n");
matrix_compare(&M5,&M2,4);

}

void sum_matrix_teste3() {
/*Esse teste faz a soma de 2 matrizes iguais[M1], com valores negativos;
A matriz [M2] é uma matriz ja setada anteriormente com o resultado esperado;
A soma de [M1]+[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [M2] e [M5];
Teste feito pra dar errado;*/
struct Matrix M1,M2,M5;

typ_var val1[16] = {val(-1),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
typ_var val2[16] = {val(-2),val(4),val(-6),val(-8),val(10),val(-12),val(-14),val(-16),val(18),val(-20),val(-23),val(-24),val(-29),val(-28),val(-30),val(-32)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);

M5 = sum(M1, M1);
printf("sum(M1,M1)\n");
matrix_compare(&M5,&M2,4);

}

void sum_matrix_teste0() {
/*Esse teste faz a soma de 2 matrizes [M1]+[M2], sendo os valores de [M2]=-[M1];
A matriz [M0] é uma matriz zerada ja setada anteriormente;
A soma de [M1]+[M2] é setada na matriz [M5];
No fim há uma comparaçao entre [M0] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M2,M5,M0;

typ_var val1[16] = {val(-1),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
typ_var val2[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val0[16] = {val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0)};
M1 = set_values(4, 4, val1);
M0 = set_values(4, 4, val0);
M2 = set_values(4, 4, val2);

M5 = sum(M1, M2);
printf("sum(M1,M2)\n");
matrix_compare(&M5,&M0,4);

}

void sum_matrix_teste4() {
/*teste com matrizes com tamanhos de linhas e colunas diferentes;
teste pra dar erro;*/
struct Matrix M1,M2,M5,M0;

typ_var val1[16] = {val(-1),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
typ_var val2[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val0[16] = {val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0)};
M1 = set_values(4, 4, val1);
M0 = set_values(8, 2, val0);
M2 = set_values(4, 4, val2);

M5 = sum(M1, M2);
printf("sum(M1,M2)\n");
matrix_compare(&M5,&M0,4);

}

void sum_matrix_teste5() {
/*teste com matrizes com tamanhos de linhas e colunas diferentes;
teste pra dar erro;*/
struct Matrix M1,M2,M5,M0;

typ_var val1[16] = {val(-1),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
typ_var val2[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val0[16] = {val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0)};
M1 = set_values(8, 2, val1);
M0 = set_values(4, 4, val0);
M2 = set_values(4, 4, val2);

M5 = sum(M1, M2);
printf("sum(M1,M2)\n");
matrix_compare(&M5,&M0,4);

}