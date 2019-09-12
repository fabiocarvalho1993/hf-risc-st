#include <hf-risc.h>
#include <hf-unit.h>
#include <math.h>
#define PI      3.1415926535897932384626433f
#define PI_2        (PI / 2.0f)
#define PI_4        (PI / 4.0f)
#define PI2     (PI * 2.0f)
#define ONE_PI      (1.0f / PI)
#define TWO_PI      (2.0f / PI)

// function under test 
float pow(float arg1,float arg2);

// list of individual tests
void pow1_test();
void pow2_test();

void pow3_test();
void pow5_test();
void pow7_test();
void pow9_test();



void pow4_test();
void pow6_test();
void pow8_test();
void tan1();
void tan2();
void tan3();
void tan4();


// main test
void hfunit_run_tests(){

	pow1_test();
    pow2_test();
    pow3_test();
    pow5_test();
    pow7_test();
    pow9_test();

 pow4_test();
 pow6_test();
 pow8_test();
 tan1();
 tan2();
 tan3();
 tan4();

	
}

// place here a nice description for each test
void pow1_test(){
	// float v = pow(2.0,127.0);
	// loat expected = 3.4028234664 × 1038;
	// hfunit_comp_float(v,expected, "pow(2.5,2,5)");
}
void pow2_test()
{

    float v=pow(-2.0,3.0);
    float expected=-8.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(-2.0,3.0)");
   
}

void pow3_test()
{
    float v=pow(-2.0,2.0);
    float expected=4.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(-2.0,2.0)");
   
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


void pow5_test()
{
    float v=pow(-2.0,-3.0);
    float expected=-0.125;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(-2.0,-3.0)");
   
}

void pow7_test()
{
    float v=pow(1.0,5.0);
    float expected=1.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(1.0,5.0)");
   
}
void pow9_test()
{
    float v=pow(1.0,2.0);
    float expected=1.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(1.0,2.0)");
   
}

void tan1()
{//float tan(float arg)
    float v=tan(PI);
    float expected=0.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi)");
}

void tan2()
{//float tan(float arg)
    float v=tan(PI_4);
    float expected=1.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi/4)");
}

void tan3()
{//float tan(float arg)
    float v=tan(PI/3);
    float expected=sqrt(3);
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi/3)");
}

void tan4()
{//float tan(float arg)
    float v=tan(PI_2);
    float expected=0.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi/2)");
}