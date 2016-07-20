#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "userName.h"

using namespace std;

// function for take user name
string askName()
{
string name; 
// try to see if the file is not empty 
string const lenghtFP("file/name.txt");
ifstream FileP(lenghtFP.c_str());
FileP.seekg(0, ios::end); //go at the end of file 
int lenght;
lenght = FileP.tellg(); //take lenght 
FileP.close(); //close file 
int counter = 0;

if (lenght <= 0) //if the file was empty ask name 
{
    while (name == "")
    {
    ofstream FileP(lenghtFP.c_str());
    cout << "What is your name ?: ";
    getline(cin,name);
    cout << endl << endl;
    FileP << name; // save the name in the file 

    counter ++; 
    if (counter >= 3) // if user want to not write his name 
    {
        name = "Username";
    }

    }
}
else // read the name in file 
	{
    ifstream FileP(lenghtFP.c_str());
    getline(FileP, name); //read the line 
    }
	// return username 
    return name;

}


