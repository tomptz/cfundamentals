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
#include <string.h>


static llist_t* list;

typedef struct person_t
{
	char name[50];
	int age;
	struct person_t* child;

} person_t;

person_t* father;
person_t* son;
person_t* another_person;

void* element_malloc()
{
	person_t* person = malloc(sizeof(person_t));
	assert(person != NULL);

	return person;
}

void element_copy(const void* src, void* dest)
{
	//Cast to get access to person_t struct
	const person_t* person_src = (const person_t*) src;
	person_t* person_dest = (person_t*) dest;

	memcpy(person_dest->name, person_src->name, sizeof(person_src->name));
	person_dest->age = person_src->age;

	if (person_src->child != NULL)
	{
		person_dest->child = (person_t*) element_malloc();
		element_copy(person_src->child, person_dest->child);
	}

}

void element_free(void** element)
{

	person_t** person = (person_t**) element;

	if((*person)->child != NULL)
	{
		element_free((void**)&((*person)->child));
	}
	free(*person);
	*person = NULL;

	assert(*person == NULL);
}

void element_print(const void* element)
{
	person_t* person = (person_t *) element;
	printf("Person %s, %d years old", person->name, person->age);

	if (person->child != NULL)
	{
		printf(", has a child %s\n", person->child->name);
		element_print((const void*)person->child);
	}
	else
		printf("\n");
}




int init_suite1(void)
{
	father = malloc(sizeof(person_t));
	son = malloc(sizeof(person_t));

	strcpy(father->name, "Tom");
	strcpy(son->name, "Elias");

	father->age=30;
	son->age=2;

	father->child = son;
	son->child = NULL;

	return 0;
}


int clean_suite1(void)
{
	element_free((void **)&father);
	element_free((void **)&son);
	return 0;

}


void test1(void)
{
	list = create_list(element_malloc, element_copy, element_free, element_print);
	CU_ASSERT(list != NULL);

	delete_list(&list);
	CU_ASSERT(list == NULL);
}

void test2(void)
{
	list = create_list(element_malloc, element_copy, element_free, element_print);
	insert_element(list, -1, father);

	another_person =  malloc(sizeof(person_t));
	strcpy(another_person->name, "Jan");
	another_person->age=50;
	another_person->child = NULL;
	insert_element(list, -1, another_person);
	element_free((void **)&another_person);

	another_person =  malloc(sizeof(person_t));
	strcpy(another_person->name, "Miranda");
	another_person->age=32;
	another_person->child = NULL;
	insert_element(list, -1, another_person);
	element_free((void **)&another_person);

	printf("\n\n");
	print_list(list);
	printf("\n\n");

	delete_list(&list);
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
	if ((NULL == CU_add_test(pSuite, "Create and delete list", test1)) ||
			(NULL == CU_add_test(pSuite, "Adding and retrieving an element to the list", test2))

	)
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
