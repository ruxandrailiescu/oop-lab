#pragma once
#include <iostream>
using namespace std;

#define PRICE_MAX 99999.9999999
#define ID_MAX	  INT_MAX

class Product
{
	int id = -1;
	char* name = nullptr;
	char* description = nullptr;
	double price = 0.0;
	double* priceHistory = nullptr;
	int priceHistoryLen = 0;

	void initPriceHistory(const double* priceHistory, int priceHistoryLen);
public:
	Product(int id, const char* name, const char* description, double price, const double* priceHistory, int priceHistoryLen);
	Product(const Product& p);
	void setId(int id);
	void setName(const char* name);
	void setDescription(const char* description);
	void setPrice(double price);

	int getId();
	char* getName();
	char* getDescription();
	double getPrice();
	double* getPriceHistory();
	int getPriceHistoryLen();
	double getPriceAverage();
	void printPriceHistory();
	static Product* initializeProduct();

	Product& operator=(const Product& p);

	~Product();
};