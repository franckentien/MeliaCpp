/*check if two sentence are similar  */

#include <vector>
#include "STRComparator.h"

using namespace std;

bool checkQuestion(string user, string question)
{
	//take the value of similarity between two sentence 
	int ValTest = taux(question, user);
	// return true if similarite up of 90%
	if (ValTest >= 90)
		return true;
	return false;
}

//take the similarity of two sentence 
int taux(string str1, string str2)
{
	int taux;
	int count = 0;

	if (str1.size() < str2.size())
	{
		for (int i = 0; i < str1.size();i++)
		{
			if (str1[i] == str2[i])
				count++;
		}
	}
	else 
	{
		for (int i = 0; i < str2.size(); i++)
		{
			if (str1[i] == str2[i])
				count++;
		}
	}

	taux = count * 100 / str1.size();

	return taux;
}
