#pragma once
#include"PersonInMemoryRepository.h"
#include "CarController.h"

#include<memory>
#include<vector>

class PersonController {
private:
	CarController carController;
	

public:
	PersonInMemoryRepository repository;
	PersonController();
	void add_person(std::string firstName, std::string lastName);
	bool add_to_favorite_list(Person person, Car car_to_be_added_to_list);
	bool check_if_car_is_in_favorite(string fileName, Car car);
	std::vector<Person> return_list();
	void print();
};