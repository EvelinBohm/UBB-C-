#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"     
#define BOLDBLUE    "\033[1m\033[34m"    
#define BOLDMAGENTA "\033[1m\033[35m" 
#define RESET   "\033[0m"
#include "UI.h"
#include <iostream>
#include<typeinfo>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//der Lager wird mit Autos initializiert
UI::UI() {
	string file_name = controller.repo.load_from_file("C:\\Users\\Bohm Evelin\\source\\repos\\lab6_oop\\lab6_oop\\cars.csv");


}

string UI::read_name_client() {
	string firstName;
	string lastName;
	cout << BOLDBLUE << "Please enter your first name: " << RESET;
	firstName = read_string();
	cout << BOLDBLUE << "Please enter your last name: " << RESET;
	lastName = read_string();
	firstName = firstName + "_" + lastName + ".csv";
	return firstName;
}

void UI::make_file_for_client(string name) {
	person_controller.add_person(get_firstName(name), get_lastName(name));

	if (repository.does_file_exist(name) == false) {
		ofstream outFile;
		outFile.open(name.c_str());
		outFile.close();
	}
}

string UI::get_firstName(string name) {
	string delimit = "_";
	int pos = name.find(delimit);
	if (pos != std::string::npos) {
		return name.substr(0, pos);
	}
}
string UI::get_lastName(string name) {
	string delimit = "_";
	string delimit2 = ".";
	int pos = name.find(delimit);
	int pos2 = name.find(delimit2);
	int count = pos2 - pos - 1;
	if (pos != std::string::npos) {
		return name.substr(pos + 1, count);
	}
}
//Methode die den Benuzter seine Roller auswaehlen laesst
void UI::choose_menu() {
	int option;
	cout << BOLDMAGENTA << "Choose:" << RESET << endl;
	cout << "1. MANAGER" << endl;
	cout << "2. Client" << endl;
	cout << BOLDMAGENTA << "Your option is: " << RESET;
	option = read_int();
	int ok = 0;
	while (ok == 0) {
		if (option == 1) {
			read_options_manager();
			break;

		}
		if (option == 2) {
			string client_name = read_name_client();
			make_file_for_client(client_name);
			read_options_kunde(client_name);
			break;

		}
		else {
			cout << BOLDMAGENTA << "Enter 1 or 2. " << RESET;
			option = read_int();

		}
	}
}
//das Menu fuer den Manager
void UI::show_manager_menu() {
	cout << BOLDMAGENTA << "The options are:" << RESET << endl;
	cout << "0. Exit." << endl;
	cout << "1. Add car." << endl;
	cout << "2. Delete car." << endl;
	cout << "3. Change car properties." << endl;
	cout << "4. Print list of cars" << endl;
	cout << "5. Find car." << endl;
	cout << "6. Filter car." << endl;
	cout << "7. Sorted cars by price." << endl;
	cout << "8. Back." << endl;

}

// das Menu fuer den Kunden
void UI::show_kunde_menu() {
	cout << BOLDMAGENTA << "The options are:" << RESET << endl;
	cout << "0. Exit" << endl;
	cout << "1. Find car." << endl;
	cout << "2. Filter car." << endl;
	cout << "3. Sorted cars by price." << endl;
	cout << "4. Add to favourites." << endl;
	cout << "5. Print favourites." << endl;
	cout << "6. Print list of cars." << endl;
	cout << "7. Back." << endl;
}
//Die Optionen fuer den Manager
void UI::read_options_manager() {
	show_manager_menu();
	int option;
	cout << BOLDMAGENTA << "Your option is: " << RESET;
	option = read_int();
	while (option != 0) {
		if (option == 1) {
			option_1();
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
		if (option == 2) {
			option_2();
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
		if (option == 3) {
			option_3();
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}

		if (option == 4) {
			option_4();
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
		if (option == 5) {
			option_5();
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
		if (option == 6) {
			option_6();
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
		if (option == 7) {
			option_7();
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
		if (option == 8) {
			choose_menu();
			break;
		}
		if (option != 0 && option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7 && option != 8) {
			cout << BOLDMAGENTA << "Invalid option" << RESET << endl;
			show_manager_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}

	}
}

//Die Optionen fuer den Kunden
void UI::read_options_kunde(string client_name) {
	show_kunde_menu();
	int option;
	cout << BOLDMAGENTA << "Your option is:" << RESET;
	option = read_int();
	while (option != 0) {
		if (option == 1) {
			option_5();
			show_kunde_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();

		}
		if (option == 2) {
			option_6();
			show_kunde_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();

		}
		if (option == 3) {
			option_7();
			show_kunde_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();

		}
		if (option == 4) {
			option_8(client_name);
			show_kunde_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();

		}
		if (option == 5) {
			option_9(client_name);
			show_kunde_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();

		}
		if (option == 6) {
			option_4();
			show_kunde_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
		if (option == 7) {
			choose_menu();
			break;
		}
		if (option != 0 && option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7) {
			cout << BOLDMAGENTA << "Invalid option" << RESET << endl;
			show_kunde_menu();
			cout << BOLDMAGENTA << "Your option is: " << RESET;
			option = read_int();
		}
	}
}

// Option1 fuegt ein Auto ins Lager ein
void UI::option_1() {
	Car car1 = read_car();
	if (controller.add_car(car1, "cars.csv") == true) {
		cout << BOLDGREEN << "Car added." << RESET << endl;
		//controller.repo.update_file_storage();
	}
	else
		cout << BOLDMAGENTA << "Car not found." << RESET << endl;
}

//Option2 loest ein Auto aus dem Lager
void UI::option_2() {
	Car car2 = read_car();
	if (controller.delete_car(car2, "cars.csv") == true) {
		cout << BOLDGREEN << "Car deleted." << RESET << endl;
		
		//controller.repo.update_file_storage();
	}
	else
		cout << BOLDMAGENTA << "Car not found." << RESET << endl;
}


void UI::option_3()
{
	cout << BOLDBLUE << "Please enter the the following data of the product you want to edit:\n" << RESET;
	Car car = read_car();
	if (repository.find_car(car) == false) {
		cout << BOLDMAGENTA << "Car not found" << RESET << endl;
		return;
	}
	cout << BOLDGREEN << "Please enter the new information about the car:\n" << RESET;
	Car updated_car = read_car_for_update();
	
	if (updated_car.get_model() == "")
	{
		updated_car.set_model(car.get_model());
	}
	if (updated_car.get_brand() == "")
	{
		updated_car.set_brand(car.get_brand());
	}
	if (updated_car.get_year_of_registration() == -1)
	{
		updated_car.set_year_of_registration(car.get_year_of_registration());
	}
	if (updated_car.get_kilometers() == -1)
	{
		updated_car.set_kilometers(car.get_kilometers());
	}
	if (updated_car.get_price() == -1)
	{
		updated_car.set_price(car.get_price());
	}
	if (updated_car.get_PS() == -1)
	{
		updated_car.set_PS(car.get_PS());
	}
	if (updated_car.get_fuel() == "")
	{
		updated_car.set_fuel(car.get_fuel());
	}
	if (controller.update(car, updated_car, "cars.csv") == true)
	{
		controller.repo.update_entity(car, updated_car);
		cout << BOLDGREEN << "Property modified." << RESET << endl;
	}
		
	
	

}




//drueckt den Inhalt des Lagers aus
void UI::option_4() {
	print(controller.get_all());
}

//Verknupft den UI mit der Methode aus dem Controller, der fuer das Lager nach dem  Modellnamen/Markennamen filtert 
void UI::option_5() {
	cout << BOLDBLUE << "Search after Modell or Brand? " << RESET;
	string option;
	int ok = 0;
	option = read_string();
	while (ok == 0) {
		if (option == "Modell") {
			cout << "Enter Modell: ";
			string modell;
			cin >> modell;
			if (controller.search_car_after_model(modell).size() != 0)
				print(controller.search_car_after_model(modell));
			ok = 1;
		}
		else
			if (option == "Brand") {
				cout << "Enter Brand: ";
				string brand = read_string();
				if (controller.search_car_after_brand(brand).size() != 0)
					print(controller.search_car_after_brand(brand));
				ok = 1;
			}
			else {
				cout << BOLDMAGENTA << "Enter Modell or Brand: " << RESET;
				option = read_string();
			}
	}
}
//Verknupft den UI mit der Methode aus dem Controller, der fuer das Lager nach dem  km/ Erstzulassungsjahr filtert 
void UI::option_6() {
	cout << "Filter after km or year: ";
	int ok = 0;
	string option = read_string();
	while (ok == 0) {
		if (option == "km") {
			cout << "Show cars with kilometers below: ";
			int km = read_int();
			if (controller.filter_after_km(km).size() != 0) {
				print(controller.filter_after_km(km));

			}
			else {
				cout << BOLDMAGENTA << "Can't find car for the given data" << RESET;
			}
			ok = 1;
		}
		else
			if (option == "year") {
				cout << "Show cars with year below: ";
				int year = read_int();
				if (controller.filter_after_year(year).size() != 0) {
					print(controller.filter_after_year(year));

				}
				else {
					cout << BOLDMAGENTA << "Cant't find car for the given data" << RESET;
				}
				ok = 1;

			}
			else {
				cout << BOLDMAGENTA << "Enter km or year: " << RESET;
				option = read_string();
			}
	}
}

//Verknupft den UI mit der Methode aus dem Controller, der fuer das Lager nach Preis sortiert  
void UI::option_7() {
	vector<Car> vektor = controller.sort_after_price();
	print(vektor);
	cout << endl;
}

//Verknupft den UI mit der Methode aus dem Controller, der fuer ein Auto in die favoriten Liste packt
void UI::option_8(string client_name) {
	option_4();
	cout << BOLDBLUE << "Enter car to be added to favourite list: " << RESET << endl;
	Car car = read_car();
	std::vector<Car> fav = {};
	Person person(get_firstName(client_name), get_lastName(client_name), fav);
	if (person_controller.check_if_car_is_in_favorite(client_name, car) == 0) {
		if (repository.find_car(car) == 1) {

			if (person_controller.add_to_favorite_list(person, car) == 1) {
				cout << BOLDGREEN << "Car added." << RESET << endl;
				repository.update_file(client_name, car);
			}
		}
		else
			cout << BOLDMAGENTA << "Car not found" << RESET << endl;
	}
	else {
		cout << BOLDMAGENTA << "Car was already added" << RESET << endl;
	}
}


//drueckt den Inhalt der favoriten Liste  aus
void UI::option_9(string client_name) {
	cout << BOLDBLUE << "Your favorites are:" << RESET << endl;

	std::fstream myfile;
	myfile.open(client_name, std::fstream::in);
	std::string line, modell, brand, fuel, string_year, string_km, string_price, string_PS;
	int year, price, km, ps;
	int i = 0;
	if (!myfile.is_open())
	{
		std::cout << "error\n";
	}
	while (std::getline(myfile, line)) {
		std::istringstream tokenizer(line);

		std::getline(tokenizer, modell, ',');
		std::getline(tokenizer, brand, ',');
		std::getline(tokenizer, string_year, ',');
		std::getline(tokenizer, string_km, ',');
		std::getline(tokenizer, string_price, ',');
		std::getline(tokenizer, string_PS, ',');
		std::getline(tokenizer, fuel);

		year = stoi(string_year);
		km = stoi(string_km);
		price = stoi(string_price);
		ps = stoi(string_PS);
		cout << BOLDYELLOW << "Modell: " << RESET << modell << ", " << BOLDYELLOW << "Brand: " << RESET << brand << ", " << BOLDYELLOW << "Year of registration: " << RESET << year << ", " << BOLDYELLOW << "Kilometer: " << RESET << km << ", " << BOLDYELLOW << "Price: " << RESET << price << ", " << BOLDYELLOW << "PS: " << RESET << ps << ", " << BOLDYELLOW << "Fuel: " << RESET << fuel << endl;
		
	}
}
// Methode der die Eingabedaten des Benutzers als ein Objekt der classe Auto interpretiert
Car UI::read_car() {
	cout << BOLDBLUE << "Modell of car: " << RESET;
	std::string model;
	std::string marke;
	int year;
	int kilo;
	int price;
	int ps;
	string fuel;
	cin >> model;
	cout << BOLDBLUE << "Brand of car: " << RESET;
	cin >> marke;
	cout << BOLDBLUE << "Year of registration: " << RESET;
	year = read_int();
	cout << BOLDBLUE << "Kilometers of car: " << RESET;
	kilo = read_int();
	cout << BOLDBLUE << "Price of car: " << RESET;
	price = read_int();
	cout << BOLDBLUE << "PS of car: " << RESET;
	ps = read_int();
	cout << BOLDBLUE << "Type of fuel: " << RESET;
	fuel = read_string();
	Car car1(model, marke, year, kilo, price, ps, fuel);
	return car1;
}
//liest car fur die Eingabe
Car UI::read_car_for_update() {
	cout << BOLDBLUE << "Modell of car: " << RESET;
	std::string model;
	std::string brand;
	std::string year_str;
	std::string km_str;
	std::string ps_str;
	std::string price_str;
	int year,new_year;
	int kilo;
	int price;
	int ps;
	string fuel;
	
	std::cin.ignore();
	std::getline(std::cin, model);
	if (model.length()==0)
	{
		model = "";
	}
	cout << BOLDBLUE << "Brand of car: " << RESET;
	std::cin.clear();
	std::getline(std::cin, brand);
	if (brand.length() == 0)
	{
		brand = "";
	}
	cout << BOLDBLUE << "Year of registration: " << RESET;
	std::cin.clear();
	std::getline(std::cin, year_str);
	if (year_str.length() == 0)
	{
		year = -1;
	}
	else
	{
		while (controller.check_int(year_str) == false)
		{
			cout << BOLDMAGENTA << "Invalid. Enter a number: " << RESET;
			cin >> year_str;
		}
		stringstream string_to_int(year_str);
		string_to_int >> year;
	}
	
	cout << BOLDBLUE << "Kilometers of car: " << RESET;
	std::cin.clear();
	std::getline(std::cin, km_str);
	if (km_str.length() == 0)
	{
		kilo= -1;
	}
	else
	{
		while (controller.check_int(km_str) == false)
		{
			cout << BOLDMAGENTA << "Invalid. Enter a number: " << RESET;
			cin >> km_str;
		}
		stringstream km_to_int(km_str);
		km_to_int >> kilo;
	}
	cout << BOLDBLUE << "Price of car: " << RESET;
	std::cin.clear();
	std::getline(std::cin, price_str);
	if (price_str.length() == 0)
	{
		price = -1;
	}
	else
	{
		while (controller.check_int(price_str) == false)
		{
			cout << BOLDMAGENTA << "Invalid. Enter a number: " << RESET;
			cin >> price_str;
		}
		stringstream price_to_int(price_str);
		price_to_int >> price;
	}
	cout << BOLDBLUE << "PS of car: " << RESET;
	std::cin.clear();
	std::getline(std::cin, ps_str);
	if (ps_str.length() == 0)
	{
		ps = -1;
	}
	else
	{
		while (controller.check_int(ps_str) == false)
		{
			cout << BOLDMAGENTA << "Invalid. Enter a number: " << RESET;
			cin >> ps_str;
		}
		stringstream ps_to_int(ps_str);
		ps_to_int >> ps;
	}
	cout << BOLDBLUE << "Type of fuel: " << RESET;
	std::cin.clear();
	std::getline(std::cin, fuel);
	if (fuel.length() == 0)
	{
		fuel = "";
	}
	Car car1(model, brand, year, kilo, price, ps, fuel);
	return car1;
}

// Methode der die Eingabedaten des Benutzers als ein Objekt der classe Auto interpretiert
string UI::read_string() { //read name und uberpruft ob es ein string ist
	string name;
	cin >> name;
	while (controller.check_string(name) == false)
	{
		cout << BOLDMAGENTA << "Invalid. Please enter string: " << RESET;
		cin >> name;
	}
	return name;
}


int UI::read_int() { //read Menge und uberpruft ob es ein int ist
	int integer;
	string integer_str;
	cin >> integer_str;

	while (controller.check_int(integer_str) == false)
	{
		cout << BOLDMAGENTA << "Invalid. Enter a number: " << RESET;
		cin >> integer_str;
	}
	stringstream string_to_int9(integer_str);
	string_to_int9 >> integer;
	return integer;

}
void UI::print(vector<Car> list) { //print ein vector
	for (auto it : list) {
		cout << BOLDYELLOW << "Modell: " << RESET << it.get_model() << ", " << BOLDYELLOW << "Brand: " << RESET << it.get_brand() << ", " << BOLDYELLOW << "Year of registration: " << RESET << it.get_year_of_registration() << ", " << BOLDYELLOW << "Kilometer: " << RESET << it.get_kilometers() << ", " << BOLDYELLOW << "Price: " << RESET << it.get_price() << ", " << BOLDYELLOW << "PS: " << RESET << it.get_PS() << ", " << BOLDYELLOW << "Fuel: " << RESET << it.get_fuel();
		cout << endl;
	}
}