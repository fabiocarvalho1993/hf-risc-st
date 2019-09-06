#include <hf-risc.h>
#include <hf-unit.h>
#include <math.h>


// function under test 
float pow(float arg1,float arg2);

// list of individual tests
void pow1_test();
void pow2_test();


// main test
void hfunit_run_tests(){
	pow1_test();
    pow2_test();
	
}

// place here a nice description for each test
void pow1_test(){
	float v = pow(2.5,2.5);
	float expected = 9.88211;
	hfunit_comp_float(v,expected, "pow(2.5,2,5)");
}
void pow2_test()
{
    float v=pow(-2.0,1.0);
    float expected=-1.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(-2.0,1.0)");
   
}

