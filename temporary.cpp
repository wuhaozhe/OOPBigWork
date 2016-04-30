#include <iostream>
#include "Database.h"
#include "User.h"
#include "Console.h"
using namespace std;
int main()
{
	ifstream fin;
	fin.open("tempdict.txt");
	Database temporary(fin);
	fin.close();
	User newuser(&temporary);
	Console console(&temporary, &newuser);
	return 0;
}
