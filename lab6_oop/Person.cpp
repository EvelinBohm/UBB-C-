#include "Person.h"
#include <iostream>
//Konstructor
Person::Person(std::string firstName, std::string lastName, std::vector<Car>favorite_list)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->favorite_list = favorite_list;
}
//getter
std::string Person::get_firstName() {
	return firstName;
}
std::string Person::get_lastName() {
	return lastName;
}
std::vector<Car> Person::get_list() {
	return favorite_list;
}
//setter
void Person::set_firstName(std::string new_name)
{
	this->firstName = new_name;
}
void Person::set_lastName(std::string new_name)
{
	this->lastName = new_name;
}

void Person::add_to_favorite(Car car) {
	this->favorite_list.push_back(car);
}

