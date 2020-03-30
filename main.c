#include "UI.h"
#include "repo.h"
#include "test.h"
#include <stdio.h>
#include <crtdbg.h>

int main() {

	test_run();

	Item_repo* repo = create_repo();
	Service* services = create_service(repo);
	UI* ui = create_UI(services);

	UI_console(ui);

	destroy_UI(ui);
	destroy_service(services);
	destroy_repo(repo);

	//this printf shows "1 if there are any memory leaks"
	printf("Memory leak: %d\n",_CrtDumpMemoryLeaks());
	return 0;
}