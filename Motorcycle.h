#ifndef DATA_HOME_MOTORCYCLE_H
#define DATA_HOME_MOTORCYCLE_H
#include "Vehicle.h"
class Motorcycle :public Vehicle {
private :
	char* Type;
	char* Color;
public  :
	Motorcycle(char*brand,char*date,char*type,char*color):Vehicle(date,brand) {
		Color = color;
		Type = type;
	}
	Motorcycle() :Vehicle() { Type = "Not Initialized"; Color = "Not Initialized"; }
	~Motorcycle() {
		
	}
	friend ostream& operator<<(ostream& out, Motorcycle obj) {
		obj.PrintAsVehicle();
		cout << ", Type: "; printf("%s ,", obj.Type);
		cout << "Color: "; printf("%s\n", obj.Color);
		return out;
	}
	bool operator==(Motorcycle obj) {
		return CheckIfEqualAsVehicle(obj) && strcmp(Color, obj.Color) && strcmp(Type , obj.Type);
		
	}
	Motorcycle operator+=(int increament){
		IncreamentAsVehicle(increament);
		return *this;
	}
};


#endif //DATA_HOME_MOTORCYCLE_H