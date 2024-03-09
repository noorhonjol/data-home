#include <iostream>
#include "Vehicle.h"
#include "Motorcycle.h"
using namespace std;
int main() {
    Date b; 
    b = "1///2//2001";
    Vehicle a(b,"bmw");
    cout << a;
}
