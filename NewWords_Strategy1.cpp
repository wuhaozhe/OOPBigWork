#include "NewWords_Strategy1.h"
std::string NewWords_Strategy1::GetText(){
	std::cout << "Less than 1000 letters" << std::endl;
	char Temp[1000];
	std::cin.getline(Temp, 1000);
	std::string Text = Temp;
	return Text;
}
NewWords_Strategy1::NewWords_Strategy1(User *temp_user, Database *temp_data): NewWords_Strategy(temp_user, temp_data){
}
