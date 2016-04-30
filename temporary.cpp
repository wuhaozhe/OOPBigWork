#include <iostream>
#include "Database.h"
#include "User.h"
using namespace std;
int main()
{
	ifstream fin;
	fin.open("tempdict.txt");
	Database temporary(fin);
	fin.close();
	return 0;
}
