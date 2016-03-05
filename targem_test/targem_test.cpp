// targem_test.cpp : Defines the entry point for the console application.
//

#include "DynamicStrings.h"
#include <iostream>

using namespace std;

int main()
{
	DynamicStrings ds = DynamicStrings("abra");
	cout << ds;
    return 0;
}

