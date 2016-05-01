#include "Memory_Strategy.h"
void Memory_Strategy::Run(){
}
Memory_Strategy::Memory_Strategy(User *temp_user, Database *temp_data): Current_User(temp_user), data(temp_data){
	Difficulty = Current_User->Get_Difficulty();
}
void Memory_Strategy::Get_Words_Queue()
{
	std::map<std::string, std::pair<int, int>>::iterator iter = Current_User->Whole_Memorized_Words().begin();
	float Reviewed_Words_Num = 0;
	float Temp_Word_Num = Word_Num;
	for(; iter != Current_User->Whole_Memorized_Words().end(); iter++)
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
	while(flag <= Temp_Word_Num)
	{
		int index = rand() % data->Get_Words_Size();
		std::string Word_By_Index = data->Get_English(index);
		if(data->Get_Difficulty(Word_By_Index) == Difficulty || data->Get_Difficulty(Word_By_Index) == Difficulty + 1)
		{
			if(Current_User->Get_Memorized_Times(Word_By_Index).first == 0 && 
			Current_User->Get_Memorized_Times(Word_By_Index).second == 0)
			{
				Wanted_Words.push(Word_By_Index);
				Whether_Used.push(0);
				Amount_Recited_Times.push(1);
				flag++;
			}
		}
	}
}
