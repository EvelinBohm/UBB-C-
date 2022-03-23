#pragma once
#include"CrudRepos.h"
#include<fstream>
#include <string>
#include<sstream>
#include<iomanip> 
#include<iostream>

#include <fstream>
using namespace std;
struct CarWithId {
	Car car;
	string id = car.get_model() + car.get_brand() + std::to_string(car.get_year_of_registration()) + std::to_string(car.get_kilometers() % 100) + std::to_string(car.get_price() + car.get_PS()) + std::to_string(car.get_fuel()[0]);
	CarWithId(string id, Car cars) {
		this->id = id;
		this->car = cars;
	}

};
class CarInMemoryRepository : public CrudRepos<Car>
{

private:
	std::vector<CarWithId> storage;
public:
	bool delete_entity(Car car);
	bool add_entity(Car car);
	bool update_entity(Car car_to_update, Car updated_car);
	std::vector<Car> return_storage();
	std::string load_from_file(std::string name);
	bool find_car(Car car);
	void update_file(std::string client_name, Car car);
	bool does_file_exist(string fileName);
	CarWithId make_id(Car car);
	void update_file_storage(std::string name);



};