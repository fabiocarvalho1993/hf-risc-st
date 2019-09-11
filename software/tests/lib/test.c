#include <hf-risc.h>
#include <hf-unit.h>
//#include <string.h>
#include <libc.h>

// function under test 
int32_t strcmp(const int8_t *s1, const int8_t *s2);

// list of individual tests
void strcmp1_test();
void strcmp2_test();
//void pow2_test();
//void pow3_test();
//void pow5_test();
//void pow7_test();
//void pow9_test();




// main test
void hfunit_run_tests(){
	strcmp1_test();
    strcmp2_test();
    //pow2_test();
    //pow3_test();
    //pow5_test();
    //pow7_test();
    //pow9_test();
	
}

// place here a nice description for each test
void strcmp1_test(){
    char  v[5] = "abc", v2[5] = "abd";
	//int32_t strcmp(v,v2);
    int expected = -1;
	int result = strcmp(v,v2);
	hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}

void strcmp2_test(){
    char  v[5] = "OI", v2[5] = "OI";
    //int32_t strcmp(v,v2);
    int expected = 0;
    int result = strcmp(v,v2);
    hfunit_comp_vector(&expected, &result, sizeof(int), "strcmp(v,v2)");
}