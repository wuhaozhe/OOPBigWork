#include "Test_Strategy.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
Test_Strategy::Test_Strategy(Database *temp_data): data(temp_data), times(20){
	std::ifstream fin;
	#ifdef _WIN32
		fin.open("Test_Strategy_Windows.txt");
	#else
		fin.open("Test_Strategy_linux.txt");
	#endif
	std::string get_in;
	while(getline(fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	fin.close();
}
void Test_Strategy::Init(){
	level = 1.0; Count = 0;
}
bool Test_Strategy::End(){
	return Count == times;
}
std::string Test_Strategy::Get_Word(){
	int temp; std::string Temp_Word;
	while (1){
		temp = rand()%data->Get_Words_Size();
		Temp_Word = data->Get_English(temp);
		if (data->Get_Difficulty(Temp_Word) == (int)level) break;
	}
	return Temp_Word;
}
std::string Test_Strategy::Work(bool Result){
	std::string A;
	if (Result){
		A += get_out_console[0];
		level += 4.0/times;
	}
	else{
		A += get_out_console[1];
		level -= 4.0/times;
	}
	level = std::min(level, 5.0); level = std::max(level, 1.0);
	Count++;
	return A;
}
void Test_Strategy::Set_Answer(int Temp){
	Answer = Temp;
}
int Test_Strategy::Get_Answer(){
	return Answer;
}
int Test_Strategy::Get_Level(){
	return level;
}

Test_Strategy::~Test_Strategy(){
}
