#include <iostream>

using namespace std;

class Product
{
	int id;
	char* name;
	char* description;
	double price;
	double* priceHistory;
	int priceHistorySize;		// cannot use .size() on const double* pointer

public:
	Product(int _id, const char* _name, const char* _description, double _price, const double* _priceHistory, int _priceHistorySize) :
		id(_id), price(_price), priceHistorySize(_priceHistorySize)
	{


	}

	//all setters
	void set_id(int _id) {

		this->id = _id;
	}

	void set_name(const char* _name) {

		if (this->name != nullptr) {
			delete[] this->name;
		}

		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}

	void set_description(const char* _description) {

		if (this->description != nullptr) {
			delete[] this->description;
		}

		this->description = new char[strlen(_description) + 1];
		strcpy_s(this->description, strlen(_description) + 1, _description);
	}

	void set_price(double _price, const double* _priceHistory, int _priceHistorySize) {

		if (this->price != _price) {
			this->price = _price;
		}
		
		if (this->priceHistory != nullptr) {
			delete[] this->priceHistory;
		}

		this->priceHistory = new double[_priceHistorySize + 1];
		for (int i = 0; i <= _priceHistorySize; i++) {
			this->priceHistory[i + 1] = _priceHistory[i];
		}
		this->priceHistory[0] = this->price;
	}

	//all getters
	int get_id() {

		return this->id;
	}

	char* get_name() {

		if (this->name == nullptr) {
			return nullptr;
		}

		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);

		return copy;
	}

	char* get_description() {

		if (this->description == nullptr) {
			return nullptr;
		}

		char* copy = new char[strlen(this->description) + 1];
		strcpy_s(copy, strlen(this->description) + 1, this->description);

		return copy;
	}

	double getPriceAverage()
	{

	}

	~Product()
	{

	}
};