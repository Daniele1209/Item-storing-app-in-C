#include "entities.h"
#include "dynamic_array.h"
#include <string.h>
#pragma once

typedef struct {
	Item* item;
	char* op_executed;
} Operation;

Operation* create_op(Item* n, char* op_executed);
void destroy_op(Operation* o);
char* get_type_op(Operation* o);
Operation* copy_op(Operation* o);
Item* get_item(Operation* o);

typedef struct {
	Operation* op_list[100];
	int list_len;
}Stack_of_op;

Stack_of_op* create_stack();
void destroy_stack(Stack_of_op* t);
void push_to_stack(Stack_of_op* t);
Operation* pop_op(Stack_of_op* t);
int verify_empty(Stack_of_op* t);
int verify_full(Stack_of_op* t);

void stack_tests();