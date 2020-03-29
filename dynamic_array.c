#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Dynamic_array* create_array(int max_len) {
	Dynamic_array* d = (Dynamic_array*)malloc(sizeof(Dynamic_array));
	if (d == NULL) {
		return NULL;
	}
	d->len = 0;
	d->max_len = max_len;
	d->elements = (TElem*)malloc(max_len * sizeof(TElem));
	if (d->elements == NULL)
		return NULL;

	return d;
}

int add_an_item(Dynamic_array* ary, TElem t) {
	if (ary == NULL)
		return;
	if (ary->elements == NULL)
		return;
	if (ary->len == ary->max_len) {
		resize_array(ary);
	}
	ary->elements[ary->len++] = t;
}

int get_dimension(Dynamic_array* ary) {
	if (ary == NULL) {
		return -1;
	}
	return ary->len;
}

void delete_an_item(Dynamic_array* ary, int item_position) {

	for (int i = item_position; i <= ary->len - 1; i++) {
		ary->elements[i] = ary->elements[i + 1];
	}
	ary->len--;
}

int resize_array(Dynamic_array* ary) {
	if (ary == NULL) {
		return -1;
	}
	ary->max_len *= 2;
	TElem* new_one = (TElem*)malloc(ary->max_len * sizeof(TElem));
	if (new_one == NULL) {
		return -1;
	}
	for (int i = 0; i <= ary->len - 1; i++) {
		new_one[i] = ary->elements[i];
	}
	free(ary->elements);
	ary->elements = new_one;

	return 0;
}

TElem get(Dynamic_array* ary, int position) {
	if (ary == NULL)
		return NULL;
	if (position < 0 || position >= ary->len)
		return NULL;
	return ary->elements[position];

}

Dynamic_array* copy_array(Dynamic_array* d) {
	Dynamic_array* copy = create_array(d->max_len);
	for (int i = 0; i < d->len; i++) {
		add_an_item(copy, new_item(d->elements[i]));
	}
	return copy;
}

void destroy_array(Dynamic_array* ary) {
	if (ary == NULL)
		return;
	for (int i = 0; i < ary->len; i++) {
		destroy_item(ary->elements[i]);
	}
	free(ary->elements);
	//ary->elements = NULL;
	free(ary);

}
void test_array() {
	Dynamic_array* ary = create_array(2);
	if (ary == NULL)
		assert(0);
	//test array length
	assert(ary->max_len == 2);
	assert(ary->len == 0);

	Item* item_1 = create_item(01, "good", "sword", 420);
	add_an_item(ary, item_1);
	assert(ary->len == 1);

	Item* item_2 = create_item(02, "crap", "armour", 12);
	add_an_item(ary, item_2);
	assert(ary->len == 2);
	
	//Now, when we try to add one more item, the max_len should resize and from len 2 it should get to len 4 (double its size)
	Item* item_3 = create_item(03, "quite_good", "helmet", 32);
	add_an_item(ary, item_3);
	assert(ary->len == 3);
	assert(ary->max_len == 4);

	destroy_array(ary);
}
