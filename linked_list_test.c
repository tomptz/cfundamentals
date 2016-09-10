/*
 * linked_list_test.c
 *
 *  Created on: Sep 10, 2016
 *      Author: tomp
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "linked_list.h"

static llist_t* list;

typedef struct person_t
{
	const char name[50];
	int age;
	struct person_t* child;

} person_t;

void* element_malloc()
{
	person_t* person = malloc(sizeof(person_t));
	assert(person != NULL);

	person_t* child = malloc(sizeof(person_t));
	person->child = child;

	return person;

}




int init_suite1(void)
{	return 0;
}


int clean_suite1(void)
{
	return 0;

}

void test1(void)
{
	list = create_list();
	CU_ASSERT(list != NULL);

	delete_list(&list);
	CU_ASSERT(list == NULL);
}


int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* NOTE - ORDER IS IMPORTANT */
	if ((NULL == CU_add_test(pSuite, "Test 1", test1)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();



}
