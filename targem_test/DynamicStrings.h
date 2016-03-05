#ifndef __DYNAMIC_STRINGS_H_
#define __DYNAMIC_STRINGS_H_

class DynamicStrings
{
	char *str;
	int len;
public:
	DynamicStrings();
	DynamicStrings(const char* charObject);
	DynamicStrings(DynamicStrings const& object);
	DynamicStrings& operator=(const DynamicStrings& object);
	DynamicStrings operator+(const DynamicStrings& right);

	friend ostream& operator<<(ostream& os, const DynamicStrings s);
	friend istream& operator>>(istream& is, const DynamicStrings s);
	~DynamicStrings();
};

#endif