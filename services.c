#include <stdlib.h>
#include <string.h>
#include "services.h"

Service* create_service(Item_repo* r) {
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
	int new_item = add_item(s -> item_list, n);

	return new_item;
}

Item_repo* get_repo(Service* s) {
	return s->item_list;
}

void remove_item(Service* s, int number) {
	delete_item(s->item_list, number);
}

void add_items_default(Service* s) {
	add_items_by_default(s->item_list);
}