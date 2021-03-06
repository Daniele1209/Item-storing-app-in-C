#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

UI* create_UI(Service* s)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->services = s;

	return ui;
}

void destroy_UI(UI* ui) {
	free(ui);
}

//verify is a given string is a valid number
int is_valid_int(const char* str)
{

	if (*str == '-')
		++str;

	if (!*str)
		return 0;

	while (*str)
	{
		if (!isdigit(*str))
			return 0;
		else
			++str;
	}

	return 1;
}
// the add functionality
void add_fct(char* command, UI* ui) {
	int ok = 1;
	int number, value;
	char state[20];
	char type[20];

	char *d = strtok(command, " ");
	d = strtok(NULL, ", ");
	if(d) {
		number = atoi(d);
		d = strtok(NULL, ", ");
		if (d) {
			strcpy(state, d);
			d = strtok(NULL, ", ");
			if (d) {
				strcpy(type, d);
				d = strtok(NULL, ", ");
				if (d) {
					value = atoi(d);
				}
				else
					ok = 0;
			}
			else
				ok = 0;
		}
		else
			ok = 0;
	}
	else
		ok = 0;
	if (ok) {
		//verify existence of item
		Item_repo* repo = get_repo(ui->services);
		int lenn = get_list_length(repo);
		for (int i = 0; i < lenn; i++) {
			Item* item = get_item_position(repo, i);
			if (get_number(item) == number) {
				ok = 0;
			}
		}
	}
	if (ok == 0)
		printf("No!\n");	
	else
		if (!add_item_service(ui->services, number, state, type, value))
			printf("No!\n");
}
//delete functionality
void delete_fct(char* command, UI* ui) {
	int ok = 1;
	if (ui == NULL)
		return;
	Item_repo* repo = get_repo(ui->services);
	int lenn = get_list_length(repo);
	char* d = strtok(command, " ");
	int number = atoi(strtok(NULL, ""));
	for (int i = 0; i < lenn; i++) {
		Item* item = get_item_position(repo, i);
		if (get_number(item) == number) {
			remove_item(ui->services, i);
			destroy_item(item);
			ok = 0;
		}
	}
	if (ok == 1)
		printf("No!\n");
}
//update functionality
void update_fct(char *command, UI* ui) {
	int ok = 1;
	int number, value;
	char state[20];
	char type[20];

	char* d = strtok(command, " ");
	d = strtok(NULL, ", ");
	if (d) {
		number = atoi(d);
		d = strtok(NULL, ", ");
		if (d) {
			strcpy(state, d);
			d = strtok(NULL, ", ");
			if (d) {
				strcpy(type, d);
				d = strtok(NULL, ", ");
				if (d) {
					value = atoi(d);
				}
				else
					ok = 0;
			}
			else
				ok = 0;
		}
		else
			ok = 0;
	}
	else
		ok = 0;

	if (ok) {
		Item_repo* repo = get_repo(ui->services);
		int lenn = get_list_length(repo);
		for (int i = 0; i < lenn; i++) {
			Item* item = get_item_position(repo, i);
			if (get_number(item) == number) {
				update_item(ui->services, number, state, type, value);
				ok = 0;
			}
		}
	}
	if (ok == 1)
		printf("No!\n");
}
//prints the list
void list_fct(UI* ui) {
	if (ui == NULL)
		return;
	Item_repo* repo = get_repo(ui->services);
	int lenn = get_list_length(repo);
	for (int i = 0; i < lenn; i++) {
		Item* item = get_item_position(repo, i);
		char item_str[100];
		print_message(item, item_str);
		printf("%s\n", item_str);
	}
}
//prints only the items from list that are a given type
void list_type_fct(char *command, UI* ui) {
	int ok = 1;
	if (ui == NULL)
		return;
	char* d = strtok(command, " ");
	char* chosen_type = strtok(NULL, "");
	Item_repo* repo = get_repo(ui->services);
	int lenn = get_list_length(repo);
	for (int i = 0; i < lenn; i++) {
		Item* item = get_item_position(repo, i);
		if (strcmp(get_type(item), chosen_type) == 0) {
			char item_str[100];
			print_message(item, item_str);
			printf("%s\n", item_str);
			ok = 0;
		}
	}
	if (ok == 1)
		printf("No!\n");
}

void undo_fct(UI* ui) {
	if (!undo_srv(ui->services))
		printf("Can't undo !\n");
}

void redo_fct(UI* ui) {
	if(!redo_srv(ui->services))
		printf("Can't redo !\n");
}
//only prints the items that are lower than a given value 
void filter_fct(char* command, UI* ui) {
	int ok = 1;
	if (ui == NULL)
		return;
	char* d = strtok(command, " ");
	d = strtok(NULL, "");
	int max_value = atoi(d);
	Item_repo* repo = get_repo(ui->services);
	int lenn = get_list_length(repo);
	for (int i = 0; i < lenn; i++) {
		Item* item = get_item_position(repo, i);
		if (get_value(item) < max_value) {
			char item_str[100];
			print_message(item, item_str);
			printf("%s\n", item_str);
			ok = 0;
		}
	}
	if (ok == 1)
		printf("No!\n");
}

void UI_console(UI* ui) {
	int ok = 1;
	while (ok)
	{
		printf(">>>\t");
		char cmd[100], cmd_aux[100], *command;

		scanf("%[^\n]%*c", cmd);
		strcpy(cmd_aux, cmd);
		command = strtok(cmd_aux, " ");

		if (strcmp(command, "add") == 0) {
			add_fct(cmd, ui);
		}
		else if (strcmp(command, "update") == 0) {
			update_fct(cmd, ui);
		}
		else if (strcmp(command, "delete") == 0) {
			delete_fct(cmd, ui);
		}
		else if (strcmp(command, "list") == 0) {
			command = strtok(0, " ");
			if (!command) {
				list_fct(ui);
			}
			else {
				if (is_valid_int(command) == 0) {
					list_type_fct(cmd, ui);
				}
				else {
					filter_fct(cmd, ui);
				}
			}
		}
		else if (strcmp(command, "undo") == 0) {
			undo_fct(ui);
		}
		else if (strcmp(command, "redo") == 0) {
			redo_fct(ui);
		}
		else if (strcmp(command, "exit") == 0) {
			ok = 0;
		}
		else printf("No!\n");
	}
}
