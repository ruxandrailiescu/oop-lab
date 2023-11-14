#include <iostream>
#include <string>

using namespace std;

#define MAX_LEN 60		// can we not use this for input_instantiation()? - did not find alternative solution

class Product
{
	int id = -1;
	char* name = nullptr;
	char* description = nullptr;
	double price = -1;
	double* priceHistory = nullptr;
	int priceHistorySize = -1;		// cannot use .size() on const double* pointer

public:

	//constructor
	Product(int _id, const char* _name, const char* _description, double _price, const double* _priceHistory, int _priceHistorySize) : id(_id)
	{

		this->set_name(_name);
		this->set_description(_description);
		this->set_price(_price, _priceHistory, _priceHistorySize);

	}

	//copy constructor - must be implemented in order to correctly copy the attributes from one instance of the object to another
	//deep copy (default copy constructor will do a shallow copy => issues with destructor, both objects will point to the same memory location
	// => destructor will try to deallocate the same memory area twice => runtime exception
	Product(const Product& product) : Product(product.id, product.name, product.description, product.price, product.priceHistory, product.priceHistorySize) {

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

		this->priceHistory = new double[_priceHistorySize + 1];		// +1 for the new price to be added to priceHistory
		for (int i = 0; i < _priceHistorySize; i++) {
			this->priceHistory[i + 1] = _priceHistory[i];
		}

		this->priceHistory[0] = this->price;
		this->priceHistorySize = _priceHistorySize + 1;				// update priceHistorySize to reflect the new history
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

	double get_price() {

		return this->price;
	}

	double* get_price_history() {

		if (this->priceHistory == nullptr) {
			return nullptr;
		}

		double* copy = new double[this->priceHistorySize];
		for (int i = 0; i < this->priceHistorySize; i++) {
			copy[i] = this->priceHistory[i];
		}
		return copy;
	}

	// calculate average of prices
	double get_price_average()
	{
		double sum = 0;
		for (int i = 0; i < this->priceHistorySize; i++) {
			sum += this->priceHistory[i];
		}
		return sum / priceHistorySize;
	}

	//destructor
	~Product()
	{
		delete[] this->name;
		delete[] this->description;
		delete[] this->priceHistory;
		cout << endl << "Destructor called." << endl;
	}
};



//instantiate object using keyboard input - DOES NOT WORK PROPERLY FOR p_name, p_description, p_priceHistory
Product* input_instantiation() {

	//can we optimize this so we don't declare 
	//new variables identical to attributes of Product class?
	int p_id = -1;
	//string p_name = "";
	char p_name[MAX_LEN];
	//string p_description = "";
	char p_description[MAX_LEN];
	int p_price = -1;

	int p_priceHistorySize = -1;
	double* p_priceHistory = nullptr;

	cout << endl << "Enter product id: ";
	if (!(cin >> p_id)) {

		//input is not an integer - handle the error
		cerr << "Invalid input/error occurred." << endl;
		return nullptr;
	}


	//getline() method does not work as expected
	cout << endl << "Enter product name: ";
	cin.ignore();								//clear the newline character
//	if (!getline(cin, p_name)) {
	if(!cin.getline(p_name, MAX_LEN)) {

		cerr << "Invalid input/error occurred." << endl;
		return nullptr;
	}

	//getline() method does not work as expected
	cout << endl << "Enter product description: ";
//	if (!getline(cin, p_description)) {
	if(!cin.getline(p_description, MAX_LEN)) {

		cerr << "Invalid input/error occurred." << endl;
		return nullptr;
	}

	
	cout << endl << "Enter product price: ";
	if (!(cin >> p_price)) {

		cerr << "Invalid input/error occurred." << endl;
		return nullptr;
	}

	cout << endl << "Enter number of previous prices of the product: ";
	if (!(cin >> p_priceHistorySize)) {

		cerr << "Invalid input/error occurred." << endl;
		return nullptr;
	}

	p_priceHistory = new double[p_priceHistorySize];

	cout << endl << "Enter price history of the product (recent to oldest): ";
	for (int i = 0; i < p_priceHistorySize; i++) {
		cout << endl << "Enter price " << i + 1 << ": ";

		if (!(cin >> p_priceHistory[i])) {
			cerr << "Invalid input/error occurred." << endl;
			return nullptr;
		}
	}

	//call constructor to instantiate object
//	Product p_input(p_id, p_name.c_str(), p_description.c_str(), p_price, p_priceHistory, p_priceHistorySize);
	Product *p_input = new Product(p_id, p_name, p_description, p_price, p_priceHistory, p_priceHistorySize);

	delete[] p_priceHistory;
	return p_input;
}


int main() {

	// Memory should be deallocated in main after calling getters which return a pointer
	// (memory allocated for copies inside getters)

	int priceHistorySize = 3;
	double* priceHistory = new double[priceHistorySize];
	priceHistory[0] = 10.2;
	priceHistory[1] = 9.8;
	priceHistory[2] = 10.5;

	Product p1(1, "Baguette", "French baguette", 10.0, priceHistory, priceHistorySize);
	
	//testing copy constructor
	Product p2 = p1;

	//testing method using user input
	Product* p3 = input_instantiation();

	//testing method for calculating price average
	double priceAverage = p1.get_price_average();

	delete[] priceHistory;
}