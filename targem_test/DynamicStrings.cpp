#include "DynamicStrings.h"

DynamicStrings::DynamicStrings()
{
	len = 0;
	str = nullptr;
}

DynamicStrings::DynamicStrings(const char * charObject)
{
	len = strlen(charObject);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = charObject[i];
	}	
	str[len] = '\0';
}

DynamicStrings::DynamicStrings(DynamicStrings const & object)
{
	len = object.len;	
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = object.str[i];
	}
	str[len] = '\0';
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
	for (int i = 0; i < len; i++)
	{
		str[i] = object.str[i];
	}
	str[len] = '\0';
	return *this;	
}

DynamicStrings DynamicStrings::operator+(const DynamicStrings & right)
{
	int summLen = len + right.len;
	char* summStr = new char[summLen + 1];
	for (int i = 0; i < len; i++)
	{
		summStr[i] = str[i];
	}
	for (int i = 0, j = len; j < summLen; i++, j++)
	{
		summStr[j] = right.str[i];
	}	
	DynamicStrings temp;
	temp.len = summLen;
	temp.str = new char[temp.len + 1];
	for (int i = 0; i < temp.len; i++)
	{
		temp.str[i] = summStr[i];
	}
	temp.str[temp.len] = '\0';
	delete[] summStr;
	return temp;
}

DynamicStrings::~DynamicStrings()
{
	delete[] str;	
}
