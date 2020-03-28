#include "operations.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* creaate_operation(Item* n, char* op_type) {
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->item = copy_op(n);
	if (op_type != NULL) {
		o->op_type = (char*)malloc(sizeof(char*) * (strlen(op_type) + 1));
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
	dree(o->op_type);
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
	os->list_len = 0;
	return os;
}

void push(Operation_stack* os, Operation* o) {
	//to do
}

Operation* pop(Operation_stack* os) {
	//to do
	return NULL;
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