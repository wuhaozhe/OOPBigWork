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
std::map<std::string, std::pair<int, int>> User::Whole_Memorized_Words()
{
	return Memorized_Words_Times;
}

User::User(Database *temporary, std::string temp_name): wordslist(temporary)
{
	std::ifstream fin;         //从这开始读入用户文件中的例句等各种信息 
	std::string temp_filename;
	//#ifdef _WIN32
	//	temp_filename += "User\\";
	//#else
		temp_filename += "User/"; 
	//#endif
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
void User::Change_Memory_times(std::string Temp_Word, int Right_Times, int Recited_Times)
{
	std::pair<int, int> Temp_Pair = Get_Memorized_Times(Temp_Word);   //要同时修改map和文件!! 
	if(Temp_Pair.first == 0 && Temp_Pair.second == 0)
	{
		Temp_Pair.first += Right_Times;
		Temp_Pair.second += Recited_Times;
		Memorized_Words_Times[Temp_Word] = Temp_Pair;
		std::ofstream fout;
		fout.open(User_Memorized_filename, std::ios::app);
		fout<<Temp_Word<<" "<<Right_Times<<" "<<Recited_Times<<std::endl;
		fout.close();
	}
	else
	{
		Temp_Pair.first = Right_Times;
		Temp_Pair.second = Recited_Times;
		Memorized_Words_Times[Temp_Word] = Temp_Pair;
		std::vector<std::string> Temp_Record;
		std::ifstream fin;
		fin.open(User_Memorized_filename);
		char temp_input[200] = {0};
		Temp_Record.clear();
		while(fin.getline(temp_input, 200))
		{
			std::string a = temp_input;
			Temp_Record.push_back(a);
			a.clear();
			memset(temp_input, 0, sizeof(temp_input));
		}
		fin.close();
		std::ofstream fout;
		fout.open(User_Memorized_filename);
		for(int i = 0; i < Temp_Record.size(); i++)
		{
			if(i <= 15)
				fout<<Temp_Record[i]<<std::endl;
			else
			{
				int p = 0;
				std::string temp_get;
				temp_get.clear();
				while(Temp_Record[i][p] != ' ')
				{
					temp_get += Temp_Record[i][p];
					p++;
				}
				if(temp_get != Temp_Word)
					fout<<Temp_Record[i]<<std::endl;
				else
					fout<<temp_get<<" "<<Right_Times<<" "<<Recited_Times<<std::endl;
			}
		}
	}
}
