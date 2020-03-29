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
	r->history = create_array(LENGTH);
	r->index = -1;
	save_repo(r);
	return r;
}

void destroy_repo(Item_repo* r) {
	if (r == NULL)
		return;
	destroy_array(r->items);
	destroy_array(r->history);
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

void save_repo(Item_repo* r) {
	r->index++;
	for (int i = r->index; i < r->history->len; i++) {
		destroy_array(r->history->elements[i]);
	}
	r->history->len = r->index;
	add_an_item(r->history, copy_array(r->items));
}

int undo_repo(Item_repo* r) {
	if (r->index <= 0)
		return 0;
	destroy_array(r->items);
	r->index--;
	r->items = copy_array(r->history->elements[r->index]);

	return 1;
}

int redo_repo(Item_repo* r) {
	if (r->index++ >= r->history->len)
		return 0;
	destroy_array(r->items);
	r->index++;
	r->items = copy_array(r->history->elements[r->index]);

	return 1;
}

void test_repo() {
	Item_repo* i = create_repo();
	Item* item_1 = create_item(01, "nice", "axe", 14);
	add_item(i, item_1);
	assert(get_list_length(i) == 1);
	assert(strcmp(get_state(get_item_position(i, 0)), "nice") == 0);

	destroy_repo(i);
}
