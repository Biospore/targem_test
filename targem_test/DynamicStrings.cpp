#include "DynamicStrings.h"
#include <cstring>
#include <ostream>

using namespace std;

DynamicStrings::DynamicStrings()
{
	len = 0;
	str = nullptr;
}

DynamicStrings::DynamicStrings(const char * charObject)
{
	len = strlen(charObject);
	str = new char[len + 1];
	for (int i = 0; i < len - 1; i++)
	{
		str[i] = charObject[i];
	}	
}

DynamicStrings::DynamicStrings(DynamicStrings const & object)
{
	len = object.len;
	delete[] str;
	str = new char[len + 1];
	for (int i = 0; i < len - 1; i++)
	{
		str[i] = object.str[i];
	}
}

DynamicStrings & DynamicStrings::operator=(const DynamicStrings & object)
{
	if (this == &object)
	{
		return *this;
	}

	len = object.len;
	delete[] str;
	str = new char[len + 1];
	for (int i = 0; i < len - 1; i++)
	{
		str[i] = object.str[i];
	}
	return *this;	
}

DynamicStrings DynamicStrings::operator+(const DynamicStrings & right)
{
	int summLen = len + right.len;
	char* summStr = new char[summLen + 1];
	for (int i = 0; i < (len - 1); i++)
	{
		summStr[i] = str[i];
	}
	for (int i = 0, j = len; i < (summLen - 1); i++, j++)
	{
		summStr[i] = right.str[j];
	}	
	DynamicStrings temp;
	temp.len = summLen;
	temp.str = new char[temp.len + 1];
	for (int i = 0; i < len - 1; i++)
	{
		temp.str[i] = summStr[i];
	}
	delete[] summStr;
	return temp;
}

DynamicStrings::~DynamicStrings()
{
	delete[] str;	
}

ostream & operator<<(ostream & os, const DynamicStrings s)
{
	os << s;
	return os;
}

istream & operator>>(istream & is, const DynamicStrings s)
{
	// TODO: insert return statement here
	return is;
}
