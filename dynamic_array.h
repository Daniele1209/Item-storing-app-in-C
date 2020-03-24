#pragma once
#include "entities.h"
#define LENGTH 12

typedef Item* TElem;

typedef struct {
	TElem* elements;
	int len;
	int max_len;
} Dynamic_array;

Dynamic_array* create_array(int max_len);
void destroy_array(Dynamic_array* ary);
int add_an_item(Dynamic_array* ary, TElem t);
void delete_an_item(Dynamic_array* ary, int item_pos);
int get_dimension(Dynamic_array* ary);

TElem get(Dynamic_array* ary, int item_pos);

void test_array();