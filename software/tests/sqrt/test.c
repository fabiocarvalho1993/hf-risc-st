#include <hf-risc.h>
#include <hf-unit.h>

// function under test 
float sqrt(float arg);

// list of individual tests
void sqrt1_test();
void sqrt4_test();

// main test
void hfunit_run_tests(){
	sqrt1_test();
	sqrt4_test();
}

// place here a nice description for each test
void sqrt1_test(){
	float v = sqrt(1.0);
	float expected = 1.0;
	hfunit_comp_float(v,expected, "sqrt(1.0)");
}

// place here a nice description for each test
void sqrt4_test(){
	float v = sqrt(4.0);
	float expected = 2.0;
	hfunit_comp_float(v,expected, "sqrt(4.0)");
}
