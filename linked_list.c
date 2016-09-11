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
	int nr_elements;
	void* head;
	void* tail;
	void* (*element_malloc)();
	void (*element_copy)(const void* src, void* dest);
	void (*element_free)(void** element);
	void (*element_print)(const void* element);

};

typedef struct node_t
{
	struct node_t* next;
	struct node_t* previous;
	void* element;

} node_t;

llist_t* create_list(void* (*element_malloc)(), void (*element_copy)(const void* src, void* dest), void (*element_free)(void** element), void(*element_print)(const void* element))
{
	llist_t* list = malloc(sizeof(llist_t));

	assert(list != NULL);

	list->nr_elements=0;
	list->head = NULL;
	list->tail = NULL;

	assert(element_malloc != NULL);
	assert(element_copy != NULL);
	assert(element_free != NULL);
	assert(element_print != NULL);


	list->element_malloc = element_malloc;
	list->element_copy = element_copy;
	list->element_free = element_free;
	list->element_print = element_print;

	return list;
}


void delete_list(llist_t** list)
{
	if((*list)->nr_elements>0)
	{
		node_t * current_node = (*list)->tail;
		node_t * previous_node;

		while(1)
		{
			(*list)->element_free(&current_node->element);

			if(current_node->next != NULL)
			{
				previous_node = current_node;
				current_node = current_node->next;
				free(previous_node);
			}
			else
			{
				free(current_node);
				break;
			}

		}

	}

	free(*list); //Don't forget dereferencing the double pointer
	*list=NULL;
	assert(*list == NULL);

}

void print_list(const llist_t* list)
{
	if(list->nr_elements>0)
	{
		const node_t * current_node = list->tail;

		while(1)
		{
			list->element_print(current_node->element);

			if(current_node->next != NULL)
				current_node = current_node->next;
			else
				break;

		}

	}
}


void insert_element(llist_t* list, int index, const void* element)
{
	node_t* new_node = malloc(sizeof(node_t));

	//Create new element using deep copy
	void* new_element = list->element_malloc();
	list->element_copy(element, new_element);
	new_node->element = new_element;


	if (list->head == NULL) //List empty
	{
		list->head = new_node;
		list->tail = new_node;
		new_node->next = NULL;
		new_node->previous = NULL;
		list->nr_elements++;

	}
	else if (index == -1 || index>=list->nr_elements) //List not empty, insert at head (after last inserted element)
	{
		node_t* previous_head = list->head;
		previous_head->next = new_node;
		new_node->previous = previous_head;
		new_node->next = NULL;
		list->nr_elements++;
		list->head = new_node;
	}

	else if (index == 0) //List not empty, insert at tail (before first inserted element)
	{
		node_t* previous_tail = list->tail;
		previous_tail->previous = new_node;
		new_node->next = previous_tail;
		new_node->previous = NULL;
		list->tail = new_node;
		list->nr_elements++;
	}
	else //List not empty, insert somewhere in the middle
	{
		node_t* current_node = list->tail;

		for (int node_counter = 0; node_counter < index; node_counter++)
		{
			current_node = current_node->next;
		}

		current_node->next->previous = new_node;
		current_node->next = new_node;
		new_node->previous = current_node;
		list->nr_elements++;

	}


}


void* get_element(llist_t* list, int index)
{

}
