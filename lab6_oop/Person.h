#pragma once
#include "Car.h"
#include <string>
#include <vector>
class Person
{
private:
	std::string firstName;
	std::string lastName;
	std::vector<Car>favorite_list;

public:

	Person(std::string firstName, std::string lastName, std::vector<Car>favorite_list);
	std::string get_firstName();
	void set_firstName(std::string new_name);
	std::string get_lastName();
	void set_lastName(std::string new_name);
	void add_to_favorite(Car car);
	std::vector<Car> get_list();

	//~Person();


};