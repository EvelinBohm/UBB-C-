#include "test.h"
#define BOLDGREEN   "\033[1m\033[32m"
#define RESET   "\033[0m"
/* die add Methode wird ueberprueft*/
void Tests::test_add()
{
	Car VW("Passat", "VW", 2017, 180122, 7222, 120, "Petrol");
	Car Audi("A3", "Audi", 2011, 171025, 4351, 106, "Diesel");
	Car Citroen("C3", "Citroen", 2019, 24222, 6751, 68, "Petrol");
	Car Dacia("Duster Laureate", "Dacia", 2011, 159416, 4151, 90, "Diesel");
	Car Mercedes("E-Class", "Mercedes-Benz", 2014, 197217, 9250, 136, "Diesel");
	Car Tesla("ModelS", "Tesla", 2018, 94126, 48721, 1020, "Electricity");
	Car Volvo("XC90", "Volvo", 2019, 36000, 40000, 235, "Petrol");
	Car Peugeot("508", "Peugeot", 2021, 1345, 19500, 170, "Diesel");
	Car Bentley("Bentayga", "Bentley", 2018, 5000, 156000, 550, "Petrol");
	Car Ford("Focus", "Ford", 2016, 136000, 7900, 110, "Diesel");
	Product_test.add_car(VW,"test.csv");
	Product_test.add_car(Audi, "test.csv");
	Product_test.add_car(Citroen,"test.csv");
	Product_test.add_car(Dacia, "test.csv");
	Product_test.add_car(Mercedes, "test.csv");
	Product_test.add_car(Tesla, "test.csv");
	Product_test.add_car(Volvo, "test.csv");
	Product_test.add_car(Peugeot, "test.csv");
	Product_test.add_car(Bentley, "test.csv");
	Product_test.add_car(Ford, "test.csv");
	int size = Product_test.get_all().size();
	assert(size == 10);
}
void Tests::test_getters() {
	// getters werden ueberprueft
	std::string model = Product_test.get_all()[0].get_model();
	assert(model == "Passat");
	std::string brand = Product_test.get_all()[0].get_brand();
	assert(brand == "VW");
	std::string fuel = Product_test.get_all()[0].get_fuel();
	assert(fuel == "Petrol");
	int km = Product_test.get_all()[0].get_kilometers();
	assert(km == 180122);
	int year = Product_test.get_all()[0].get_year_of_registration();
	assert(year == 2017);
	int price = Product_test.get_all()[0].get_price();
	assert(price == 7222);
	int ps = Product_test.get_all()[0].get_PS();
	assert(ps == 120);

}

/* die modify Methode wird ueberprueft*/
void Tests::test_modify() {
	Car car11("car3", "brand3", 2001, 20, 1200, 100, "Diesel");
	Car car12("car4", "brand3", 2004, 204, 1204, 104, "Petrol");
	Product_test.add_car(car11,"test.csv");
	Product_test.update(car11, car12,"test.csv");
	std::string model = Product_test.get_all()[10].get_model();
	assert(model == "car4");
	std::string brand = Product_test.get_all()[10].get_brand();
	assert(brand == "brand3");
	std::string fuel = Product_test.get_all()[10].get_fuel();
	assert(fuel == "Petrol");
	int km = Product_test.get_all()[10].get_kilometers();
	assert(km == 204);
	int year = Product_test.get_all()[10].get_year_of_registration();
	assert(year == 2004);
	int price = Product_test.get_all()[10].get_price();
	assert(price == 1204);
	int ps = Product_test.get_all()[10].get_PS();
	assert(ps == 104);
}
// die delete Methode wird getestet
void Tests::test_remove()
{
	Car car12("car4", "brand3", 2004, 204, 1204, 104, "Petrol");
	Product_test.delete_car(car12,"test.csv");
	assert(Product_test.get_all().size() == 10);

}
// die filter Methoden werden getestet
void Tests::test_filter() {
	std::vector<Car> list_of_cars_after_year;
	list_of_cars_after_year = Product_test.filter_after_year(2012);
	assert(list_of_cars_after_year.size() == 2);

	std::vector<Car> list_of_cars_after_km;
	list_of_cars_after_km = Product_test.filter_after_km(18000);
	assert(list_of_cars_after_km.size() == 2);
}

// die Such Methoden werden getestet
void Tests::test_search()
{
	Car Audi("A3", "Audi", 2011, 171025, 4351, 106, "Diesel");
	std::vector<Car>list_of_cars_with_wanted_brand;
	list_of_cars_with_wanted_brand = Product_test.search_car_after_brand("Audi");
	assert(list_of_cars_with_wanted_brand[0] == Audi);
	std::vector<Car>list_of_cars_with_wanted_model;
	list_of_cars_with_wanted_model = Product_test.search_car_after_model("A3");
	assert(list_of_cars_with_wanted_model[0] == Audi);

}
void Tests::test_sort()
{
	Car Dacia("Duster Laureate", "Dacia", 2011, 159416, 4151, 90, "Diesel");
	std::vector<Car>sort;
	sort = Product_test.sort_after_price();
	assert(sort[0] == Dacia);
	

}


//die add to favorite list Methode wird getestet
void Tests::test_add_to_favorite_list() {
	Car Audi("A3", "Audi", 2011, 171025, 4351, 106, "Diesel");
	std::vector<Car>list;
	Car VW("Passat", "VW", 2017, 180122, 7222, 120, "Petrol");
	Person test_p("test", "person",list);
	Person_test.add_to_favorite_list(test_p,Audi);
	assert(Person_test.return_list().size() == 0);
	std::cout << BOLDGREEN << "TESTS PASSED SUCCESSFULLY!" << RESET << std::endl;

	}
		