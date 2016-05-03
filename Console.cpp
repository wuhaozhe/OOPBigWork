#include <cstring>
#include "Console.h"
void Console::Change_Memory_Strategy(){
	std::cout << get_out_console[0] << std::endl;
	std::string Temp;
	getline(std::cin, Temp);
	if (Temp.size() == 1 && Temp[0] >= '1' && Temp[0] <= '2'){
		Current_User->Change_Memory_Strategy_Number(Temp[0]-'0');
		switch (Temp[0]){
			case '1':
				memory_strategy = new Memory_Strategy_Shanbay(Current_User, data);
				break;
			case '2':
				memory_strategy = new Memory_Strategy_Towords(Current_User, data);
				break;
		}
	}
	else std::cout << get_out_console[1] << std::endl;
}
std::string Console::Get_Word(std::string Temp_Word){
	return data->Get_Chinese(Temp_Word);
}
void Console::Show_Search_History(){
	std::vector<std::string>History = Current_User->Get_Search_History();
	if (History.size() == 0) std::cout << get_out_console[2] << std::endl;
	else{
		std::cout << get_out_console[3] << History.size() << get_out_console[4] << std::endl;
		for (int i = (int)History.size() - 1; i >= 0; --i) std::cout << History[i] << std::endl;
	}
}
void Console::Search(){
	while (1){
		std::cout << get_out_console[5] << std::endl << get_out_console[6] << std::endl
		<< get_out_console[7] << std::endl << get_out_console[8] << std::endl
		<< get_out_console[9] << std::endl;
		char Temp[200]; std::string Temp_Word, Chinese;
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1){
			switch (Temp[0]){
				case '0':
					std::cin.getline(Temp, 200); Temp_Word = Temp;
					Chinese = data->Get_Chinese(Temp_Word);
					if (Chinese == "") std::cout << get_out_console[10] << std::endl;
					else std::cout << Chinese << std::endl;
					Current_User->Add_History(Temp_Word);
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
		std::cout << get_out_console[11] << std::endl;
		char Temp[200];
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1 && Temp[0] >= '1' && Temp[0] <= '3'){
			switch (Temp[0]){
				case '1':
					test_strategy = new Test_Strategy_TF(data);
					break;
				case '2':
					test_strategy = new Test_Strategy_Multi(data);
					break;
				case '3':
					return;
			}
			test_strategy->Run();
		}
	}
}
void Console::NewWords(){
	newwords_strategy = new NewWords_Strategy1(Current_User, data);
	newwords_strategy->Run();
}
Console::Console(Database *temp_data, User *temp_user):data(temp_data), Current_User(temp_user), newwords_strategy(NULL), test_strategy(NULL){
	std::ifstream fin;
	#ifdef _WIN32
		fin.open("Console_Windows.txt");
	#else
		fin.open("Console_linux.txt");
	#endif
	std::string get_in;
	while(getline(fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	fin.close();
	switch (Current_User->Get_Memory_Strategy()){
		case 1:
			memory_strategy = new Memory_Strategy_Shanbay(Current_User, data);
			break;
		case 2:
			memory_strategy = new Memory_Strategy_Towords(Current_User, data);
			break;
	}
}
void Console::Run(){
	while (1){
		std::cout << get_out_console[12] << std::endl << get_out_console[13] << std::endl
		<< get_out_console[14] << std::endl << get_out_console[15] << std::endl
		<< get_out_console[16] << std::endl << get_out_console[17] << std::endl
		<< get_out_console[18] << std::endl;
		char Temp[200];
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1 && Temp[0] >= '1' && Temp[0] <= '6'){
			switch (Temp[0]){
				case '1': memory_strategy->Run(); break;
				case '2': Search(); break;
				case '3': Test(); break;
				case '4': NewWords(); break;
				case '5': Change_Memory_Strategy(); break;
				case '6': return;
			}
		}
	}
}
