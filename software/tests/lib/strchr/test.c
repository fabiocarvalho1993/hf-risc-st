#include <hf-risc.h>
#include <hf-unit.h>
//#include <string.h>
#include <libc.h>
//#include <stdio.h>

// function under test 
int8_t *strchr(const int8_t *s, int32_t c);
// list of individual tests
void strchr_test();

// main test
void hfunit_run_tests(){
    strchr_test();   
	
}


void strchr_test(){
	/*int8_t *strchr(const int8_t *s, int32_t c){
	while (*s != (int8_t)c)
		if (!*s++)
			return 0;

	return (int8_t *)s;
}*/
     char  v[] = "My name is Ayush";
    
     int expected = 204;
     char result = strchr(v,'a');
	 printf("\t%d ----- rc: %d\n", expected, result);
     hfunit_comp_vector(&expected, &result, sizeof(int8_t), "strchr(v,'a')");
 }