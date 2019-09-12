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
void strchr_test();



// main test
void hfunit_run_tests(){
	strcmp1_test();
    strcmp2_test();
    strcmp3_test();
    strchr_test();   
	
}


void strcmp1_test(){
	/*int32_t strncmp(int8_t *s1, int8_t *s2, int32_t n){
	while (--n >= 0 && *s1 == *s2++)
		if (*s1++ == '\0')
			return(0);

	return(n<0 ? 0 : *s1 - *--s2);
}*/
    char  v[3] = "abc", v2[3] = "abd";
	//int32_t strcmp(v,v2);
    int expected = -1;
	int result = strcmp(v,v2);
	printf("%f\n",&result);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

void strcmp2_test(){
    char  v[2] = "OI", v2[2] = "OI";
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
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

void strchr_test(){
	/*int8_t *strchr(const int8_t *s, int32_t c){
	while (*s != (int8_t)c)
		if (!*s++)
			return 0;

	return (int8_t *)s;
}*/
     char  v[] = "My name is Ayush";
    
     int expected = 5;
     char result = strchr(v,'a');
     //sprintf("%d\n", &expected);
     //sprintf("%c\n", &result);
     hfunit_comp_vector(&expected, &result, sizeof(int8_t), "strchr(v,'a')");
 }