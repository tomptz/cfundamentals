/*
 * linked_list.c
 *
 *  Created on: Sep 10, 2016
 *      Author: tomp
 */

#include <stdlib.h>
#include <stdio.h>
#include <CUnit/Basic.h>
#include "linked_list.h"
#include <assert.h>

struct llist
{
	void* (*element_malloc)();
	void (*element_copy)(void* src, void* dest);
	void (*element_free)(void** element);

};


llist_t* create_list()
{
	llist_t* list = malloc(sizeof(llist_t));

	assert(list != NULL);

	return list;
}


void delete_list(llist_t** list)
{
	free(*list); //Don't forget dereferencing the double pointer
	*list=NULL;
	assert(*list == NULL);

}
