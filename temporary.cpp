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
	newuser.Change_Memory_times("wuhao", 6, 2);
	Memory_Strategy temp_memory(&newuser, &temporary);
	temp_memory.Get_Words_Queue();
	return 0;
}
