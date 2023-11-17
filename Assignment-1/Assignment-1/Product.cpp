#include "Product.h"
#include "Utils.h"

Product::Product(int id, const char* name, const char* description, double price, const double* priceHistory, int priceHistoryLen)
{
	this->setId(id);
	this->setName(name);
	this->setDescription(description);
	this->setPrice(price);
	this->initPriceHistory(priceHistory, priceHistoryLen);
};

Product::Product(const Product& p)
{
	if (this == &p) return;
	this->setId(p.id);
	this->setName(p.name);
	this->setDescription(p.description);
	this->setPrice(p.price);
	this->initPriceHistory(p.priceHistory, p.priceHistoryLen);
}

void Product::setId(int id)
{
	this->id = id;
}

void Product::setName(const char* name)
{
	if (this->name != nullptr)
		delete[] this->name;

	if (name == nullptr)
	{
		this->name = nullptr;
		return;
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Product::setDescription(const char* description)
{
	if (this->description != nullptr)
		delete[] this->description;

	if (description == nullptr)
	{
		this->description = nullptr;
		return;
	}

	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);
}

void Product::setPrice(double price)
{
	double* pH = new double[this->priceHistoryLen + 1];
	for (int i = 0; i < this->priceHistoryLen; i++)
	{
		pH[i] = this->priceHistory[i];
	}
	pH[this->priceHistoryLen] = this->price;
	this->priceHistoryLen += 1;
	this->price = price;

	if(this->priceHistory != nullptr)
		delete[] this->priceHistory;
	this->priceHistory = pH;
}

void Product::initPriceHistory(const double* priceHistory, int priceHistoryLen)
{
	if (this->priceHistory != nullptr)
		delete[] this->priceHistory;

	if (priceHistory == nullptr)
	{
		this->priceHistory = nullptr;
		this->priceHistoryLen = 0;
		return;
	}
	this->priceHistoryLen = priceHistoryLen;
	this->priceHistory = new double[priceHistoryLen];
	for (int i = 0; i < priceHistoryLen; i++)
		this->priceHistory[i] = priceHistory[i];
}

int Product::getId() 
{
	return this->id; 
}

char* Product::getName()
{
	char* retName = new char[strlen(this->name) + 1];
	strcpy_s(retName, strlen(this->name) + 1, this->name);
	return retName;
}

char* Product::getDescription()
{
	char* retDescription = new char[strlen(this->description) + 1];
	strcpy_s(retDescription, strlen(this->description) + 1, this->description);
	return retDescription;
}

double Product::getPrice() 
{ 
	return this->price; 
}

double* Product::getPriceHistory()
{
	double* retPriceHistory = new double[this->priceHistoryLen];
	for (int i = 0; i < this->priceHistoryLen; i++)
		retPriceHistory[i] = this->priceHistory[i];
	return retPriceHistory;
}

int Product::getPriceHistoryLen() 
{ 
	return this->priceHistoryLen; 
}

double Product::getPriceAverage()
{
	double avg = 0;
	for (int i = 0; i < this->priceHistoryLen; i++)
	{
		avg += this->priceHistory[i];
	}

	avg += this->price;

	avg = avg / (this->priceHistoryLen + 1);
	return avg;
}

void Product::printPriceHistory()
{
	for (int i = 0; i < this->priceHistoryLen; i++)
		cout << this->priceHistory[i] << " ";
	cout << endl;
}

Product* Product::initializeProduct()
{
	int id = Utils::readIntFromConsole("Product ID:", 1, PRICE_MAX);
	char* name = Utils::readCharSTringFromConsole("Product name:", 2, 1024);
	char* description = Utils::readCharSTringFromConsole("Product description:", 10, 1024);
	double price = Utils::readDoubleFromConsole("Product price:", 0.001, 9999.9999);
	int priceHistoryLen = Utils::readIntFromConsole("Product price history count:", 1, INT_MAX);

	double* priceHistory = new double[priceHistoryLen];

	for (int i = 0; i < priceHistoryLen; i++)
	{
		priceHistory[i] = Utils::readDoubleFromConsole("Product price:", 0.001, 9999.9999);
	}

	Product* p = new Product(id, name, description, price, priceHistory, priceHistoryLen);
	
	return p;
}

Product::~Product()
{
	if (this->name != nullptr)
		delete[] this->name;

	if (this->description != nullptr)
		delete[] this->description;

	if (this->priceHistory != nullptr)
		delete[] this->priceHistory;
}

Product& Product::operator=(const Product& p)
{
	if (this == &p) return *this;
	this->setId(p.id);
	this->setName(p.name);
	this->setDescription(p.description);
	this->setPrice(p.price);
	this->initPriceHistory(p.priceHistory, p.priceHistoryLen);

	return *this;
}
