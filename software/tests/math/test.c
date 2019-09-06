#include <hf-risc.h>
#include <hf-unit.h>
#include <math.h>


// function under test 
float pow(float arg1,float arg2);

// list of individual tests
void pow1_test();
void pow2_test();
void pow4_test();
void pow6_test();
void pow8_test();


// main test
void hfunit_run_tests(){
 pow1_test();
 pow2_test();
 pow4_test();
 pow6_test();
 pow8_test();
	
}

// place here a nice description for each test
void pow1_test(){
	float v = pow(2.0,127.0);
	//float expected = 3.4028234664 × 1038;
	hfunit_comp_float(v,expected, "pow(2.5,2,5)");
}
void pow2_test()
{
    float v=pow(2.0,-2.0);
    float expected=0.25;
    printf("\n");
    hfunit_comp_float(v,expected,"pow(2.0,-2.0)");
}
void pow4_test()
{
    float v=pow(2.0,0.0);
    float expected=1;
    printf("\n");
    hfunit_comp_float(v,expected,"pow(2.0,0.0)");
}
void pow6_test()
{
    float v=pow(0.0,2.0);
    float expected=0.0;
    printf("\n");
    hfunit_comp_float(v,expected,"pow(0.0,2.0)");
}

void pow8_test()
{
    float v=pow(0.0,0.0);
    float expected=1.0;
    printf("\n");
    hfunit_comp_float(v,expected,"pow(0.0,0.0)");
}


