#include "Memory_Strategy_Towords.h"
Memory_Strategy_Towords::Memory_Strategy_Towords(User *temp_user, Database *temp_data): 
Memory_Strategy(temp_user, temp_data){
	Current_User = temp_user;
	data = temp_data;
	std::ifstream fin;
	#ifdef _WIN32
		fin.open("Memory_Strategy_Towords_Windows.txt");
	#else
		fin.open("Memory_Strategy_Towords_linux.txt");
	#endif
	std::string get_in;
	while(getline(fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	fin.close();
}
std::string Memory_Strategy_Towords::Get_Query(){
	Recited_Times++; std::string Query; Query.clear();
	std::string Temp_Word;
	Temp_Word = First_Word();
	Query += Temp_Word + "\n";
	int index[4] = {0};
	for(int i = 0; i < 4; i++)
	{
		int temp_flag = 0;
		do
		{
			index[i] = rand() % data->Get_Words_Size();
			for(int j = 0; j < i; j++)
			{
				if(index[j] == index[i] || data->Get_English(index[j]) == Temp_Word)
					temp_flag = 1;
			}
		}while(temp_flag != 0);
	}
	int seq = rand() % 4; answer = seq;
	for(int i = 0; i < 4; i++)
	{
		if(i == seq)
		{
			Query += char(65 + i); Query += '.'; Query += data->Get_Chinese(Temp_Word);
		}
		else
		{
			Query += char(65 + i); Query += '.'; Query += data->Get_Chinese(data->Get_English(index[i]));
		}
		if (i < 3) Query += "\n";
	}
	return Query;
}
bool Memory_Strategy_Towords::Check(std::string Temp){
	return (Temp.size() == 1 && 'A' <= Temp[0] && 'D' >= Temp[0]);
}
std::string Memory_Strategy_Towords::Work(std::string Ans){
	std::string Temp_ans; Temp_ans.clear();
	if(int(Ans[0] - 'A') != answer)   //wrong
	{
		int temp_right_times = (Current_User->Get_Memorized_Times(First_Word()).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(First_Word()).second);
		temp_whole_times++;
		Current_User->Change_Memory_times(First_Word(), temp_right_times, temp_whole_times);
		Temp_ans += get_out_console[1] + char(answer + 65) + "\n";
		Temp_ans += get_out_console[2] + data->Get_Chinese(First_Word()) + "\n";
		Temp_ans += get_out_console[3];
		for(int i = 0; i < (int)data->Get_Examples(First_Word()).size(); i++)
			Temp_ans += "\n" + data->Get_Examples(First_Word())[i];
	}
	else    //right
	{
		Temp_ans += get_out_console[7];
		Right_Times++;
		int temp_right_times = (Current_User->Get_Memorized_Times(First_Word()).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(First_Word()).second);
		temp_right_times++;
		temp_whole_times++;
		Current_User->Change_Memory_times(First_Word(), temp_right_times, temp_whole_times);
		return Temp_ans;
	}
}
