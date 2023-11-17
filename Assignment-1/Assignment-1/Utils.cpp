#include "Utils.h"

int Utils::readIntFromConsole(string textToDisplay, int min, int max)
{
	bool wrongValue = false;
	char* readLine = new char[256];
	int val = 0;

	do
	{
		if (wrongValue)
			cout << "Value out of range. Please insert a new value." << endl;
		cout << textToDisplay << "(" << min << "-" << max << ")" << endl;
		cin.getline(readLine, 10);

		val = atoi(readLine);

		if (val < 1 || val > max)
			wrongValue = true;
		else
			wrongValue = false;
	} while (wrongValue);

	return val;
}

char* Utils::readCharSTringFromConsole(string textToDisplay, int minLen, int maxLen)
{
	char* readText = new char[maxLen];
	do
	{
		cout << textToDisplay << "(Len: " << minLen << "-" << maxLen << ")" << endl;
		cin.getline(readText, maxLen);
	} while (strlen(readText) < minLen);

	return readText;
}

double Utils::readDoubleFromConsole(string textToDisplay, double min, double max)
{
	bool wrongValue = false;
	char* readLine = new char[256];
	double val = 0.0;

	do
	{
		if (wrongValue)
			cout << "Value out of range. Please insert a new value." << endl;
		cout << textToDisplay << "(" << min << "-" << max << ")" << endl;

		cin.getline(readLine, 256);

		val = atof(readLine);

		if (val < min || val > max)
			wrongValue = true;
		else
			wrongValue = false;
	} while (wrongValue);
	return val;
}

