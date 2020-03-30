#pragma once
#define _CRT_SECURE_NO_DEPRECATE

typedef struct {
	int catalogueNumber, value;
	char* state;
	char* type;
} Item;

Item* create_item(int catalogueNumber, char* state, char* type, int value);
int get_number(Item* n);
char* get_state(Item* n);
char* get_type(Item* n);
int get_value(Item* n);
void destroy_item(Item* n);
void print_message(Item* n, char string[]);
Item* new_item(Item* n);
