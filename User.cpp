#include "User.h"
int User::Get_Difficulty()
{
	return Difficulty_Of_User;
}
int User::Get_Memory_Strategy()
{
	return Memory_Strategy_Number;
}
std::vector<std::string> User::Get_Search_History()
{
	return Search_History;
}
std::pair<int, int> User::Get_Memorized_Times(std::string Temp_Word)
{
	std::map<std::string, std::pair<int, int>>::iterator iter;
	iter = Memorized_Words_Times.find(Temp_Word);
	if(iter != Memorized_Words_Times.end())
		return Memorized_Words_Times[Temp_Word];
	else
	{
		std::pair<int, int> a;
		a.first = 0; a.second = 0;
		return a;
	}
}

User::User(Database *temporary): wordslist(temporary)
{
	std::string temp_name;
	std::string temp_password;
	char flag[100] = {0};
	std::cout<<"未注册， 请按1"<<std::endl;
	std::cout<<"已注册， 请按2"<<std::endl;
	std::cin.getline(flag, 100);
	while(!(strlen(flag) == 1 && (flag[0] == '1' || flag[0] == '2')))
	{
		std::cout<<"输入错误，请重新输入"<<std::endl;
		memset(flag, 0, sizeof(flag)); 
		std::cin.getline(flag, 100);
	}
	if(flag[0] == '1')   //register
	{
		std::string temp;
		std::string name;
		std::string password;
		std::ofstream fout;        //此处没有管mac, 需要改动 
		#ifdef linux
			fout.open("User/account.txt", std::ios::app);
		#endif
		#ifdef _WIN32
			fout.open("User\\account.txt", std::ios::app);
		#endif
		std::cout<<"请输入用户名" <<std::endl;
		char temporarya[100] = {0};
		std::cin.getline(temporarya, 100);
		temp = temporarya;
		name = temp;
		fout<<temp<<std::endl;
		std::cout<<"请输入密码"<<std::endl;
		char temporaryb[100] = {0};
		std::cin.getline(temporaryb, 100);
		password = temporaryb;
		fout<<password<<std::endl;
		fout.close();
		std::string filename;
		#ifdef linux
			filename = "User/";
		#endif
		#ifdef _WIN32
			filename = "User\\";
		#endif
		filename += name;
		filename += "MemorizedWords.txt";
		User_Memorized_filename = filename;
		fout.open(filename);
		temp.clear();
		std::cout<<"请确认密码"<<std::endl;
		char temporaryc[100] = {0};
		std::cin.getline(temporaryc, 100);
		temp = temporaryc;
		while(temp != password)
		{
			std::cout<<"输入错误，请重新输入"<<std::endl;
			temp.clear();
			char temporaryd[100] = {0};
			std::cin.getline(temporaryd, 100);
			temp = temporaryd;
		}
		
		std::cout<<"你希望选择的难度"<<std::endl;
		std::cout<<"1. 简单，2. 一般，3. 较难，4. 难， 5. 地狱模式"<<std::endl;
		std::cout<<"请输入难度所对应的数字"<<std::endl;
		memset(flag, 0, sizeof(flag));
		std::cin.getline(flag, sizeof(flag));
		while(!(strlen(flag) == 1 && flag[0] >= '1' && flag[0] <= '5'))
		{
			std::cout<<"输入错误，请重新输入"<<std::endl;
			memset(flag, 0, sizeof(flag)); 
			std::cin.getline(flag, sizeof(flag));
		}
		char b1 = flag[0];
		Difficulty_Of_User = (flag[0] - '0');
		
		std::cout<<"你希望选择的背单词模式"<<std::endl;
		std::cout<<"1. 扇贝模式， 2. 百词斩模式"<<std::endl;
		std::cout<<"请输入模式所对应的数字"<<std::endl;
		memset(flag, 0, sizeof(flag));
		std::cin.getline(flag, sizeof(flag));
		while(!(strlen(flag) == 1 && flag[0] >= '1' && flag[0] <= '2'))
		{
			std::cout<<"输入错误，请重新输入"<<std::endl;
			memset(flag, 0, sizeof(flag)); 
			std::cin.getline(flag, sizeof(flag));
		}
		fout<<flag[0]<<" "<<b1;
		Memory_Strategy_Number = flag[0] - '0';
		for(int i = 1; i <= 16; i++)
			fout<<std::endl;
		fout.close();
		#ifdef linux
			filename = "User/";
		#endif
		#ifdef _WIN32
			filename = "User\\";
		#endif
		filename += name;
		filename += "Examples.txt";
		User_Examples_filename = filename;
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
			std::cout<<"请输入用户名"<<std::endl;
			char temporary1[100] = {0};
			std::cin.getline(temporary1, 100);
			temp_name = temporary1;
			std::cout<<"请输入密码"<<std::endl;
			memset(temporary1, 0, sizeof(temporary1));
			std::cin.getline(temporary1, 100);
			temp_password = temporary1;
			#ifdef linux
				fin.open("User/account.txt", std::ios::app);
			#endif
			#ifdef _WIN32
				fin.open("User\\account.txt", std::ios::app);
			#endif
			char temporary2[100] = {0};
			while(fin.getline(temporary2, 100))
			{
				file_temp_name = temporary2;
				if(p % 2 == 1)
				{
					p++;
					memset(temporary2, 0, sizeof(temporary2));
					file_temp_name.clear();
					continue;
				}
				else
				{
					p++;
					if(file_temp_name == temp_name)
					{
						char temporary3[100] = {0};
						fin.getline(temporary3, 100);
						file_temp_password = temporary3;
						found = 1;
						break;
					}
				}
			}
			if(found != 0 && (file_temp_password == temp_password))
			{
				std::cout<<"登录成功！"<<std::endl;
				break;
			}
			else
			{
				std::cout<<"该用户不存在或密码输入错误"<<std::endl;
				fin.close();
			}
		}while(found == 0 || file_temp_password != temp_password);
	}
	std::ifstream fin;         //从这开始读入用户文件中的例句等各种信息 
	std::string temp_filename;
	#ifdef linux
		temp_filename += "User/"; 
	#endif
	#ifdef _WIN32
		temp_filename += "User\\";
	#endif
	temp_filename += temp_name;
	std::string filename_one = temp_filename;
	filename_one += "MemorizedWords.txt";
	std::string filename_two = temp_filename;
	filename_two += "Examples.txt";
	User_Memorized_filename = filename_one;
	User_Examples_filename = filename_two;
	fin.open(filename_one);
	fin>>Memory_Strategy_Number;
	fin>>Difficulty_Of_User;
	std::string temp_history;
	for(int i = 1; i <= 15; i++)
	{
		char temporary4[100] = {0};
		fin.getline(temporary4, 100);
		temp_history = temporary4;
		if(temp_history.size() >= 1)
			Search_History.push_back(temp_history);
		temp_history.clear();	
	}
	std::pair<int, int> Temp_Memorized_Words;
	std::string temp_word;
	while((fin>>temp_word) && (fin>>Temp_Memorized_Words.first) && (fin>>Temp_Memorized_Words.second))
		Memorized_Words_Times[temp_word] = Temp_Memorized_Words;
	fin.close();
	fin.open(filename_two);
	std::string temp_str;
	temp_word.clear();
	std::string temp_examples;
	char temporary5[400] = {0};
	while(fin.getline(temporary5, 400))
	{
		temp_str = temporary5;
		int p = 0;
		while(temp_str[p] != ' ')
		{
			temp_word += temp_str[p];
			p++;
		}
		p++;
		for(; p <= temp_str.size() - 1; p++)
			temp_examples += temp_str[p];
		wordslist->Add_Example(temp_word, temp_examples);
		temp_word.clear();
		temp_examples.clear();
		temp_str.clear();
		memset(temporary5, 0, sizeof(temporary5));
	}
}
void User::Add_Example(std::string Word, std::string Example)
{
	std::ofstream fout;
	fout.open(User_Examples_filename, std::ios::app);
	fout<<Word<<" "<<Example<<std::endl;
	fout.close();
}
void User::Add_History(std::string Word)
{
	std::ifstream fin;
	fin.open(User_Memorized_filename);
	char temp_input[200] = {0};
	std::vector<std::string> temp_record;
	temp_record.clear();
	while(fin.getline(temp_input, 200))
	{
		std::string a = temp_input;
		temp_record.push_back(a);
		a.clear();
		memset(temp_input, 0, sizeof(temp_input));
	}
	fin.close();
	std::ofstream fout;
	fout.open(User_Memorized_filename);
	for(int i = 0; i < temp_record.size(); i++)
	{
		if(i == 0)
			fout<<temp_record[0]<<std::endl;
		else if(i == 1)
			fout<<Word<<std::endl;
		else if(i >= 2 && i <= 15)
			fout<<temp_record[i - 1]<<std::endl;
		else
			fout<<temp_record[i]<<std::endl;
	}
	fout.close();
	if(Search_History.size() < 15)
		Search_History.push_back(Word);
	else
	{
		for(int i = 1; i <= 14; i++)
			Search_History[i - 1] = Search_History[i];
		Search_History[14] = Word;
	}
}
void User::Clear_History()
{
	std::ifstream fin;
	fin.open(User_Memorized_filename);
	char temp_input[200] = {0};
	std::vector<std::string> temp_record;
	temp_record.clear();
	while(fin.getline(temp_input, 200))
	{
		std::string a = temp_input;
		temp_record.push_back(a);
		a.clear();
		memset(temp_input, 0, sizeof(temp_input));
	}
	fin.close();
	std::ofstream fout;
	fout.open(User_Memorized_filename);
	for(int i = 0; i < temp_record.size(); i++)
	{
		if(i == 0)
			fout<<temp_record[0]<<std::endl;
		else if(i >= 1 && i <= 15)
			fout<<std::endl;
		else
			fout<<temp_record[i]<<std::endl;
	}
	Search_History.clear();
}
void User::Change_Memory_Strategy_Number(int Wanted_Strategy)
{
	Memory_Strategy_Number = Wanted_Strategy;
	std::ifstream fin;
	fin.open(User_Memorized_filename);
	char temp_input[200] = {0};
	std::vector<std::string> temp_record;
	temp_record.clear();
	while(fin.getline(temp_input, 200))
	{
		std::string a = temp_input;
		temp_record.push_back(a);
		a.clear();
		memset(temp_input, 0, sizeof(temp_input));
	}
	fin.close();
	std::ofstream fout;
	fout.open(User_Memorized_filename);
	fout<<Memory_Strategy_Number<<" "<<temp_record[0][2]<<std::endl;
	for(int i = 1; i < temp_record.size(); i++)
		fout<<temp_record[i]<<std::endl;
	fout.close();
}
void User::Change_Difficulty_Of_User(int Temp_difficulty)
{
	Difficulty_Of_User = Temp_difficulty;
	std::ifstream fin;
	fin.open(User_Memorized_filename);
	char temp_input[200] = {0};
	std::vector<std::string> temp_record;
	temp_record.clear();
	while(fin.getline(temp_input, 200))
	{
		std::string a = temp_input;
		temp_record.push_back(a);
		a.clear();
		memset(temp_input, 0, sizeof(temp_input));
	}
	fin.close();
	std::ofstream fout;
	fout.open(User_Memorized_filename);
	fout<<temp_record[0][0]<<" "<<Difficulty_Of_User<<std::endl;
	for(int i = 1; i < temp_record.size(); i++)
		fout<<temp_record[i]<<std::endl;
	fout.close();
}
