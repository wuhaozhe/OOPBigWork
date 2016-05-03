#include "Test_Strategy.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
Test_Strategy::Test_Strategy(Database *temp_data): data(temp_data), times(10){
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
void Test_Strategy::Run(){
	double level = 1.0; int temp; std::string Temp_Word; int correct = 0;
	for (int i = 1; i <= times; ++i){
		while (1){
			temp = rand()%data->Get_Words_Size();
			Temp_Word = data->Get_English(temp);
			if (data->Get_Difficulty(Temp_Word) == (int)level) break;
		}
		if (Test_Word(Temp_Word)){
			std::cout << get_out_console[0] << std::endl;
			level += 4.0/times;
			correct++;
		}
		else{
			std::cout << get_out_console[1] << std::endl;
			level -= 4.0/times;
		}
		level = std::min(level, 5.0); level = std::max(level, 1.0);
	}
	std::cout << get_out_console[2] << (int)level << std::endl;
}
