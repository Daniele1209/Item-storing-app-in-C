#include "repo.h";
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Item_repo* create_repo() {
	Item_repo* r = (Item_repo*)malloc(sizeof(Item_repo));
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
	destroy_vector(r->history);
	free(r);
}

int add_item(Item_repo* r, Item* n) {
	if (r == NULL || n == NULL)
		return 0;
	add_an_item(r->items, n);
	return 1;
}

int update_repo(Item_repo* r, Item* n) {
	for (int i = 0; i < r->items->len; i++)
		if (get_number(r->items->elements[i]) == n->catalogueNumber)
		{
			destroy_item(r->items->elements[i]);
			r->items->elements[i] = n;
			break;
		}
}

void delete_item(Item_repo* r, int number) {
	delete_an_item(r->items, number);
}
//returns the length of a given list
int get_list_length(Item_repo* r) {
	if (r == NULL)
		return -1;

	return get_dimension(r->items);
}

int check(Item_repo* r, int number) {
	for (int i = 0; i < r->items->len; i++)
		if (get_number(r->items->elements[i]) == number)
			return 1;
	return 0;
}

//returns the item from the given position 
Item* get_item_position(Item_repo* r, int position) {
	if (r == NULL)
		return NULL;
	return get(r->items, position);
}
//saves the current repo in history so we can undo and redo
void save_repo(Item_repo* r) {
	r->index++;
	for (int i = r->index; i < r->history->len; i++) {
		destroy_array(r->history->elements[i]);
	}
	r->history->len = r->index;
	add_an_item(r->history, copy_array(r->items));
}
//undo functionality that returns the last saved repo
int undo_repo(Item_repo* r) {
	if (r->index <= 0)
		return 0;
	destroy_array(r->items);
	r->index--;
	r->items = copy_array(r->history->elements[r->index]);

	return 1;
}
//redo functionality 
int redo_repo(Item_repo* r) {
	if (r->index+1 >= r->history->len)
		return 0;
	destroy_array(r->items);
	r->index++;
	r->items = copy_array(r->history->elements[r->index]);

	return 1;
}
