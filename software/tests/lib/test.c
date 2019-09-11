#include <hf-risc.h>
#include <hf-unit.h>
//#include <string.h>
#include <libc.h>

// function under test 
int32_t strcmp(const int8_t *s1, const int8_t *s2);
int8_t *strchr(const int8_t *s, int32_t c);
// list of individual tests
void strcmp1_test();
void strcmp2_test();
//void strchr_test();



// main test
void hfunit_run_tests(){
	strcmp1_test();
    strcmp2_test();
   // strchr_test();   
	
}


void strcmp1_test(){
    char  v[3] = "abc", v2[3] = "abd";
	//int32_t strcmp(v,v2);
    int expected = -1;
	int result = strcmp(v,v2);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

void strcmp2_test(){
    char  v[2] = "OI", v2[2] = "OI";
    //int32_t strcmp(v,v2);
    int expected = 0;
    int result = strcmp(v,v2);
    hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

// void strchr_test()
// {
//     char  v[3] = "abc";
    
//     int expected = 'b';
//     int result = strchr(v,'b');
//     hfunit_comp_vector(&expected, &result, sizeof(int), "strchr(v,'b')");
// }