/*
  HF-RISC Unit Testing framework

  edit these macros to chage the behavior of HF-UNIT.
  See usage examples in the dir software/tests
*/
#include<hf-unit.h>


// =======================
// util functions
// =======================
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}




// =======================
// comparison functions
// =======================

// compare int/char/short vectors. do not use this for vector of float or double. it wont work !
int hfunit_comp_vector(void *v1,void *v2, int size, char* message){
	test_counter++;
	executed_tests++;
	if (memcmp(v1,v2,size)!=0){
		failed_tests++;
		HFUNIT_MSG_FAIL(message)
		return 1;
	}else{
		HFUNIT_MSG_PASS(message)
		return 0;
	}
}

// compare floats
int hfunit_comp_float(float f1,float f2, char *message){
	test_counter++;
	executed_tests++;
	if (!(((f1 - HFUNIT_PRECISION) < f2) && ((f1 + HFUNIT_PRECISION) > f2)))
	{
		failed_tests++;
		HFUNIT_MSG_FAIL(message)
		return 1;
	}else{
		HFUNIT_MSG_PASS(message)
		return 0;
	}
}

void ASSERT_EQUALS_FIXED(int arg,int arg2,char* message)
{
    test_counter++;
    executed_tests++;
    if(arg!=arg2)
    {
        
        failed_tests++;
        HFUNIT_MSG_FAIL(message)
    }
    else 
    {
        
        HFUNIT_MSG_PASS(message)
    	
    }
}
void ASSERT_EQUALS(int arg,char* message)
{
    test_counter++;
    executed_tests++;
    if(arg==0)
    {
        
        failed_tests++;
        HFUNIT_MSG_FAIL(message)
    }
     else 
     {
        
         HFUNIT_MSG_PASS(message)
        
     }
}

void ASSERT_EQUALS_FLOAT(float result,float expected,float epsilon,const char * message)
{
        test_counter++;
        executed_tests++;
        if(expected>(result-epsilon)&&(result+epsilon))
        {
            HFUNIT_MSG_PASS(message);
        }
        else
        {
            failed_tests++;
            HFUNIT_MSG_FAIL(message);
        }
}
