
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
	~Vehicle() { delete(Brand); };
	friend ostream& operator<<(ostream&out,Vehicle obj){
		printf("Brand: %s", obj.Brand);
		cout <<", Manufaturing Date: " << obj.ManufatureDate;
	}
	bool operator==(Vehicle obj) {
		if (this->Brand == obj.Brand && this->ManufatureDate == obj.ManufatureDate)return 1;
		return 0;
	}

	Vehicle operator++() {
		this->ManufatureDate.year++;
		return *this;
	}
	void PrintAsVehicle() {
		//because we cannot call the overload of << in the derived classes directly
		cout << *this;
	};
	bool CheckIfEqualAsVehicle(Vehicle obj) {
		//same with the print .. we cannot check the values in overloading car/motorcycle == operator
		//nor can we use the overload we have in this ,, we leffy bena ya donya
		if (*this == obj)return 1;
		return 0;
	}
	void IncreamentAsVehicle(int add) {
		//we . cannot . use . ++ . operator . inside . the . inhirited . classes . :D
		ManufatureDate.year += add;
	}
	void operator=(char* date) {
		ManufatureDate = date;
	}
};


#endif //DATA_HOME_VEHICLE_H
