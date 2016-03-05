#ifndef __DYNAMIC_STRINGS_H_
#define __DYNAMIC_STRINGS_H_

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
	int getLength();
	char* getContent();
	~DynamicStrings();
};

#endif