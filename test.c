#include "test.h"

void test_array() {
	Dynamic_array* ary = create_array(2);
	if (ary == NULL)
		assert(0);
	//test array length
	assert(ary->max_len == 2);
	assert(ary->len == 0);

	Item* item_1 = create_item(01, "good", "sword", 420);
	add_an_item(ary, item_1);
	assert(ary->len == 1);

	Item* item_2 = create_item(02, "crap", "armour", 12);
	add_an_item(ary, item_2);
	assert(ary->len == 2);

	//Now, when we try to add one more item, the max_len should resize and from len 2 it should get to len 4 (double its size)
	Item* item_3 = create_item(03, "quite_good", "helmet", 32);
	add_an_item(ary, item_3);
	assert(ary->len == 3);
	assert(ary->max_len == 4);

	destroy_array(ary);
}

void test_valid_item() {
	Item* n = create_item(12, "meh", "sword", 29);
	assert(get_number(n) == 12);
	assert(strcmp(get_state(n), "meh") == 0);
	assert(strcmp(get_type(n), "sword") == 0);
	assert(get_value(n) == 29);

	destroy_item(n);

}

void test_repo() {
	Item_repo* r = create_repo();
	Item* n = create_item(12, "meh", "sword", 29);
	add_item(r, n);
	assert(get_list_length(r) == 1);

	destroy_repo(r);

}

void test_run() {
	test_array();
	test_valid_item();
	test_repo();
}