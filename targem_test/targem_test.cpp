// targem_test.cpp : Defines the entry point for the console application.
//

#include "DynamicStrings.h"
#include <iostream>

using namespace std;

int main()
{
	DynamicStrings ds = DynamicStrings("abra");
	DynamicStrings ds1 = DynamicStrings("cadabra");
	DynamicStrings ds2;
	DynamicStrings ds3;
	ds2 = ds;
	ds3 = ds + ds1;		
	cout << ds << '\n';
	cout << ds2 << '\n';
	cout << ds1<< '\n';
	cout << ds3<< '\n';		
	system("pause");
    return 0;
}

