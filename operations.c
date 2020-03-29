#include "operations.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* create_operation(Item* n, char* op_type) {
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->item = new_item(n);
	if (op_type != NULL) {
		o->op_type = (char*)malloc(sizeof(char) * (strlen(op_type) + 1));
		strcpy(o->op_type, op_type);
	}
	else {
		o->op_type = NULL;
	}
	return o;
}

void destroy_operation(Operation* o) {
	if (o == NULL)
		return;
	destroy_item(o->item);
	free(o->op_type);
	free(o);
}

Operation* copy_operation(Operation* o) {
	//to do
}

char* get_type_operation(Operation* o) {
	return o->op_type;
}

Item* get_item(Operation* o) {
	return o->item;
}

Operation_stack* create_stack() {
	Operation_stack* os = (Operation_stack*)malloc(sizeof(Operation_stack));
	os->list_len = 1;
	return os;
}

void destroy_stack(Operation_stack* os) {
	if (os == NULL) {
		return;
	}
	for (int i = 0; i < os->list_len; i++) {
		destroy_operation(os->op_list);
	}
	free(os);
}

void push(Operation_stack* os, Operation* o) {
	printf("%s\n", os->op_list[os->list_len]);
	os->op_list[os->list_len] = get_item(o);
	os->list_len += 1;
}

Operation* pop(Operation_stack* os) {
	if (os->list_len == -1)
		return;
	os->list_len -= 1;
	return os->op_list[os->list_len];
}

int verify_empty(Operation_stack* os) {
	return (os->list_len == 0);
}

int verify_full(Operation_stack* os) {
	return os->list_len == 100;
}

//we do the test for the stack 
void stack_tests() {
	Operation_stack* os = create_stack();
	//to do

	destroy_stack(os);
}