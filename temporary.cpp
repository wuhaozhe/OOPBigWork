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
	Memory_Strategy *temp_memory = new Memory_Strategy_Towords(&newuser, &temporary);
	temp_memory->Run();
	return 0;
}
