//
// Created by Amroh on 3/9/2024.
//

#ifndef DATA_HOME_CAR_H
#define DATA_HOME_CAR_H

#include "Vehicle.h"

class Car:public Vehicle {
private :
	int numDoors;
	char* engineType;
public :
	Car(char*brand,char*date,int numdoors,char*engine):Vehicle(date,brand) {
		numDoors = numdoors;
		engineType = engine;
	}
	Car() :Vehicle() {
		numDoors = -1;
		engineType = "Not Initialized";
	}
	~Car(){}
	friend ostream& operator<<(ostream& out, Car obj) {
		obj.PrintAsVehicle();
		cout << ", Number of Doors: "<< obj.numDoors<<" , ";
		cout << "Engine Type: "; printf("%s\n", obj.engineType);
		return out;
	}
	bool operator==(Car obj) {
		return CheckIfEqualAsVehicle(obj) && strcmp(engineType, obj.engineType) && numDoors==obj.numDoors);

	}
	Car operator+=(int increament) {
		IncreamentAsVehicle(increament);
		return *this;
	}
	Car operator=(char* date) {
		Car temp(getbrand(), date, numDoors, engineType);
		*this = temp;
		return *this;
	}
};


#endif //DATA_HOME_CAR_H
