#include <stdlib.h>
#include <string.h>
#include "services.h"

Service* create_service(Item_repo* r, Operation_stack* os) {
	Service* s = (Service*)malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->item_list = r;
	return s;
}

void destroy_service(Service* s) {
	destroy_repo(s->item_list);
	free(s);
}

int add_item_service(Service* s, int number, char* state, char* type, int value) {
	Item* n = create_item(number, state, type, value);
	add_item(s -> item_list, n);
	save_repo(s->item_list);
}

Item_repo* get_repo(Service* s) {
	return s->item_list;
}

void remove_item(Service* s, int number) {
	delete_item(s->item_list, number);
	save_repo(s->item_list);
}

int undo_srv(Service* s) {
	return undo_repo(s->item_list);
}

int redo_srv(Service* s) {
	return redo_repo(s->item_list);
}