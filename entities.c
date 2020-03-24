#include "entities.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Item* create_item(int catalogueNumber, char* state, char* type, int value)
{
	Item* n = (Item*)malloc(sizeof(Item));

	n->catalogueNumber = catalogueNumber;
	n->state = (char*)malloc(sizeof(char) * (strlen(state) + 1));
	strcpy(n->state, state);
	n->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(n->type, type);
	n->value = value;

	return n;
}

int get_number(Item* n) {
	if (n == NULL)
		return -1;
	return n->catalogueNumber;
}

char* get_state(Item* n) {
	if (n == NULL)
		return NULL;
	return n->state;
}

char* get_type(Item* n) {
	if (n == NULL)
		return NULL;
	return n->type;
}

int get_value(Item* n) {
	if (n == NULL)
		return -1;
	return n->value;
}

void destroy_item(Item* n) {
	if (n == NULL)
		return;
	free(n->state);
	free(n->type);
	free(n);
}

void print_message(Item* n, char string[]) {
	if (n == NULL)
		return;
	sprintf(string, "Number: %d  State: %s  Type: %s  Value: %d ", n->catalogueNumber, n->state, n->type, n->value);
}

Item* new_item(Item* n) {
	if (n == NULL)
		return NULL;
	Item* new_Item = create_item(get_number(n), get_state(n), get_type(n), get_value(n));
	
	return new_Item;
}
