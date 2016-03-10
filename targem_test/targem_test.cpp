// targem_test.cpp : Defines the entry point for the console application.
//

#include "DynamicStrings.h"
#include <vector>
#include <fstream>

using namespace std;

//bad practice
less<> cmp;

void ds_qsort(vector<DynamicStrings>::iterator dsstart, vector<DynamicStrings>::iterator dsend)
{
	ptrdiff_t right = (dsend - dsstart) - 1;
	ptrdiff_t left = 0;

	if (right > 0)
	{
		auto ptr = dsstart[left + (right - left) / 2];
		ptrdiff_t i = left;
		ptrdiff_t j = right;

		while (i <= j)
		{
			while (cmp(dsstart[i], ptr))
				++i;

			while (cmp(ptr, dsstart[j]))
				--j;
			if (i <= j)
				swap(dsstart[i++], dsstart[j--]);
		}

		ds_qsort(dsstart, dsstart + j + 1);
		ds_qsort(dsstart + i, dsend);
	}
};

int main(int argc, char* argv[])
{
	vector<DynamicStrings> dsvector;
	ifstream inputfile;
	if (argc < 2) 
	{
		cout << "Provide filename to program." << endl;
		system("pause");
		return 0;
	}
	inputfile.open(argv[1]);
	if (!inputfile.is_open())
	{
		cout << "Some error occured while opening '"<< argv[1] << "' file!" << endl;
		system("pause");
		return 0;	
	}	
	DynamicStrings temp;
	while (!inputfile.eof()) 
	{
		inputfile >> temp;
		dsvector.push_back(temp);
		temp = DynamicStrings();		
	}	
	
	ds_qsort(dsvector.begin(), dsvector.end());
	for (vector<DynamicStrings>::reverse_iterator it = dsvector.rbegin(); it != dsvector.rend(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
    return 0;
}

