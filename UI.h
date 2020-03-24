#pragma once
#include "services.h"

typedef struct
{
	Service* services;
} UI;

UI* create_UI(Service* s);
void destroy_UI(UI* ui);
void UI_console(UI* ui);

void add_some_enteries(UI* ui);