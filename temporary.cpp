#include <iostream>
#include "Database.h"
using namespace std;
int main()
{
	ifstream fin;
	fin.open("tempdict.txt");
	Database temporary(fin);
	cout<<temporary.Get_Chinese("abacus")<<endl;
	return 0;
}
