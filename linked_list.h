/*
 * linked_list.h
 *
 *  Created on: Sep 10, 2016
 *      Author: tomp
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct llist llist_t; //forward declaration of linked list object (contents should be "private")

llist_t* create_list(void* (*element_malloc)(), void (*element_copy)(const void* src, void* dest), void (*element_free)(void** element), void(*element_print)(const void* element));
void delete_list(llist_t** list); //Double pointer to allow for nulling of original pointer

void insert_element(llist_t* list, int index, const void* element);
void* get_element(llist_t* list, int index);
void print_list(const llist_t* list);


#endif /* LINKED_LIST_H_ */
