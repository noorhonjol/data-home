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
	Car(const char*brand,const char*date,int numdoors,const char*engine):Vehicle(date,brand) {
        fillString(engineType,engine);
        numDoors = numdoors;
    }
	Car() :Vehicle() {

		numDoors = -1;
        fillString(engineType,"Not Initialized");
	}
	~Car(){}
	friend ostream& operator<<(ostream& out, Car obj) {
		obj.PrintAsVehicle();
		cout << ", Number of Doors: "<< obj.numDoors<<" , ";
		cout << "Engine Type: "; printf("%s\n", obj.engineType);
		return out;
	}
	bool operator==(const Car& obj) {
		return CheckIfEqualAsVehicle(obj) && strcmp(engineType, obj.engineType) != 0 && numDoors==obj.numDoors;

	}
	Car operator+=(int increament) {
        increamentAsVehicle(increament);
		return *this;
	}
	Car& operator=(const char* date) {
		Car temp(getbrand(), date, numDoors, engineType);
		*this = temp;
		return *this;
	}
};


#endif //DATA_HOME_CAR_H
