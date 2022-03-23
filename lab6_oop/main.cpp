#include"Ui.h"
#include "PersonController.h"
#include "PersonInMemoryRepository.h"
#include "Person.h"
#include"Test.h"
int main()
{
	CarInMemoryRepository Repos;
	CarController cont;
	PersonInMemoryRepository repo1;
	PersonController repo;
	Tests tests;
	tests.test_add();
	tests.test_getters();
	tests.test_modify();
	tests.test_remove();
	tests.test_filter();
	tests.test_search();
	tests.test_sort();
	tests.test_add_to_favorite_list();
	cont.load_from_file("C:\\Users\\Bohm Evelin\\source\\repos\\lab6_oop\\lab6_oop\\cars.csv");
	std::cout << std::endl;
	UI ui;
	ui.choose_menu();

	return 0;
}