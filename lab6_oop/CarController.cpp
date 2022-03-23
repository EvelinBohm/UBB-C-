#include"CarController.h"
#include<algorithm>
//Verknuepft den Controller mit der add Methode aus dem Repository
bool CarController::add_car(Car car,std::string filename)
{
	if (repo.add_entity(car) == true) 
	{
		repo.update_file_storage(filename);
		return true;
	}
	else
		return false;
}
//Verknuepft den Controller mit der loescg Methode aus dem Repository
bool CarController::delete_car(Car car, std::string filename)
{
	if (repo.delete_entity(car) == true)
	{
		repo.update_file_storage(filename);
		return true;
		
	}
	else
		return false;
}
//Verknuepft den Controller mit der veranderungs Methode aus dem Repository
bool CarController::update(Car car_to_update, Car updated_car, std::string filename)
{
	if (repo.update_entity(car_to_update, updated_car) == true)
	{
		repo.update_file_storage(filename);
		return true;
	}
	else
		return false;
}

// gibt eine Liste von Autos zurueck, die mit dem gegebenen Markennamen uebereinstimmen
std::vector<Car> CarController::search_car_after_brand(std::string brand_name)
{
	
	std::vector<Car> search_vector;
	std::vector<Car> storage = repo.return_storage();
	for (Car& current_produkt : storage) {

		if (brand_name.compare(current_produkt.get_brand()) == 0) {
			search_vector.push_back(current_produkt);

		}
	}
	return search_vector;
}
// gibt eine Liste von Autos zurueck, die mit dem gegebenen Modellnamen uebereinstimmen
std::vector<Car> CarController::search_car_after_model(std::string model_name)
{
	std::vector<Car> search_vector1;
	std::vector<Car> storage = repo.return_storage();
	for (Car& current_produkt : storage) {
		if (model_name.compare(current_produkt.get_model()) == 0) {
			search_vector1.push_back(current_produkt);

		}

	}
	return search_vector1;
}
// gibt eine Liste von Autos zurueck dessen Kilometerstand kleiner gleich einer gegebenen Zahl ist 
std::vector<Car>CarController::filter_after_km(int km) {


	std::vector<Car> filter_vector;
	std::vector<Car> storage = repo.return_storage();
	for (Car& current_produkt : storage) {
		if (current_produkt.get_kilometers() <= km) {
			filter_vector.push_back(current_produkt);

		}
	}
	return filter_vector;

}

// gibt eine Liste von Autos zurueck dessen Erstzulassungsjahr keliner gleich einer gegebenen Zahl ist 
std::vector<Car> CarController::filter_after_year(int year) {


	std::vector<Car> filter_vector1;
	std::vector<Car> storage = repo.return_storage();
	for (Car& current_produkt : storage) {
		if (current_produkt.get_year_of_registration() <= year) {
			filter_vector1.push_back(current_produkt);

		}
	}
	return filter_vector1;


}
bool function(Car auto1, Car auto2)
{
	return (auto1.get_price() < auto2.get_price());
}
//gibt eine nach Preis sortietre Liste von Autos zurueck
std::vector<Car> CarController::sort_after_price()
{
	std::vector<Car> vektor;
	std::vector<Car> storage = repo.return_storage();
	for (Car& current_produkt : storage) {
		vektor.push_back(current_produkt);
	}

	std::sort(vektor.begin(), vektor.end(), function);
	return vektor;
}

std::vector<Car>CarController::get_all(){
	return repo.return_storage();
};
//ueberpruft falls die gegebene Variable ein string ist
bool CarController::check_string(std::string string) {
	for (int i = 0; i < string.size(); i++)
		if (string[i] < 'A' || (string[i] > 'Z' && string[i] < 'a') || string[i]>'z')
			return false;
	return true;
}
//ueberpruft falls die  gegebene Varibale nur Zahlen enthalt
bool CarController::check_int(std::string number) {
	return (number.find_first_not_of("0123456789") == std::string::npos);
}
