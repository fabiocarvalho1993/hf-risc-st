/*Teste--------------Esperado-----------Resultado
fix_asin(v[1.0])     1.570800           1.570800  PASSED

fix_asin(v[-1.0])   -1.570800          -1.570800  PASSED 

fix_asin(v[0.0])     0.000000           0.000000  PASSED

fix_rad(v[60])       1.047195           1.047195  PASSED

fix_rad(v[90])       1.570785           1.570785  PASSED

fix_rad(v[80])       1.396255           1.396255  PASSED

fix_rad(v[360])      6.283172           6.283172  PASSED*/
#include <hf-risc.h>
#include <hf-unit.h>
#include <fixed.h> 

extern int failed_tests;
extern int executed_tests;



// function under test 
fixed_t fix_asin(fixed_t expected);
fixed_t fix_rad(fixed_t deg);
// list of individual tests
void fix_asin_test();
void fix_asin_test_2();
void fix_asin_test_3();

void fix_rad_test();
void fix_rad_test_2();
void fix_rad_test_3();
void fix_rad_test_4();
// main test
void hfunit_run_tests(){
fix_asin_test();
fix_asin_test_2();
fix_asin_test_3();

fix_rad_test();
fix_rad_test_2();
fix_rad_test_3();
fix_rad_test_4();

}

void fix_asin_test()
{
    fixed_t expected=fix_val(1.57079633);
    fixed_t v=fix_val(1.0);
    fixed_t receive=fix_asin(v);
    printf("receive     " );
    fix_print(receive);
    printf("\nexpected    ");
    fix_print(expected);
    printf("\n");
    hfunit_comp_vector(&receive,&expected,sizeof(fixed_t),"fix_asin(1.0)");
    printf("\n");
}

void fix_asin_test_2()
{
    fixed_t expected=fix_val(-1.57079633);
    fixed_t v=fix_val(-1.0);
    fixed_t receive=fix_asin(v);
    printf("receive     " );
    fix_print(receive);
    printf("\nexpected    ");
    fix_print(expected);
    printf("\n");
    hfunit_comp_vector(&receive,&expected,sizeof(fixed_t),"fix_asin(-1.0)");
    printf("\n");
}

void fix_asin_test_3()
{
    fixed_t expected=fix_val(0.0);
    fixed_t v=fix_val(0.0);
    fixed_t receive=fix_asin(v);
    printf("receive     " );
    fix_print(receive);
    printf("\nexpected    ");
    fix_print(expected);
    printf("\n");
    hfunit_comp_vector(&receive,&expected,sizeof(fixed_t),"fix_asin(0.0)");
    printf("\n");
}

//--------------------------------------------------------------------------------//

void fix_rad_test()
{
    fixed_t expected=fix_val(1.0472);
    fixed_t v=fix_val(60);
    fixed_t receive=fix_rad(v);
    printf("receive     " );
    fix_print(receive);
    printf("\nexpected    ");
    fix_print(expected);
    printf("\n");
     hfunit_comp_vector(&receive,&expected,sizeof(fixed_t),"fix_rad(60)");
     printf("\n");
}

void fix_rad_test_2()
{
    fixed_t expected=fix_val(1.570785);
    fixed_t v=fix_val(90);
    fixed_t receive=fix_rad(v);
    printf("receive     " );
    fix_print(receive);
    printf("\nexpected    ");
    fix_print(expected);
    printf("\n");
    hfunit_comp_vector(&receive,&expected,sizeof(fixed_t),"fix_rad(90)");
    printf("\n");
}

void fix_rad_test_3()
{
    fixed_t expected=fix_val(1.39626);
    fixed_t v=fix_val(80);
    fixed_t receive=fix_rad(v);
    printf("receive     " );
    fix_print(receive);
    printf("\nexpected    ");
    fix_print(expected);
    printf("\n");
    hfunit_comp_vector(&receive,&expected,sizeof(fixed_t),"fix_rad(80)");
    printf("\n");
}

void fix_rad_test_4()
{
    fixed_t expected=fix_val(6.283172);
    fixed_t v=fix_val(360);
    fixed_t receive=fix_rad(v);
    printf("receive     " );
    fix_print(receive);
    printf("\nexpected    ");
    fix_print(expected);
    printf("\n");
    hfunit_comp_vector(&receive,&expected,sizeof(fixed_t),"fix_rad(360)");
    
}