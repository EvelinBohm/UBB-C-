#pragma once
#include"CarInMemoryRepository.h"
#include<memory>

class CarController
{

public:
	CarInMemoryRepository repo;
	CarController() {};
	std::vector<Car> search_car_after_model(std::string model_name);
	std::vector<Car> search_car_after_brand(std::string brand_name);
	std::vector<Car> filter_after_km(int km);
    std::vector<Car> filter_after_year(int year);
	std::vector<Car>sort_after_price();
	bool add_car(Car car,std::string filename);
	bool delete_car(Car car, std::string filename);
	bool update(Car car_to_update, Car updated_car, std::string filename);
	void load_from_file(std::string name)
	{
		repo.load_from_file(name);
	}
	void print(std::vector<Car> list);
	std::vector<Car> get_all();
	bool check_string(std::string string);
	bool check_int(std::string number);
};