#include <cstring>
#include "Console.h"
void Console::Change_Memory_Strategy(){
	std::cout << "Which memory strategy do you want? 1.Shanbay mode 2.Towords mode" << std::endl;
	char Temp[200];
	std::cin.getline(Temp, 200);
	if (strlen(Temp) == 1 && Temp[0] >= '1' && Temp[0] <= '2'){
		Current_User->Change_Memory_Strategy(Temp[0]-'0');
		switch (Temp[0]){
			case '1':
				memory_strategy = new Memory_Strategy_Shanbay(Current_User, data);
				break;
			case '2':
				memory_strategy = new Memory_Strategy_Towords(Current_User, dasta);
				break;
		}
	}
	else std::cout << "No such strategy." << std::endl;
}
std::string Console::Get_Word(std::string Temp_Word){
	return data->Get_Chinese(Temp_Word);
}
void Console::Show_Search_History(){
	std::vector<std::string>History = Current_User->Get_Search_History();
	if (History.size() == 0) std::cout << "No search history yet." << std::endl;
	else{
		cout << "Last " << History.size() << " search history:" << std::endl;
		for (int i = 0; i < (int)History.size(); ++i) std::cout << History[i] << std::endl;
	}
}
void Console::Search(){
	while (1){
		std::cout << "What do you want to do? 0.Search Word 1. Get Search History 2.Clear Search History 3.Exit"
		<< std::endl;
		char Temp[200]; string Temp_Word, Chinese;
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1){
			switch (Temp[0]){
				case '0':
					std::cin >> Temp_Word;
					Chinese = data->Get_Chinese(Temp_Word);
					if (Chinese == "") std::cout << "No such Word." << std::endl;
					else std::cout << Chinese << endl;
					break;
				case '1':
					Show_Search_History();
					break;
				case '2':
					Current_User->Clear_History();
					break;
				case '3':
					return;
			}
		}
	}
}
void Console::Test(){
	while (1){
		std::cout << "Which test mode do you want? 1.T/F 2.multiple-choice" << std::endl;
		char Temp[200];
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1) && Temp[0] >= '1' && Temp[0] <= '2'){
			switch (Temp[0]){
				case '1':
					test_strategy = new Test_Strategy_TF(data);
					break;
				case '2':
					test_strategy = new Test_Strategy_Multi(data);
					break;
			}
			test_strategy->Run();
		}
	}
}
Console::Console(database *temp_data, User *temp_user):data(temp_data), Current_User(temp_user), newwords_strategy(NULL), test_strategy(NULL){
	switch (Current_User->Memory_Strategy){
		case 1:
			memory_strategy = new Memory_strategy_Shanby(Current_User, data);
			break;
		case 2:
			memory_strategy = new Memory_strategy_Towords(Current_User, data);
			break;
	}
}
void Console::Run(){
	while (1){
		std::cout << "What do you want to do? 1.Memory words 2.Search words 3.Test your vocabulary 4.Statistics of new words 5. Change memory strategy 6.Exit" << std::endl;
		char Temp[200];
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1 && Temp[0] >= '1' && Temp[0] <= '6'){
			switch (Temp[0]){
				case '1': memory_strategy->Run(); break;
				case '2': Search(); break;
				case '3': Test(); break;
				case '4': 
					newwords_strategy = new NewWords_Strategy1(Current_User, data);
					newwords_strategy->Run();
					break;
				case '5': Change_Memory_Strategy(); break;
				case '6': return;
			}
		}
	}
}
