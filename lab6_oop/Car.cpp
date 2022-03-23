#include "Car.h"

//Konstruktor
Car::Car(std::string model, std::string brand, unsigned int year_of_registration, int kilometers, int price, unsigned int PS, std::string fuel)
{
	this->model = model;
	this->brand = brand;
	this->year_of_registration = year_of_registration;
	this->kilometers = kilometers;
	this->price = price;
	this->PS = PS;
	this->fuel = fuel;
}
Car::Car()
{
	this->model = "";
	this->brand = "";
	this->year_of_registration = 0;
	this->kilometers = 0;
	this->price = 0;
	this->PS = 0;
	this->fuel = "";
}

//getter
std::string Car::get_model()
{
	return this->model;
}

std::string Car::get_brand()
{
	return this->brand;
}
unsigned int Car::get_year_of_registration()
{
	return this->year_of_registration;
}
int Car::get_kilometers()
{
	return this->kilometers;
}
int Car::get_price()
{
	return this->price;
}
unsigned int Car::get_PS()
{
	return this->PS;
}
std::string Car::get_fuel()
{
	return this->fuel;
}
//setter
void Car::set_model(std::string new_model)
{
	this->model = new_model;
}
void Car::set_brand(std::string new_brand)
{
	this->brand = new_brand;
}

void Car::set_year_of_registration(unsigned int year_of_registration)
{
	this->year_of_registration = year_of_registration;
}

void Car::set_kilometers(int km)
{
	this->kilometers = km;
}

void Car::set_price(int price)
{
	this->price = price;
}

void Car::set_PS(unsigned int PS)
{
	this->PS = PS;
}

void Car::set_fuel(std::string fuel)
{
	this->fuel = fuel;
}
//Overload
bool Car::operator==(const Car& car) const {
	if (car.brand != this->brand) {
		return false;
	}
	if (car.fuel != this->fuel) {
		return false;
	}
	if (car.kilometers != this->kilometers) {
		return false;
	}
	if (car.model != this->model) {
		return false;
	}
	if (car.price != this->price) {
		return false;
	}
	if (car.PS != this->PS) {
		return false;
	}
	if (car.year_of_registration != this->year_of_registration) {
		return false;
	}
	return true;
}
bool Car::operator!=(const Car& car) const {
	if (car.brand == this->brand) {
		return false;
	}
	if (car.fuel == this->fuel) {
		return false;
	}
	if (car.kilometers == this->kilometers) {
		return false;
	}
	if (car.model == this->model) {
		return false;
	}
	if (car.price == this->price) {
		return false;
	}
	if (car.PS == this->PS) {
		return false;
	}
	if (car.year_of_registration == this->year_of_registration) {
		return false;
	}
	return true;
}
