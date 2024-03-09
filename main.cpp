#include <iostream>
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"
using namespace std;
int main() {
	Car car("Toyota", "10/5/2022", 4, "V6");
	Motorcycle bike("Harley-Davidson", "15/8/2021", "Cruiser", "Black");
	std::cout << "Car Info: " << car << std::endl;
	std::cout << "Motorcycle Info: " << bike << std::endl;
	// Assigning from constant strings for date
	car = "1/1/2023";
	bike = "20/9/2022";
	std::cout << "Updated Car Info: " << car << std::endl;
	std::cout << "Updated Motorcycle Info: " << bike << std::endl;
}
