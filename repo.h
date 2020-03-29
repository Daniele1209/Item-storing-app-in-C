#pragma once
#include "entities.h"
#include <stdlib.h>
#include "dynamic_array.h"

typedef struct {
	Dynamic_array* items;
	Dynamic_array* history;
	int index;
} Item_repo;

Item_repo* create_repo();

void destroy_repo(Item_repo* r);

Item* search_item(Item_repo* r, int number);

int add_item(Item_repo* r, Item* n);

void delete_item(Item_repo* r, int number);

int get_list_length(Item_repo* r);

Item* get_item_position(Item_repo* r, int position);

void save_repo(Item_repo* r);

int undo_repo(Item_repo* r);

int redo_repo(Item_repo* r);

void test_repo();





