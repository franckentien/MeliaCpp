#include <iostream>
#include <string>
#include <cstdlib>
#include "mainLoop.h"
#include "welcome.h"

using namespace std;

int main()
{
	bool valeurReturn = true; // bool for main loop 


	//display introduce message 
	cout << "*Do not put space betzeen the last word and the '?'*" << endl;
	cout << "*For close the soft you myst to write ``/STOP''*" << endl;
	cout << endl << endl;
	cout << "\t\t=== Artificial Intelligence Software==== " << endl << endl;

	welcome(); //Welcome message 


	while (valeurReturn)
	{
		valeurReturn = mainLoop();
	}

	system("pause");// do not close the console imediatly 


	return 0;
}





