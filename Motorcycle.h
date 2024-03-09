#ifndef DATA_HOME_MOTORCYCLE_H
#define DATA_HOME_MOTORCYCLE_H
#include "Vehicle.h"
class Motorcycle :public Vehicle {
private :
	char* Type;
	char* Color;
public  :
	Motorcycle(const char*brand,const char*date,const char*type,const char*color):Vehicle(date,brand) {
        fillString(Type,type);
        fillString(Color,color);

	}
	Motorcycle() :Vehicle() {
        fillString(Type,"Not Initialized");
        fillString(Type,"Not Initialized");
    }
	~Motorcycle() {
		
	}
	friend ostream& operator<<(ostream& out, Motorcycle obj) {
		obj.PrintAsVehicle();
		cout << ", Type: "; printf("%s ,", obj.Type);
		cout << "Color: "; printf("%s\n", obj.Color);
		return out;
	}
	bool operator==(Motorcycle obj) {
		return CheckIfEqualAsVehicle(obj) && strcmp(Color, obj.Color) != 0 && strcmp(Type , obj.Type) != 0;
		
	}
	Motorcycle operator+=(int increament){
        increamentAsVehicle(increament);
		return *this;
	}
	Motorcycle& operator=(const char* date) {
		Motorcycle temp(getbrand(), date,Type ,Color );
		*this = temp;
		return *this;
	}
};


#endif //DATA_HOME_MOTORCYCLE_H