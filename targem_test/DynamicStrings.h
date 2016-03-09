#ifndef __DYNAMIC_STRINGS_H_
#define __DYNAMIC_STRINGS_H_

#include <cstring>
#include <iostream>

using namespace std;

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
	void stream_to(std::ostream& os) const { os << str; }
	~DynamicStrings();
};

inline ostream & operator<<(ostream & os, const DynamicStrings & obj)
{
	obj.stream_to(os);
	return os;
}
#endif