
#include <iostream>
#include "Date.h"
using namespace std;
#ifndef DATA_HOME_VEHICLE_H
#define DATA_HOME_VEHICLE_H
class Vehicle {
private :
	Date ManufatureDate;
	char* Brand;
public :
	
	Vehicle(Date date, char* brand) {
		ManufatureDate = date;
		Brand = brand;
	}
	Vehicle(char* date, char* brand) {
		ManufatureDate = date;
		Brand = brand;
	}
	Vehicle() { Brand = "Not initialized"; ManufatureDate = "1/1/2000"; };
	~Vehicle() {};
	friend ostream& operator<<(ostream&out,Vehicle obj){
		obj.PrintAsVehicle();
		return out;
	}
	bool operator==(Vehicle obj) {
		return CheckIfEqualAsVehicle(obj);
	}

	Vehicle operator++(int) {
		Vehicle temp = *this;
		IncreamentAsVehicle(1);
		return temp;
	}
	Vehicle operator++() {
		IncreamentAsVehicle(1);
		return *this;
	}
	void PrintAsVehicle() {
		printf("Brand: %s", Brand);
		cout << ", Manufaturing Date: " << ManufatureDate;
		
	};
	bool CheckIfEqualAsVehicle(Vehicle obj) {
		
		return strcmp(this->Brand, obj.Brand) && this->ManufatureDate == obj.ManufatureDate;
		
	}
	void IncreamentAsVehicle(int add) {
		
		ManufatureDate.year += add;
	}
	char* getbrand() { return Brand; }
	void operator=(char* date) {
		ManufatureDate = date;
	}
};


#endif //DATA_HOME_VEHICLE_H
