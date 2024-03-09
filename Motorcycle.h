#ifndef DATA_HOME_MOTORCYCLE_H
#define DATA_HOME_MOTORCYCLE_H
#include "Vehicle.h"
class Motorcycle :public Vehicle {
private :
	char* Type;
	char* Color;
public  :
	Motorcycle(char*brand,char*date,char*type,char*color):Vehicle(brand,date) {
		Color = color;
		Type = type;
	}
	Motorcycle() :Vehicle() { Type = "unknown"; Color = "unknown"; }
	~Motorcycle() {
		delete(Type);
		delete(Color);
	}
	friend ostream& operator<<(ostream& out, Motorcycle obj) {
		cout << "Motorcycle Info: "; obj.PrintAsVehicle();
		cout << ", Type: "; printf("%s ,", obj.Type);
		cout << ", Color: "; printf("%s\n", obj.Color);
		return out;
	}
	bool operator==(Motorcycle obj) {
		if (CheckIfEqualAsVehicle(obj) && Color == obj.Color && Type == obj.Type)return 1;
		return 0;
	}

};


#endif //DATA_HOME_MOTORCYCLE_H