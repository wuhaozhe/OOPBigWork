#include "Memory_Strategy.h"
Memory_Strategy::Memory_Strategy(User *temp_user, Database *temp_data): Current_User(temp_user), data(temp_data){
	Difficulty = Current_User->Get_Difficulty();
}
void Memory_Strategy::Get_Words_Queue()
{
	auto Record_Map = Current_User->Whole_Memorized_Words();
	auto iter = Record_Map.begin();
	float Reviewed_Words_Num = 0;
	float Temp_Word_Num = Word_Num;
	std::vector<int> prevent_repeat;
	prevent_repeat.clear();
	for(; iter != Record_Map.end(); iter++)
	{
		float element = iter->second.first;   //分子 
		float denominator = iter->second.second;    //分母
		if(!(element / denominator >= 0.6 && denominator >= 5))     //加入队列条件
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
