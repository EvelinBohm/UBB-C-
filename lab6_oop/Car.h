#pragma once
#include<string>

class Car
{

private:
	std::string model;
	std::string brand;
	unsigned int year_of_registration;
	int kilometers;
	int price;
	unsigned int PS;
	std::string fuel;
public:
	Car(std::string model, std::string brand, unsigned int year_of_registration, int kilometers, int price, unsigned int PS, std::string fuel);
	Car();
	~Car() {};
	Car(const Car& other) {
		this->model = other.model;
		this->brand = other.brand;
		this->year_of_registration = other.year_of_registration;
		this->kilometers = other.kilometers;
		this->price = other.price;
		this->PS = other.PS;
		this->fuel = other.fuel;
	}
	std::string get_model();
	void set_model(std::string new_model);
	std::string get_brand();
	void set_brand(std::string new_brand);
	unsigned int get_year_of_registration();
	void set_year_of_registration(unsigned int new_year_of_registration);
	int get_kilometers();
	void set_kilometers(int new_km);
	int  get_price();
	void set_price(int new_price);
	unsigned int get_PS();
	void set_PS(unsigned int PS);
	std::string get_fuel();
	void set_fuel(std::string new_fuel);
	bool operator==(const Car& car) const;
	bool operator!=(const Car& car) const;






};
