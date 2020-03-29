#include "entities.h"
#include "dynamic_array.h"
#include <string.h>
#pragma once

typedef struct {
	Item* item;
	char* op_type;
} Operation;

Operation* create_operation(Item* n, char* op_executed);
void destroy_operation(Operation* o);
char* get_type_operation(Operation* o);
Operation* copy_operation(Operation* o);
Item* get_item(Operation* o);


typedef struct {
	Operation* op_list[100];
	int list_len;
}Operation_stack;

Operation_stack* create_stack();
void destroy_stack(Operation_stack* os);
void push(Operation_stack* os, Operation* o);
Operation* pop(Operation_stack* os);
int verify_empty(Operation_stack* os);
int verify_full(Operation_stack* os);

void stack_tests();