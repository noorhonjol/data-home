//
// Created by Amroh on 3/9/2024.
//
#include <iostream>
using namespace std;
#ifndef DATA_HOME_VEHICLE_H
#define DATA_HOME_VEHICLE_H

struct Date{
	Date operator=(char*a){}
};
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
		printf("%s\t", obj.Brand);
		cout << obj.ManufatureDate;
	}

};


#endif //DATA_HOME_VEHICLE_H
