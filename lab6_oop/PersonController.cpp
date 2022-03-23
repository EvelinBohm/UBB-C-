#include "PersonController.h"
#include "Person.h"
#include <iostream>
#include<exception>

PersonController::PersonController() {

}
//Verknuepft den Controller mit der add Methode aus dem Repository
void PersonController::add_person(std::string firstName, std::string lastName) {
	repository.add_entity(firstName, lastName);

}

//Verknuepft den Controller mit der add_to_favorite Methode aus dem Repository
bool PersonController::add_to_favorite_list(Person person, Car car_to_be_added_to_list) {

	return repository.update(person, car_to_be_added_to_list);
}
// ueberprueft ob ein schon bereits einfeguftes Auto in der Liste existiert
bool PersonController::check_if_car_is_in_favorite(string fileName, Car car) {
	int offset;
	ifstream Myfile;
	string line;
	Myfile.open(fileName);
	int year = car.get_year_of_registration();
	string years = to_string(year);
	int kilo = car.get_kilometers();
	string kilos = to_string(kilo);
	int preis = car.get_price();
	string preiss = to_string(preis);
	int ps = car.get_PS();
	string pss = to_string(ps);
	string carName = car.get_model() + "," + car.get_brand() + "," + years + "," + kilos + "," + preiss + "," + pss + "," + car.get_fuel();
	while (!Myfile.eof())
	{
		getline(Myfile, line);
		if ((offset = line.find(carName, 0)) != string::npos)
		{
			Myfile.close();
			return true;
		}
	}
	return false;
}
//gibt die Liste zurueck
std::vector<Person> PersonController::return_list()
{
	return repository.return_list();
}

void PersonController::print() {
	for (auto it2 : return_list()) {
		std::cout << it2.get_firstName() << " " << it2.get_lastName() << " ";
		for (auto it : it2.get_list()) {
			std::cout << "Modell: " << it.get_model() << ", " << "Brand: " << it.get_brand() << ", " << "Year of registration: " << it.get_year_of_registration() << ", " << "Kilometer: " << it.get_kilometers() << ", " << "Price: " << it.get_price() << ", " << "PS: " << it.get_PS() << ", " << "Fuel: " << it.get_fuel();
			std::cout << std::endl;
		}
	}
}