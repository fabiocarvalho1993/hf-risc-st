#include <hf-risc.h>
#include <hf-unit.h>
//#include <string.h>
#include <libc.h>
//#include <stdio.h>

// function under test 
int32_t strcmp(const int8_t *s1, const int8_t *s2);
int8_t *strchr(const int8_t *s, int32_t c);
// list of individual tests
void strcmp1_test();
void strcmp2_test();
void strcmp3_test();
//-------------------------------------//
void strchr_test();
void strchr_test2();
void strchr_test3();



// main test
void hfunit_run_tests(){
	strcmp1_test();
    strcmp2_test();
    strcmp3_test();
    strchr_test();   
	strchr_test();
	strchr_test2();
    strchr_test3();
	
}


void strcmp1_test(){
    char  v[] = "abc", v2[] = "abd";
    int expected = -1;
    int result=strcmp(v,v2);
	printf("%d\n",result);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(abc,abd)");
}

void strcmp2_test(){
    char  v[] = "o", v2[] = "o";
    int expected = 0;
    int result = strcmp(v,v2);
    hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(o,o)");
}

void strcmp3_test(){
    char  v[] = "abd", v2[] = "abc";
    int expected = 1;
	int result = strcmp(v,v2);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(abd,abc)");
}

void strchr_test(){
     char  v[] = "My name is Ayush";
    
     int expected = 3;
     char result = strchr(v,'a');
     hfunit_comp_vector(expected, result, sizeof(int8_t), "strchr(v,'a')");
 }
 void strchr_test2(){
     char  v[] = "My name is Ayush";
    
     int expected = 2;
     char result = strchr(v,'m');
     hfunit_comp_vector(expected, result, sizeof(int8_t), "strchr(v,'M')");
 }
 void strchr_test3(){
     char  v[] = "My name is Ayush";
    
     int expected = 3;
     char result = strchr(v,'is');
     hfunit_comp_vector(expected, result, sizeof(int8_t), "strchr(v,'n')");
 }