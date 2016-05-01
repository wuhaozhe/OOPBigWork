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
	cout<<newuser.Get_Memorized_Times("wuhao").first<<endl;
	cout<<newuser.Get_Memorized_Times("wuhao").second<<endl;
	return 0;
}
