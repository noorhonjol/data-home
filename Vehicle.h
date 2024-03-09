
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

	Vehicle(const char* date,const char* brand) {
		ManufatureDate.fillDate(date);
        fillString(Brand,brand);
	}

	Vehicle() {
        ManufatureDate.putDefault();
        fillString(Brand,"Not Initialized");
    };
	~Vehicle() {
        //aa
    };

	friend ostream& operator<<(ostream&out,Vehicle obj){
		obj.PrintAsVehicle();
		return out;
	}

	bool operator==(const Vehicle& obj) {
		return CheckIfEqualAsVehicle(obj);
	}

	Vehicle operator++(int) {
		Vehicle temp = *this;
        increamentAsVehicle(1);
		return temp;
	}
	Vehicle operator++() {
        increamentAsVehicle(1);
		return *this;
	}
	void PrintAsVehicle() {
		printf("Brand: %s", Brand);
		cout << ", Manufaturing Date: " << ManufatureDate;
		
	};
	bool CheckIfEqualAsVehicle(const Vehicle& obj) {
		
		return strcmp(this->Brand, obj.Brand) != 0 && this->ManufatureDate == obj.ManufatureDate;
		
	}
	void increamentAsVehicle(int add) {
		
		ManufatureDate.year += add;
	}
	char* getbrand() {
        return Brand;
    }
	void operator=(const char* date) {
        strcpy(Brand,date);
	}
protected:
    void fillString(char *& toFillMessage,const char *str){
        const unsigned long long msgLen=strlen(str)+1;
        toFillMessage=new char[msgLen];
        strcpy(toFillMessage,str);
    }

};


#endif //DATA_HOME_VEHICLE_H
