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
void Console::Setup(){
	std::ifstream Fin;
	#ifdef _WIN32
		Fin.open("User_Windows.txt");
	#else
		Fin.open("User_linux.txt");
	#endif
	std::string get_in;
	while(getline(Fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	Fin.close();
	std::string temp_name;
	std::string temp_password;
	std::string flag;
	Out->Print(get_out_console[19]);
	Out->Print(get_out_console[20]);
	getline(std::cin, flag);
	while(!(flag.size() == 1 && (flag[0] == '1' || flag[0] == '2')))
	{
		Out->Print(get_out_console[21]);
		flag.clear(); 
		getline(std::cin, flag);
	}
	if(flag[0] == '1')   //register
	{
		std::string temp;
		std::string name;
		std::string password;
		std::ofstream fout;        //此处没有管mac, 需要改动 
		//#ifdef _WIN32
		//	fout.open("User\\account.txt", std::ios::app);
		//#else
			fout.open("User/account.txt", std::ios::app);
		//#endif
		Out->Print(get_out_console[22]);
		temp.clear();
		getline(std::cin, temp);
		name = temp;
		temp_name = name;
		fout<<temp<<std::endl;
		Out->Print(get_out_console[23]);
		password.clear();
		getline(std::cin, password);
		fout<<password<<std::endl;
		fout.close();
		std::string filename;
		//#ifdef _WIN32
		//	filename = "User\\";
		//#else
			filename = "User/";
		//#endif
		filename += name;
		filename += "MemorizedWords.txt";
		fout.open(filename);
		temp.clear();
		Out->Print(get_out_console[24]);
		temp.clear();
		getline(std::cin, temp);
		while(temp != password)
		{
			Out->Print(get_out_console[25]);
			temp.clear();
			getline(std::cin, temp);
		}
		
		Out->Print(get_out_console[26]);
		Out->Print(get_out_console[27]);
		Out->Print(get_out_console[28]);
		flag.clear();
		getline(std::cin, flag);
		while(!(flag.size() == 1 && flag[0] >= '1' && flag[0] <= '5'))
		{
			Out->Print(get_out_console[29]);
			flag.clear();
			getline(std::cin, flag);
		}
		char b1 = flag[0];
		
		Out->Print(get_out_console[30]);
		Out->Print(get_out_console[31]);
		Out->Print(get_out_console[32]);
		flag.clear();
		getline(std::cin, flag);
		while(!(flag.size() == 1 && flag[0] >= '1' && flag[0] <= '2'))
		{
			Out->Print(get_out_console[33]);
			flag.clear(); 
			getline(std::cin, flag);
		}
		fout<<flag[0]<<" "<<b1;
		for(int i = 1; i <= 16; i++)
			fout<<std::endl;
		fout.close();
		//#ifdef _WIN32
		//	filename = "User\\";
		//#else
			filename = "User/";
		//#endif
		filename += name;
		filename += "Examples.txt";
		fout.open(filename);
		fout.close();
	}
	else if(flag[0] == '2')   //login
	{
		std::string file_temp_name;
		std::string file_temp_password;
		std::ifstream fin;
		int p = 0, found = 0;
		do
		{
			p = 0;
			found = 0;
			Out->Print(get_out_console[34]);
			temp_name.clear();
			getline(std::cin, temp_name);
			Out->Print(get_out_console[35]);
			temp_password.clear();
			getline(std::cin, temp_password);
			//#ifdef _WIN32
			//	fin.open("User\\account.txt", std::ios::app);
			//#else
				fin.open("User/account.txt");
			//#endif
			while(getline(fin, file_temp_name))
			{
				file_temp_name;
				if(p % 2 == 1)       //password line
				{
					p++;
					file_temp_name.clear();
					continue;
				}
				else         //user nameline
				{
					p++;
					if(file_temp_name == temp_name)
					{;
						getline(fin, file_temp_password);
						found = 1;
						break;
					}
				}
			}
			if(found != 0 && (file_temp_password == temp_password))
			{
				Out->Print(get_out_console[36]);
				break;
			}
			else
			{
				Out->Print(get_out_console[37]);
				fin.close();
			}
		}while(found == 0 || file_temp_password != temp_password);
	}
	Current_User = new User(data, temp_name);
	//分割线 
	switch (Current_User->Get_Memory_Strategy()){
		case 1:
			memory_strategy = new Memory_Strategy_Shanbay(Current_User, data);
			break;
		case 2:
			memory_strategy = new Memory_Strategy_Towords(Current_User, data);
			break;
	}
}
Console::Console(Database *temp_data, Output *temp_out):data(temp_data), Current_User(NULL), newwords_strategy(NULL), test_strategy(NULL), Out(temp_out)
{
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
