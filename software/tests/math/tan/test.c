/*Teste--------------Esperado--------------Resultado
tan(0.0)             0.000000000          0.000000000 

tan(PI_6)            0.577350318          0.577350258

tan(PI_4)            1.000000000          1.000000000

tan(PI_3)            1.732050895          1.732051253

tan(PI_2)            0.000000000          0.000000000

tan(PI)              0.000000000          0.000000000

tan(PI3_2)           0.000000000         -1.000000000

tan(PI2)             0.000000000          0.000000000*/
#include <hf-risc.h>
#include <hf-unit.h>
#include <math.h>
#define PI      3.1415926535897932384626433f
#define PI_2        (PI / 2.0f)
#define PI_3        (PI / 3.0f)
#define PI_4        (PI / 4.0f)
#define PI_6        (PI / 6.0f)
#define PI3_2       ((PI*3) / 4.0f)
#define PI2         (PI * 2.0f)
#define ONE_PI      (1.0f / PI)
#define TWO_PI      (2.0f / PI)

// function under test 
float pow(float arg1,float arg2);

// list of individual tests
void tan0();
void tan1();
void tan2();
void tan3();
void tan4();
void tan5();
void tan6();
void tan7();


// main test
void hfunit_run_tests(){

 tan0();
 tan1();
 tan2();
 tan3();
 tan4();
 tan5();
 tan6();
 tan7();

}

// place here a nice description for each test
void tan0()
{//float tan(float arg)
    float v=tan(0.0);
    float expected=0.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(0.0)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void tan1()
{//float tan(float arg)
    float v=tan(PI_6);
    float expected=(sqrt(3)) / 3.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi/6)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void tan2()
{//float tan(float arg)
    float v=tan(PI_4);
    float expected=1.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi/4)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void tan3()
{//float tan(float arg)
    float v=tan(PI_3);
    float expected=sqrt(3);
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi/3)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void tan4()
{//float tan(float arg)
    float v=tan(PI_2);
    float expected=0.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi/2)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void tan5()
{//float tan(float arg)
    float v=tan(PI);
    float expected=0.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(pi)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void tan6()
{//float tan(float arg)
    float v=tan(PI3_2);
    float expected=0.0;
    printf("%lf\n",&v);
    hfunit_comp_float(v,expected,"tan(3*pi/2)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}

void tan7()
{//float tan(float arg)
    float v=tan(PI2);
    float expected=0.0;
    hfunit_comp_float(v,expected,"tan(2*pi)");
    print_float(expected);
    printf("\n");
    print_float(v);
    printf("\n");
}