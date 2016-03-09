#include "DynamicStrings.h"

DynamicStrings::DynamicStrings()
{
	len = 0;
	str = new char[0];
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

istream & operator>>(istream & is, DynamicStrings & obj)
{	
	int count = 30;
	int readed = 0;
	char symbol;
	char* buf = new char[count];
	delete obj.str;	
	while (is.get(symbol) && symbol != '\n' && symbol != '\0')
	{
		buf[readed] = symbol;
		readed++;		
		if (readed == count - 1) 
		{			
			char* buf2 = new char[count];
			for (int i = 0; i < count; i++)
			{
				buf2[i] = buf[i];
			}
			count += 30;
			buf = new char[count];
			for (int i = 0; i < count - 16; i++)
			{
				buf[i] = buf2[i];
			}			
			delete[] buf2;
		}
	}
	
	obj.str = new char[readed+1];
	for (int i = 0; i < readed; i++)
	{
		obj.str[i] = buf[i];
	}
	delete[] buf;	
	obj.str[readed] = '\0';
	obj.len = strlen(obj.str);
	return is;
}
