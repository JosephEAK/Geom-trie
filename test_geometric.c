#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <math.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "geometric.h"

void test_dames_dummy(void){

	CU_ASSERT(0 == 0);
}

void testisRectangle(void){
    rectangle object;
    coord p[4];

    p[0].x = 0;
    p[1].x = 0;
    p[2].x = 1;
    p[3].x = 1;

    p[0].y = 0;
    p[1].y = 2;
    p[2].y = 2;
    p[3].y = 0;

    object.a = p[0];
    object.b = p[1];
    object.c = p[2];
    object.d = p[3];

    CU_ASSERT(isRectangle(object) == 2);
}

void testisTriangle(void){
	triangle object1, object2, object3;
    coord p1[3], p2[3], p3[3];

	//equilateral
	p1[0].x = 0;
    p1[1].x = 1;
    p1[2].x = 0.5;

	p1[0].y = 0;
    p1[1].y = 0;
    p1[2].y = 0.866100001;

	//isocèle
	p2[0].x = 0;
    p2[1].x = 1;
    p2[2].x = 0;

	p2[0].y = 0;
    p2[1].y = 1;
    p2[2].y = 1;

	//rectangle
	p3[0].x = 0;
    p3[1].x = 2;
    p3[2].x = 0;

	p3[0].y = 0;
    p3[1].y = 1;
    p3[2].y = 1;


	object1.a = p1[0];
    object1.b = p1[1];
    object1.c = p1[2];

	object2.a = p2[0];
    object2.b = p2[1];
    object2.c = p2[2];

	object3.a = p3[0];
    object3.b = p3[1];
    object3.c = p3[2];

	CU_ASSERT(isTriangle(object1) == 1);
	CU_ASSERT(isTriangle(object2) == 2);
	CU_ASSERT(isTriangle(object3) == 3);

}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */
	if (
		NULL == CU_add_test(pSuite, "test of test_dames_dummy()", test_dames_dummy) ||
        NULL == CU_add_test(pSuite, "test of isRectangle()", testisRectangle) ||
		NULL == CU_add_test(pSuite, "test of isTriangle()", testisTriangle) 
	)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
