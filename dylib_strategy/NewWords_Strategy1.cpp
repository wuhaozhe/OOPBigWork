#include "NewWords_Strategy1.h"
std::string NewWords_Strategy1::GetText(){
	std::string Text;
	getline(std::cin, Text);
	return Text;
}
NewWords_Strategy1::NewWords_Strategy1(User *temp_user, Database *temp_data): NewWords_Strategy(temp_user, temp_data){
}
