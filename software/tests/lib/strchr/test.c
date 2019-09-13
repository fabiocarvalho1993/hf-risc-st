/*Teste----------Esperado-----------Resultado
strchr(&v,'a')       4                  4 PASSED

strchr(&v,'M')       0                  0 PASSED

strchr(&v,'is')      29                 9 FAILED

strchr(&v,'A')       195               27 FAILED*/
#include <hf-risc.h>
#include <hf-unit.h>
//#include <string.h>
#include <libc.h>
#define offset 184
//#include <stdio.h>

// function under test 
int8_t *strchr(const int8_t *s, int32_t c);
// list of individual tests
void strchr_test();
void strchr_test2();
void strchr_test3();
void strchr_test4();

// main test
void hfunit_run_tests(){
    strchr_test();
    strchr_test2();
    strchr_test3();
    strchr_test4();   
	
}

/*Esses teste retornam a posição da primeira ocorrencia de um caracter passado, dentro da string;
o calculo de valor é feito a partir do indice do caracter dentro da string mas o offset da memoria;*/
void strchr_test(){
	/*int8_t *strchr(const int8_t *s, int32_t c){
	while (*s != (int8_t)c)
		if (!*s++)
			return 0;

	return (int8_t *)s;
}*/
/*Esse teste procura o caracter 'a' dentro da string;
o resultado esperado pra esse teste é 4;
sendo [i]=4 + 184 [offset memoria];*/
     char  v[] = "My name is Ayush";
    
     int expected = 4;
     char result = strchr(v,'a');
     result=result - offset;
	 printf("\t%d ----- rc: %d\n", expected, result);
     hfunit_comp_vector(&expected, &result, sizeof(int), "strchr(v,'a')");
 }

 void strchr_test2(){
 /*Esse teste procura o caracter 'M' dentro da string;
o resultado esperado pra esse teste é 0;
sendo [i]=0 + 184 [offset memoria];*/
     char  v[] = "My name is Ayush";
    
     int expected = 0;
     char result = strchr(&v,'M');
     result=result - offset;
     printf("\t%d ----- rc: %d\n", expected, result);
     hfunit_comp_vector(expected, result, sizeof(int), "strchr(v,'M'");
 }

 void strchr_test3(){
 	/*Esse teste procura a primeira ocorrencia do ultimo caracter passado 's' dentro da string
o resultado esperado pra esse teste é 9;
sendo [i]=9 + 184 [offset memoria];
teste para dar errado;*/
     char  v[] = "My name is Ayush";
    
     int expected = 29;
     char result = strchr(&v,'is');
     result=result - offset;
     printf("\t%d ----- rc: %d\n", expected, result);
     hfunit_comp_vector(expected, result, sizeof(int), "strchr(v,'is')");
 }

 void strchr_test4(){
 	/*Esse teste procura o caracter 'A' dentro da string;
o resultado esperado pra esse teste é 211;
sendo [i]=11 + 184 [offset memoria]*/
     char  v[] = "My name is Ayush";
    
     int expected = 195;
     char result = strchr(&v,'A');
     result=result - offset;
     printf("\t%d ----- rc: %d\n", expected, result);
     hfunit_comp_vector(expected, result, sizeof(int), "strchr(v,'A')");
 }