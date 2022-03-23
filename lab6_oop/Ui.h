
#pragma once
#include "CarController.h"
#include "PersonController.h"
//#include "CarInMemoryRepository.h"
using namespace std;


class UI {
private:
	CarInMemoryRepository repository;
	CarController controller;
	PersonInMemoryRepository person_repo;
	PersonController person_controller;


public:
	string file_name = repository.load_from_file("C:\\Users\\Bohm Evelin\\source\\repos\\lab6_oop\\lab6_oop\\cars.csv");
	UI();
	void choose_menu();
	void show_manager_menu();
	void show_kunde_menu();
	void read_options_manager();
	void read_options_kunde(string client_name);
	string read_name_client();
	void make_file_for_client(string name);
	string get_firstName(string name);
	string get_lastName(string name);

	void option_1();
	void option_2();
	void option_3();
	void option_4();
	void option_5();
	void option_6();
	void option_7();
	void option_8(string name);
	void option_9(string name);
	void option_10();
	void option_11();
	string read_string();
	int read_int();
	Car read_car();
	Car read_car_for_update();
	void print(vector<Car> list);
	bool check_string(std::string string);
	bool check_int(std::string number);

};