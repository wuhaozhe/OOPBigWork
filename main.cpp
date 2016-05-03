#include "Console.h"
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	ifstream fin;
	#ifdef _WIN32
		fin.open("dict_Windows.txt");
	#else
		fin.open("dict_linux.txt");
	#endif
	Database temporary(fin);
	fin.close();
	User newuser(&temporary);
	Console newconsole(&temporary, &newuser);
	newconsole.Run();
	return 0;
}
