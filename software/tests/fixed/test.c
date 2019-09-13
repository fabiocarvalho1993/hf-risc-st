#include <hf-risc.h>
#include <hf-unit.h>
#include <fixed.h>
extern int failed_tests;
extern int executed_tests;



// function under test 
fixed_t fix_asin(fixed_t expected);
fixed_t fix_acos(fixed_t expected);
fixed_t fix_sinh(fixed_t arg);
fixed_t fix_tan(fixed_t rad);
fixed_t fix_rad(fixed_t deg);


// list of individual tests
void fix_asin_test();
void fix_asin_test_2();
void fix_asin_test_3();

void fix_rad_test();
void fix_rad_test_2();
void fix_rad_test_3();
// main test
void hfunit_run_tests(){
fix_asin_test();
fix_asin_test_2();
fix_asin_test_3();

fix_rad_test();
fix_rad_test_2();
fix_rad_test_3();

}

void fix_asin_test()
{
    fixed_t expected=1.57079633;
    fixed_t receive=fix_asin(2.0);
    
    ASSERT_EQUALS_FIXED(receive,expected,"fix_asin(2.0)");
}
void fix_asin_test_2()
{
    fixed_t expected=1.57079633;
    fixed_t receive=fix_asin(1.0);
    
    ASSERT_EQUALS_FIXED(receive,expected,"fix_asin(1)");
}
void fix_asin_test_3()
{
    fixed_t expected=0.0;
    fixed_t receive=fix_asin(0.0);
    ASSERT_EQUALS_FIXED(receive,expected,"fix_asin(0.0)");
}

//--------------------------------------------------------------------------------//

void fix_rad_test()
{
    fixed_t expected=1.0472;
    fixed_t receive=fix_rad(60);
    ASSERT_EQUALS_FIXED(receive,expected,"fix_rad(60)");
}
void fix_rad_test_2()
{
    fixed_t expected=1.5708;
    fixed_t receive=fix_rad(90);
    ASSERT_EQUALS_FIXED(receive,expected,"fix_rad(90)");
}
void fix_rad_test_3()
{
    fixed_t expected=1.39626;
    fixed_t receive=fix_rad(80);
    ASSERT_EQUALS_FIXED(receive,expected,"fix_rad(80)");
}