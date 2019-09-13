/*Teste---------------Esperado-----------Resultado
subtraction(M1, M1)     M5=M0             PASSED

subtraction(M2, M1)     M5=M3              ERRO

subtraction(M1, M2)     M5=M3             PASSED

subtraction(M2, M1)     M5=M3              ERRO

subtraction(M2, M1)     M5=M3              ERRO

subtraction(M2, M1)     M5=M3              ERRO*/
#include <mat_type.h> // this include define the type of the matrix
#include <matrix.h>   // the functions under test are defined here
#include <hf-risc.h>
#include <hf-unit.h>


// list of individual tests
//void sqrt1_test();
//void sqrt4_test();
void sub_matrix_teste0();
void sub_matrix_teste1();
void sub_matrix_teste2();
void sub_matrix_teste3();
void sub_matrix_teste4();
void sub_matrix_teste5();

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
	sub_matrix_teste0();
	sub_matrix_teste1();
	sub_matrix_teste2();
	sub_matrix_teste3();
	sub_matrix_teste4();
	sub_matrix_teste5();

}


void sub_matrix_teste0() {
/*Esse teste faz a subtração de 2 matrizes iguais[M1];
A matriz [M0] é uma matriz totalmente zerada, que é o resultado esperado;
A subtraçao de [M1]-[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [MO] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M5,M0;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val0[16] = {val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0)};
M1 = set_values(4, 4, val1);
M0 = set_values(4, 4, val0);

M5 = subtraction(M1, M1);
printf("subtraction(M1,M1)\n");
matrix_compare(&M5,&M0,4);
}

void sub_matrix_teste1() {
/*Esse teste faz a subtração de 2 matrizes [M2]-[M1];
A matriz [M3] é uma matriz ja setada anteriormente com o resultado errado;
A subtraçao de [M2]-[M1] é setada na matriz [M5];
No fim há uma comparaçao entre [M3] e [M5];
O teste é feito para dar errado;*/
struct Matrix M1,M2,M3,M5;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(2),val(4),val(6),val(8),val(10),val(12),val(14),val(16),val(18),val(20),val(22),val(24),val(26),val(28),val(30),val(32)};
typ_var val3[16] = {val(0),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);
M3 = set_values(4, 4, val3);

M5 = subtraction(M2, M1);
printf("subtraction(M2,M1)\n");
matrix_compare(&M5,&M3,4);

}

void sub_matrix_teste2() {
/*Esse teste faz a subtração de 2 matrizes [M2]-[M1];
A matriz [M3] é uma matriz ja setada anteriormente com o resultado errado;
A subtraçao de [M1]-[M2] é setada na matriz [M5];
No fim há uma comparaçao entre [M3] e [M5];
Se o teste for correto é pq as matrizes comparadas sao iguais;*/
struct Matrix M1,M2,M3,M5;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(1),val(4),val(6),val(8),val(10),val(12),val(14),val(16),val(18),val(20),val(22),val(24),val(26),val(28),val(30),val(32)};
typ_var val3[16] = {val(0),val(-2),val(-3),val(-4),val(-5),val(-6),val(-7),val(-8),val(-9),val(-10),val(-11),val(-12),val(-13),val(-14),val(-15),val(-16)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);
M3 = set_values(4, 4, val3);

M5 = subtraction(M1, M2);
printf("subtraction(M1,M2)\n");
matrix_compare(&M5,&M3,4);

}

void sub_matrix_teste3() {
/*Esse teste faz a subtração de 2 matrizes [M2]-[M1];
A matriz [M3] é uma matriz ja setada anteriormente com o resultado errado;
A subtraçao de [M1]-[M2] é setada na matriz [M5];
No fim há uma comparaçao entre [M3] e [M5];
O teste é feito para dar errado;*/
struct Matrix M1,M2,M3,M5;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val2[16] = {val(1),val(4),val(6),val(8),val(10),val(12),val(14),val(16),val(18),val(20),val(22),val(24),val(26),val(28),val(30),val(32)};
typ_var val3[16] = {val(0),val(-2),val(-3),val(-4),val(-5),val(-6),val(7),val(8),val(-99),val(-10),val(-11),val(12),val(-14),val(-14),val(-15),val(-16)};
M1 = set_values(4, 4, val1);
M2 = set_values(4, 4, val2);
M3 = set_values(4, 4, val3);

M5 = subtraction(M1, M2);
printf("subtraction(M2,M1)\n");
matrix_compare(&M5,&M3,4);

}

void sub_matrix_teste4() {
/*teste com matrizes com tamanhos de linhas e colunas diferentes;
teste pra dar erro;*/
struct Matrix M1,M2,M5,M0;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val0[16] = {val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0)};
M1 = set_values(4, 4, val1);
M2 = set_values(8, 2, val1);
M0 = set_values(4, 4, val0);

M5 = subtraction(M1, M2);
printf("subtraction(M1,M1)\n");
matrix_compare(&M5,&M0,4);
}

void sub_matrix_teste5() {
/*teste com matrizes com tamanhos de linhas e colunas diferentes;
teste pra dar erro;*/
struct Matrix M1,M2,M5,M0;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
typ_var val0[16] = {val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0),val(0)};
M1 = set_values(4, 4, val1);
M2 = set_values(2, 8, val1);
M0 = set_values(4, 4, val0);

M5 = subtraction(M1, M2);
printf("subtraction(M1,M1)\n");
matrix_compare(&M5,&M0,4);
}