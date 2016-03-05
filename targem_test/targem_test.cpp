// targem_test.cpp : Defines the entry point for the console application.
//

#include "DynamicStrings.h"
#include <iostream>

using namespace std;

int main()
{
	DynamicStrings ds = DynamicStrings("abra\0");
	DynamicStrings ds1 = DynamicStrings("cadabra\0");
	DynamicStrings ds2;
	DynamicStrings ds3;
	ds2 = ds;
	ds3 = ds + ds1;		
	cout << ds.getContent() << '\n';
	cout << ds2.getContent() << '\n';
	cout << ds1.getContent() << '\n';
	cout << ds3.getContent() << '\n';	
	system("pause");
    return 0;
}

