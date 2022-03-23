#pragma once
#include "CarController.h"
#include<assert.h>
#include "PersonController.h"

class Tests {

private:
	CarController Product_test;
	PersonController Person_test;

public:
	void test_add();
	void test_remove();
	void test_modify();
	void test_getters();
	void test_filter();
	void test_search();
	void test_sort();
	void test_add_to_favorite_list();


};