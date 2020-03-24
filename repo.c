#include "repo.h";
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Item_repo* create_repo() {
	Item_repo* r = (Item_repo*)malloc(sizeof(Item_repo));
	if (r == NULL) {
		return NULL;
	}
	r->items = create_array(LENGTH);

	return r;
}

void destroy_repo(Item_repo* r) {
	if (r == NULL)
		return;
	destroy_array(r->items);
	free(r);
}

int add_item(Item_repo* r, Item* n) {
	if (r == NULL || n == NULL)
		return 0;
	add_an_item(r->items, n);
	return 1;
}

void delete_item(Item_repo* r, int number) {
	delete_an_item(r->items, number);
}

int get_list_length(Item_repo* r) {
	if (r == NULL)
		return -1;

	return get_dimension(r->items);
}

Item* search_item(Item_repo* r, int number) {
	
	return NULL;
}

Item* get_item_position(Item_repo* r, int position) {
	if (r == NULL)
		return NULL;
	return get(r->items, position);
}

void add_items_by_default(Item_repo* r) {
	Item* item_1 = create_item(01, "nice", "axe", 14);
	Item* item_2 = create_item(02, "ok", "chest", 123);
	Item* item_3 = create_item(03, "damaged", "sword", 56);
	Item* item_4 = create_item(04, "legendary", "helmet", 120);
	add_item(r, item_1);
	add_item(r, item_2);
	add_item(r, item_3);
	add_item(r, item_4);
}

void test_repo() {
	Item_repo* i = create_repo();
	Item* item_1 = create_item(01, "nice", "axe", 14);
	add_item(i, item_1);
	assert(get_list_length(i) == 1);
	assert(strcmp(get_state(get_item_position(i, 0)), "nice") == 0);

	destroy_repo(i);
}
