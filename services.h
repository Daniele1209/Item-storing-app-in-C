#include "repo.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma once

typedef struct {
	Item_repo* item_list;
} Service;

Service* create_service(Item_repo* r);
void destroy_service(Service* s);
int add_item_service(Service* s,int number, char* state, char* type, int value);
int update_item(Service* s, int number, char* state, char* type, int value);
void remove_item(Service* s, int number);
int undo_srv(Service* s);
int redo_srv(Service* s);

Item_repo* get_repo(Service* s);
