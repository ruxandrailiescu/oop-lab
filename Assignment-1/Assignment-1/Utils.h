#pragma once
#include <iostream>
using namespace std;

class Utils
{
public:
	static int readIntFromConsole(string textToDisplay, int min, int max);
	static char* readCharSTringFromConsole(string textToDisplay, int minLen, int maxLen);
	static double readDoubleFromConsole(string textToDisplay, double min, double max);
};