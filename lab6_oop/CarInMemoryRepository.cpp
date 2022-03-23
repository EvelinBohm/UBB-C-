#include "CarInMemoryRepository.h"
#include<algorithm>


//loescht ein Auto aus der Liste,falls das Auto sich nicht in der Liste befindet dann wird false zuruckgegeben(die Methode wird mit hilfe der abstrakten Methoden aus dem CrudRepos erstellt)
bool CarInMemoryRepository::delete_entity(Car car)
{
	for (auto it = storage.begin(); it != storage.end(); it++)
	{
		int index = it - storage.begin();
		CarWithId current_auto = storage.at(index);
		if (current_auto.car == car)
		{
			storage.erase(it);
			return true;
		}
	}
	return false;
}
// Fuegt ein Auto hinzu,falls das Auto schon in der Liste existiert, wird die Einfuegeoperation ignoriert(die Methode wird mit hilfe der abstrakten Methoden aus dem CrudRepos erstellt)
bool CarInMemoryRepository::add_entity(Car car)
{


	CarWithId cars = make_id(car);
	for (CarWithId& current_produkt : storage) {
		if ((current_produkt.id) == cars.id) {
			return false;

		}
	}

	storage.push_back(cars);
	return true;
}
//veraendert den die Atribute des gegeben Autos,falls das Auto sich nicht in der Liste befindet dann wird false zuruckgegeben(die Methode wird mit hilfe der abstrakten Methoden aus dem CrudRepos erstellt)
bool CarInMemoryRepository::update_entity(Car car_to_update, Car updated_car)

{
	for (CarWithId& current_produkt : storage) {
		if ((current_produkt.car) == (car_to_update)) {
			current_produkt.car.set_model(updated_car.get_model());
			current_produkt.car.set_brand(updated_car.get_brand());
			current_produkt.car.set_year_of_registration(updated_car.get_year_of_registration());
			current_produkt.car.set_kilometers(updated_car.get_kilometers());
			current_produkt.car.set_price(updated_car.get_price());
			current_produkt.car.set_PS(updated_car.get_PS());
			current_produkt.car.set_fuel(updated_car.get_fuel());
			return true;
		}
	}

	return false;
}

//gibt den Inhalt des Lagers zurueck
std::vector<Car> CarInMemoryRepository::return_storage()
{
	std::vector<Car> vektor;
	for (CarWithId& current_produkt : storage) {
		vektor.push_back(current_produkt.car);
	}

	return vektor;
}
//liest die Daten vom der Datei
std::string CarInMemoryRepository::load_from_file(string name)
{
	//string name = "cars.csv";
	std::fstream myfile;
	myfile.open(name, std::fstream::in);
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
		Car car(modell, brand, year, km, price, ps, fuel);
		if (add_entity(car) == true) {
			add_entity(car);
		}
	}
	return name;
}

//fugt ein auto hinzu
void CarInMemoryRepository::update_file(std::string name, Car car)
{
	ofstream outFile;
	outFile.open(name.c_str(), std::ios_base::app);
	outFile << car.get_model() << "," << car.get_brand() << "," << car.get_year_of_registration() << "," << car.get_kilometers() << "," << car.get_price() << "," << car.get_PS() << "," << car.get_fuel() << endl;

}

//ueberprueft ob die Datei existiert
bool CarInMemoryRepository::does_file_exist(string fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}

//sucht nach einem Auto
bool CarInMemoryRepository::find_car(Car car) {
	for (auto it : storage) {
		if (it.car == car) {
			return true;
		}
	}
	return false;

}
// erstellt eine kuenstliche ID
CarWithId CarInMemoryRepository::make_id(Car car) {
	string id = car.get_model() + car.get_brand() + std::to_string(car.get_year_of_registration()) + std::to_string(car.get_kilometers() % 100) + std::to_string(car.get_price() + car.get_PS()) + std::to_string(car.get_fuel()[0]);
	CarWithId cars(id, car);
	return cars;
}
// ersetzt die alte Datei mit der Neuen, die schon bearbeitet wurde
void CarInMemoryRepository::update_file_storage(std::string name)
{
	std::ofstream updatedFile;
	updatedFile.open("temp.csv", std::ios_base::app);
	for (auto car : storage)
	{
		updatedFile << car.car.get_model() << "," << car.car.get_brand() << "," << car.car.get_year_of_registration() << "," << car.car.get_kilometers() << "," << car.car.get_price() << "," << car.car.get_PS() << "," << car.car.get_fuel() << endl;
	}
	updatedFile.close();
	remove(name.c_str());
	rename("temp.csv", name.c_str());
	return;

}