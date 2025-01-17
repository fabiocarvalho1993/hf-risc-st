/*Teste--------------Esperado--------------Resultado
pow(2.0,127.0)

pow(-2.0,3.0)       -8.000000000         -7.999999523 

pow(-2.0,2.0)        4.000000000          3.999999761

pow(-2.0,-2.0)       1.000000000          1.000000000

pow(-2.0,-3.0)      -0.125000000          0.000000000

pow(0.0,2.0)         0.000000000          0.000000000

pow(1.0,5.0)         1.000000000          1.000000000

pow(0.0,0.0)         1.000000000          0.000000000

pow(2.0,0.0)         1.000000000          1.000000000*/
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
void pow4_test();
void pow5_test();
void pow6_test();
void pow7_test();
void pow8_test();
void pow9_test();


// main test
void hfunit_run_tests(){

    pow1_test();
    pow2_test();
    pow3_test();
    pow4_test();
    pow5_test();
    pow6_test();
    pow7_test();
    pow8_test();
    pow9_test(); 
}

// place here a nice description for each test
void pow1_test(){
    float v = pow(2.0,127.0);
    float expected = 256.00000001;
    hfunit_comp_float(v,expected, "pow(2.5,2,5)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void pow2_test()
{

    float v=pow(-2.0,3.0);
    float expected=-8.0;
    hfunit_comp_float(v,expected,"pow(-2.0,3.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void pow3_test()
{
    float v=pow(-2.0,2.0);
    float expected=4.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(-2.0,2.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void pow4_test()
{
    float v=pow(-2.0,-2.0);
    float expected=0.25;
    printf("\n");
    hfunit_comp_float(v,expected,"pow(-2.0,-2.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void pow5_test()
{
    float v=pow(-2.0,-3.0);
    float expected=-0.125;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(-2.0,-3.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
   
}

void pow6_test()
{
    float v=pow(0.0,2.0);
    float expected=0.0;
    printf("\n");
    hfunit_comp_float(v,expected,"pow(0.0,2.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void pow7_test()
{
    float v=pow(1.0,5.0);
    float expected=1.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(1.0,5.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void pow8_test()
{
    float v=pow(0.0,0.0);
    float expected=1.0;
    printf("\n");
    hfunit_comp_float(v,expected,"pow(0.0,0.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void pow9_test()
{
    float v=pow(2.0,0.0);
    float expected=1.0;
    printf("\n%lf\n",&v);
    hfunit_comp_float(v,expected,"pow(2.0,0.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}