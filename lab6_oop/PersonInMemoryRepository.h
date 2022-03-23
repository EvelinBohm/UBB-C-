#pragma once
#include"CrudRepos.h"
#include"Person.h"
#include <iostream>

class PersonInMemoryRepository // public CrudRepos<Person>
{
private:
	std::vector<Person> list;
public:
	void add_entity(std::string firstName, std::string lastName);
	bool update(Person person, Car car_to_be_added_to_list);
	std::vector<Person> return_list();


};