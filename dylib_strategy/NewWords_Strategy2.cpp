#include "NewWords_Strategy2.h"
std::string NewWords_Strategy2::GetText(std::string FileName){
	ifstream fin; std::string Text;
	fin.open(Filename);
	char A;
	while(fin.get(A)) Text += A;
	return Text;
}
NewWords_Strategy1::NewWords_Strategy1(User *temp_user, Database *temp_data): NewWords_Strategy(temp_user, temp_data){
}
