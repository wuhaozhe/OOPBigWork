#include "Memory_Strategy_Shanbay.h"
Memory_Strategy_Shanbay::Memory_Strategy_Shanbay(User *temp_user, Database *temp_data): 
	Memory_Strategy(temp_user, temp_data){
	Current_User = temp_user;
	data = temp_data;
	std::ifstream fin;
	#ifdef _WIN32
		fin.open("Memory_Strategy_Shanbay_Windows.txt");
	#else
		fin.open("Memory_Strategy_Shanbay_linux.txt");
	#endif
	std::string get_in;
	while(getline(fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	fin.close();
}
std::string Memory_Strategy_Shanbay::Get_Query(){
	Recited_Times++; std::string Query; Query.clear();
	Query += First_Word() + "\n" + get_out_console[0] + "\n" + get_out_console[1];
	return Query;
}
bool Memory_Strategy_Shanbay::Check(std::string Temp){
	return Temp.size() == 1 && (Temp[0] == 'Y' || Temp[0] == 'N');
}
std::string Memory_Strategy_Shanbay::Work(std::string Ans){
	std::string Temp_ans; Temp_ans.clear();
	if(Ans[0] == 'N')
	{
		int temp_right_times = (Current_User->Get_Memorized_Times(First_Word()).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(First_Word()).second);
		temp_whole_times++;
		Current_User->Change_Memory_times(First_Word(), temp_right_times, temp_whole_times);
		Temp_ans +=  data->Get_Chinese(First_Word()) + "\n" + get_out_console[3];
		for(int i = 0; i < (int)data->Get_Examples(First_Word()).size(); i++)
			Temp_ans += "\n" + data->Get_Examples(First_Word())[i];
		return Temp_ans;
	}
	else
	{
		Right_Times++;
		int temp_right_times = (Current_User->Get_Memorized_Times(First_Word()).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(First_Word()).second);
		temp_right_times++;
		temp_whole_times++;
		Current_User->Change_Memory_times(First_Word(), temp_right_times, temp_whole_times);
		Temp_ans += get_out_console[3];
		return Temp_ans;
	}
}
Memory_Strategy_Shanbay::~Memory_Strategy_Shanbay() {}
