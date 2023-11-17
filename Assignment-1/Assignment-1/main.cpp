#include "Product.h"

int main()
{
	double p1PriceHistory[3] = { 19.0, 21.3, 25.4 };

	//constructor with params
	Product p1(1, "produs 1", "descriere produs 1", 22.4, p1PriceHistory, 3);

	// copy constructor
	Product p2 = p1;

	// necessity of copy constructor
	p2.setName("new name");

	// copy constructor
	Product p3 = p1;

	// operator =
	p3 = p2;

	// avg. price method call
	cout << "p1 avg. price: " << p1.getPriceAverage() << endl;

	// initialize product with values read from console
	Product* p4 = Product::initializeProduct();
	// check if setPrice adds old price to price history
	p4->printPriceHistory();
	p4->setPrice(5.55);
	p4->printPriceHistory();


	return 0;
}