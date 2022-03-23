#pragma once
#include"CrudRepos.h"
#include "PersonInMemoryRepository.h"
#include"Person.h"
#include <iostream>
#include <exception>


//fuegt eine Person in die Liste ein,falls die Person sich vorhanden ist dann wird false zuruckgegeben(die Methode wird mit hilfe der abstrakten Methoden aus dem CrudRepos erstellt)
void PersonInMemoryRepository::add_entity(std::string firstName, std::string lastName)
{
	int ok = 0;
	for (auto it : list) {
		if (it.get_firstName() == firstName && it.get_lastName() == lastName)
			ok = 1;
	}
	if (ok == 1) {

	}
	else {
		std::vector<Car> favorite = {};
		Person person(firstName, lastName, favorite);
		list.push_back(person);


	}
}

//verandert eine Person aus der Liste,falls das Auto sich nicht in der Liste befindet dann wird false zuruckgegeben(die Methode wird mit hilfe der abstrakten Methoden aus dem CrudRepos erstellt)
bool PersonInMemoryRepository::update(Person person, Car car_to_be_added_to_list)
{
	for (Person& person1 : list) {
		if (person1.get_firstName() == person.get_firstName() && person1.get_lastName() == person.get_lastName()) {
			person1.add_to_favorite(car_to_be_added_to_list);
			return true;

		}
	}
	return false;
}

std::vector<Person> PersonInMemoryRepository::return_list()
{
	return list;
}

