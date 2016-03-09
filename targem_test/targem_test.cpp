// targem_test.cpp : Defines the entry point for the console application.
//

#include "DynamicStrings.h"
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	vector<DynamicStrings> strs;
	ifstream inputfile;
	if (argc < 2) 
	{
		cout << "Provide filename to program." << endl;
		system("pause");
		return 0;
	}
	inputfile.open(argv[1]);
	if (!inputfile.is_open())
	{
		cout << "Some error occured while opening '"<< argv[1] << "' file!" << endl;
		system("pause");
		return 0;	
	}	
	DynamicStrings temp;
	while (!inputfile.eof()) 
	{
		inputfile >> temp;
		strs.push_back(temp);
		temp = DynamicStrings();		
	}	
	/*
	for (vector<DynamicStrings>::iterator it = strs.begin(); it != strs.end(); it++)
	{
		cout << *it << endl;
	}
	*/
	
	system("pause");
    return 0;
}

