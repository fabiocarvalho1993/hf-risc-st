#include <hf-risc.h>
#include <hf-unit.h>
//#include <string.h>
#include <libc.h>

// function under test 
int32_t strcmp(const int8_t *s1, const int8_t *s2);

// list of individual tests
void strcmp1_test();
//void pow2_test();
//void pow3_test();
//void pow5_test();
//void pow7_test();
//void pow9_test();




// main test
void hfunit_run_tests(){
	strcmp1_test();
    //pow2_test();
    //pow3_test();
    //pow5_test();
    //pow7_test();
    //pow9_test();
	
}

// place here a nice description for each test
void strcmp1_test(){
    char  v[5] = "oi", v2[5] = "hello";
	//int32_t strcmp(v,v2);
	int expected = strcmp(v,v2);
	hfunit_comp_vector(v, v2,expected, "strcmp(v,v2)");
}
