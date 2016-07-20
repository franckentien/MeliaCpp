/* welcome user message */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "welcome.h"

using namespace std;

int welcome()
{

string name;
// read the file for take this lenght 
string const tailleFP("file/name.txt");
ifstream FileP(tailleFP.c_str());
FileP.seekg(0, ios::end); //Go at the end of file
int lenght;

lenght = FileP.tellg();
FileP.close(); //close file for go at 0

if (lenght <= 0) // if file empty do a presentation
{
    cout << "Melia: Welcome, it's the first time i see you ! " << endl;
    cout << "I will introducre myself ,My name is Melia, I will try to ansewr at your questions" << endl ;

}
else // else welcome the user 
{
    getline(FileP, name); //read the full line 
    cout << "Melia: Hello " << name << ", I'm glad to see you " << endl << endl;
    }

    return 0;
}
