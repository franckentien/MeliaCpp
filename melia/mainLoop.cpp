/*Main loop display ansews for the user question */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "mainLoop.h"
#include "userName.h"
#include "STRComparator.h"

using namespace std;

bool mainLoop ()
{

    //Value
    vector<string>question;
    vector<string>answer;
    string user;
    string read;
    string stop = "/stop";
    int lenght;
    int i = 0;
    string nameU = askName();
	bool questionOk = true;
	bool testQ = true;
	bool testR = true;

	// open the file 
    string const lenghtf("file/question.melia");
    ifstream fileQ(lenghtf.c_str());
    if(fileQ){}
	else{ testQ = false;}
    string const lenghta("file/answer.melia");
    ifstream fileR(lenghta.c_str());
    if(fileR){}
	else{ testR = false;}

	//display error if file can'b be load 
	if (testQ == false && testR == false)
	{
		cout << "Melia: I can't found files : 'question' and 'answer'" << endl << "Melia: I can't answer to your questions";
		cout << endl << endl << endl;
			return 0; //finish the execution 
	}
	else if (testQ == false ) 
	{
		cout << "Melia: I can't found files : 'question'" << endl << "Melia: I can't answer to your questions";
		cout << endl << endl << endl;
		return 0; 
	}
	else if (testR == false ) 
	{
		cout << "Melia: I can't found files : 'answer'" << endl << "Melia: I can't answer to your questions";
		cout << endl << endl << endl;
		return 0;
	}

	//loop for save the file in tab 
	string l;
	while (getline(fileQ, l)) {
		question.push_back(l);
	}
	while (getline(fileR, l)) {
		answer.push_back(l);
	}

    lenght = question.size(); //define size value 

    cout << nameU <<": " ; // display username for waiting question 
    
    getline(cin,user); // take user question 
    
    // check of value 
    // if user ask to stop the application 
    if (user == stop)
	{
		cout << endl << "Melia: See you soon !! ";
		cout << endl << endl << endl;
		return false; // return false for exit the programe 
	}
	// if the sentese was empty 
	if (user == "")  
	{
		cout << "It's not a valide question" << endl << endl;
		return true;// continue 
	}
	// loop for check user question 
	while (questionOk)
	{
		if (i >= lenght) // if the question was not in file 
		{
			//display error message and save it in the file 
			cout << "Melia: I'm sorry but i don't have ansews for this question !!!" << endl << endl << endl;
			string const fileLogs("file/Logs.txt");
			ofstream Logs(fileLogs.c_str(), ios::app);
			Logs << user << endl; // write the unknow question 
			return true;
		}
		//if user was simmilar go out of loop 
		if (checkQuestion(user, question[i])) 
			questionOk = false;
		else i++;
	}

	// display the answers in ansews file base on id of line 
	cout << "Melia: " << answer[i] << endl << endl << endl;

	return true;
}