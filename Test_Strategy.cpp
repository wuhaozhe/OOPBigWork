#include "Test_Strategy.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
Test_Strategy::Test_Strategy(Database *temp_data): data(temp_data), times(10){
}
void Test_Strategy::Run(){
	double level = 1.0; int temp; string Temp_Word;
	for (int i = 1; i <= times; ++i){
		while (1){
			temp = rand()%data->Words.size();
			Temp_Word = data->Get_English(temp);
			if (data->Get_Difficulty(Temp_Word) == (int)level) break;
		}
		if (Test_Word(Temp_Word)) level+=4.0/times;
		else level-=4.0/times;
		level = std::min(level, 5.0); level = std::max(level, 1.0);
	}
}
