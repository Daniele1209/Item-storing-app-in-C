#include "UI.h"
#include "repo.h"
#include <stdio.h>

int main() {
	//test_array();
	//test_repo();

	Item_repo* repo = create_repo();
	Operation_stack* op_stack = create_stack();
	Service* services = create_service(repo, op_stack);
	UI* ui = create_UI(services);
	UI_console(ui);
	destroy_UI(ui);

	printf("Memory leak: %d\n",_CrtDumpMemoryLeaks());
	return 0;
}