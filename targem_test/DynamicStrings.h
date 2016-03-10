#ifndef __DYNAMIC_STRINGS_H_
#define __DYNAMIC_STRINGS_H_

#include <iostream>

using namespace std;

//big bicycle
class DynamicStrings
{
private:
	char *str;
	int len;	
public:	
	DynamicStrings();
	DynamicStrings(const char* charObject);
	DynamicStrings(DynamicStrings const& object);
	DynamicStrings& operator=(const DynamicStrings& object);
	DynamicStrings operator+(const DynamicStrings& right);	
	void stream_to(ostream& os) const { os << str; }	
	friend istream & operator>>(istream & is, DynamicStrings & obj);
	bool operator==(const DynamicStrings& object);
	bool operator!=(const DynamicStrings& object);
	bool operator>(const DynamicStrings& object);
	bool operator<(const DynamicStrings& object);
	bool operator<=(const DynamicStrings& object);
	bool operator>=(const DynamicStrings& object);
	~DynamicStrings();
};
//some crutch with 'stream_to' func
inline ostream & operator<<(ostream & os, const DynamicStrings & obj)
{
	obj.stream_to(os);
	return os;
}

#endif