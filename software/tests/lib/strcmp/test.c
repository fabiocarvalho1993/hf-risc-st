#include <hf-risc.h>
#include <hf-unit.h>
//#include <string.h>
#include <libc.h>
#define NULL
//#include <stdio.h>

// function under test 
int32_t strcmp(const int8_t *s1, const int8_t *s2);

// list of individual tests
void strcmp1_test();
void strcmp2_test();
void strcmp3_test();
void strcmp4_test();

// main test
void hfunit_run_tests(){
	strcmp1_test();
    strcmp2_test();
    strcmp3_test();
    strcmp4_test();
}


void strcmp1_test(){
	/*int32_t strcmp(const int8_t *s1, const int8_t *s2){
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return(0);

	return(*s1 - *--s2);
}*/
    char  v[3] = "abc", v2[3] = "abd";
	//int32_t strcmp(v,v2);
    int expected = -1;
	int result = strcmp(v,v2);
	printf("%f\n",&result);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

void strcmp2_test(){
    char  v[3] = "ab", v2[3] = "ab";
    //int32_t strcmp(v,v2);
    int expected = 0;
    int result = strcmp(v,v2);
    hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

void strcmp3_test(){
    char  v[3] = "abd", v2[3] = "abc";
	//int32_t strcmp(v,v2);
    int expected = 1;
	int result = strcmp(v,v2);
	printf("\t%d ----- rc: %d\n", expected, result);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

void strcmp4_test(){
    char  v[2] = "■"; char v2[2] = "";
	//int32_t strcmp(v,v2);
    int expected = 0;
	int result = strcmp(v,v2);
	printf("\t%d ----- rc: %d\n", expected, result);
	printBits(1,&v);
	printf("\n");
	printBits(1,&v2);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v2,v)");
}