#include "Memory_Strategy.h"
Memory_Strategy::Memory_Strategy(User *temp_user, Database *temp_data): Current_User(temp_user), data(temp_data){
	Difficulty = Current_User->Get_Difficulty();
	Word_Num = 0;
	Recited_Times = 0;
	Right_Times = 0;
	std::ifstream Fin;
	#ifdef _WIN32
		Fin.open("Memory_Strategy_Windows.txt");
	#else
		Fin.open("Memory_Strategy_linux.txt");
	#endif
	std::string get_in;
	while(getline(Fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	Fin.close();
}
void Memory_Strategy::Get_Words_Queue()
{
	auto Record_Map = Current_User->Whole_Memorized_Words();
	auto iter = Record_Map.begin();
	int Reviewed_Words_Num = 0;
	int Temp_Word_Num = Word_Num;
	std::vector<int> prevent_repeat;
	prevent_repeat.clear();
	for(; iter != Record_Map.end(); iter++)
	{
		int element = iter->second.first;   //分子 
		int denominator = iter->second.second;    //分母
		if(!(1.0 * element / denominator >= 0.6 && denominator >= 5))     //加入队列条件
		{
			Wanted_Words.push(iter->first);
			Whether_Used.push(1);
			Amount_Recited_Times.push(0);
			Reviewed_Words_Num++;
		}
		if(Reviewed_Words_Num >= (Temp_Word_Num * 0.6))
			break; 
	}
	Temp_Word_Num -= Reviewed_Words_Num;
	int flag = 0;
	while(flag < Temp_Word_Num)
	{
		int index = rand() % data->Get_Words_Size();
		int temp_flag = 0;
		for(auto iter = prevent_repeat.begin(); iter != prevent_repeat.end(); iter++)
			if(*iter == index)
				temp_flag = 1;
		if(temp_flag == 1)
			continue;
		std::string Word_By_Index = data->Get_English(index);
		if(data->Get_Difficulty(Word_By_Index) == Difficulty || data->Get_Difficulty(Word_By_Index) == Difficulty + 1)
		{
			if(Current_User->Get_Memorized_Times(Word_By_Index).first == 0 && 
			Current_User->Get_Memorized_Times(Word_By_Index).second == 0)
			{
				prevent_repeat.push_back(index);
				Wanted_Words.push(Word_By_Index);
				Whether_Used.push(0);
				Amount_Recited_Times.push(0);
				flag++;
			}
		}
	}
}
void Memory_Strategy::After_Factory()
{
	std::string temp_first_word = Wanted_Words.front();
	int temp_first_used = Whether_Used.front();
	int temp_first_amount = Amount_Recited_Times.front();
	Wanted_Words.pop();
	Whether_Used.pop();
	Amount_Recited_Times.pop();
	if(temp_first_used == 0 && temp_first_amount < 3)
	{
		temp_first_amount++;
		Wanted_Words.push(temp_first_word);
		Whether_Used.push(0);
		Amount_Recited_Times.push(temp_first_amount);
	}
}
void Memory_Strategy::Run()
{
	Recited_Times = 0;
	Right_Times = 0;
	std::cout<<get_out_console[0]<<std::endl;
	std::string temp_input;
	temp_input.clear();
	int flag = 0;
	do
	{
		flag = 0;
		getline(std::cin, temp_input);
		for(int i = 0; i < temp_input.size(); i++)
			if(temp_input[i] < '0' || temp_input[i] > '9')
			{
				std::cout<<get_out_console[1]<<std::endl;
				flag = 1;
				temp_input.clear();
				break;
			}
	}while(flag != 0);
	Word_Num = 0;
	for(int i = 0; i < temp_input.size(); i++)
		Word_Num += (temp_input[i] - '0') * pow(10, temp_input.size() - i - 1);
	Get_Words_Queue();
	while(!Wanted_Words.empty())
	{
		Recited_Times++;
		Word_Factory(Wanted_Words.front());
		After_Factory();
	}
	if(Right_Times >= (Recited_Times * 0.9))
	{
		if(Current_User->Get_Difficulty() < 5)
		{
			int Temp_Difficulty = Current_User->Get_Difficulty() + 1;
			Current_User->Change_Difficulty_Of_User(Temp_Difficulty);
			Difficulty = Temp_Difficulty;
		}	
	}
	if(Right_Times <= (Recited_Times * 0.5))
	{
		if(Current_User->Get_Difficulty() > 1)
		{
			int Temp_Difficulty = Current_User->Get_Difficulty() - 1;
			Current_User->Change_Difficulty_Of_User(Temp_Difficulty);
			Difficulty = Temp_Difficulty;
		}	
	}
	std::cout<<get_out_console[2]<<Recited_Times<<get_out_console[3]<<std::endl;
}	
