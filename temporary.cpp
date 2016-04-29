#include <iostream>
#include "Database.h"
using namespace std;
int main()
{
	ifstream fin;
	fin.open("tempdict.txt");
	Database temporary(fin);
	temporary.Add_Example("abacus", "·¶Ò¯Ì«Ò¯ÁË");
	temporary.Add_Example("abattoir", "hahahahah");
	cout << (temporary.Get_Examples("abattoir"))[0];
	return 0;
}
