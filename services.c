#include <stdlib.h>
#include <string.h>
#include "services.h"

Service* create_service(Item_repo* r, Operation_stack* os) {
	Service* s = (Service*)malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->item_list = r;
	s->undo_stack = os;
	return s;
}

void destroy_service(Service* s) {
	destroy_repo(s->item_list);
	destroy_stack(s->undo_stack);
	free(s);
}

int add_item_service(Service* s, int number, char* state, char* type, int value) {
	Item* n = create_item(number, state, type, value);
	int new_item = add_item(s -> item_list, n);
	if (new_item) {
		Operation* o = create_operation(n, "add");
		push(s->undo_stack, o);
		destroy_operation(o);
	}
	return new_item;
}

Item_repo* get_repo(Service* s) {
	return s->item_list;
}

void remove_item(Service* s, int number) {
	delete_item(s->item_list, number);

	//Operation* o = create_operation(item, "delete");
	//push(s->undo_stack, o);
	//destroy_operation(o);
}

void add_items_default(Service* s) {
	add_items_by_default(s->item_list);
}

int undo(Service* s) {
	if (verify_empty(s->undo_stack));
	//printf("isempty\n");
		return 0;

	Operation* o = pop(s->undo_stack);
	//printf("%s\n", get_type_operation(o));
	if (strcmp(get_type_operation(o), "add") == 0) {
		Item* n = get_item(o);
		int number;
		number = get_number(o);
		delete_item(s->item_list, number);
	}
	else if(strcmp(get_type_operation(o), "delete") == 0){
		Item* n = get_item(o);
		/* int number, value;
		char type[100], state[100];
		number = get_number(n);
		value = get_value(n);
		strcpy(state, get_state(n));
		strcpy(type, get_type(n));
		Item* n = create_item(number, state, type, value); */
		add_item(s->item_list, n);
	}

	destroy_operation(o);
	
	return 1;
}

int redo(Service* s) {
	return 1;
}