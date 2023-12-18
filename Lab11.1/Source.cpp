#include <iostream>
using namespace std;

class Product {

protected:
	string name = "";
	string description = "";
	double price = 0;

public:
	Product(string _name, string _description, double _price) 
		: name(_name), description(_description), price(_price) {}

	virtual string listDetails() {
		return "Product";
	}
};


class Electronics : public Product {

	int garant = 0;

public:
	Electronics(string _name, string _description, double _price, int _garant) 
		: Product(_name, _description, _price), garant(_garant) {}

	string listDetails() {
		return "Electronics";
	}
};


class Vehicles : public Product {

	int wheels = 0;

public:
	Vehicles(string _name, string _description, double _price, int _wheels)
		: Product(_name, _description, _price), wheels(_wheels) {}

	string listDetails() {
		return "Vehicles";
	}
};


int main() {

	Product** all = new Product * [3];
	Product* p = new Product("eraser", "pencil eraser", 2);
	Product* e = new Electronics("fridge", "kitchen fridge", 800, 2);
	Product* v = new Vehicles("car", "suv", 20000, 4);

	all[0] = p;
	all[1] = e;
	all[2] = v;

	for (int i = 0; i < 3; i++) {
		cout << endl << all[i]->listDetails() << endl;
	}
}