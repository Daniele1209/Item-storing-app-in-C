#include "repo.h"
#include "operations.h"
#pragma once

typedef struct {
	Item_repo* item_list;
} Service;

Service* create_service(Item_repo* r);
void destroy_service(Service* s);
int add_item_service(Service* s,int number, char* state, char* type, int value);
void remove_item(Service* s, int number);
void add_items_default(Service* s);
//int undo(Service* s);

Item_repo* get_repo(Service* s);
