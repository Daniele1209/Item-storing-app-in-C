#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Dynamic_array* create_array(int max_len) {
	Dynamic_array* d = malloc(sizeof(Dynamic_array));
	if (d == NULL) 
		return NULL;
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
//the function that resizes the dynamic array
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
//gets the element on the position given
TElem get(Dynamic_array* ary, int position) {
	if (ary == NULL)
		return NULL;
	if (position < 0 || position >= ary->len)
		return NULL;
	return ary->elements[position];

}
//returns a copy of the dynamic array
Dynamic_array* copy_array(Dynamic_array* d) {
	Dynamic_array* copy = create_array(d->max_len);
	for (int i = 0; i < d->len; i++) {
		add_an_item(copy, new_item(d->elements[i]));
	}
	return copy;
}
//destroys a basic dynamic array
void destroy_array(Dynamic_array* ary) {
	if (ary == NULL)
		return;
	for (int i = 0; i < ary->len; i++) {
		destroy_item(ary->elements[i]);
	}
	free(ary->elements);
	ary->elements = NULL;
	free(ary);

}
//destroys an array of arrays, for example the array "history"
void destroy_vector(Dynamic_array* ary) {
	if (ary == NULL)
		return;
	for (int i = 0; i < ary->len; i++) {
		destroy_array(ary->elements[i]);
	}
	free(ary->elements);
	ary->elements = NULL;
	free(ary);
}

