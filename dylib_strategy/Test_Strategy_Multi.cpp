#include "Test_Strategy_Multi.h"
std::string Test_Strategy_Multi::Get_Query(std::string Temp_Word){
	std::string Query; Query.clear();
	int Temp1, Temp2, answer;
	Temp1 = rand()%4+1;
	Query += Temp_Word + "\n";
	for (int i = 1; i <= 4; ++i){
		Query += (char)('A'-1+i); Query+= " ";
		if (i == Temp1) Query += data->Get_Chinese(Temp_Word);
		else{
			while (1){
				Temp2 = rand()%data->Get_Words_Size();
				if (data->Get_English(Temp2) != Temp_Word) break;
			}
			Query += data->Get_Chinese(data->Get_English(Temp2));
		}
		Query += "\n";
	}
	Query += "please choose A B C or D";
	Set_Answer(Temp1);
	return Query;
}
bool Test_Strategy_Multi::Test_Word(std::string Temp_Word){
	return (Get_Answer() == Temp_Word[0]-'A'+1);
}
bool Test_Strategy_Multi::Check(std::string Temp){
	return Temp.size() == 1 && Temp[0] >= 'A' && Temp[0] <= 'D';
}
Test_Strategy_Multi::Test_Strategy_Multi(Database *temp_data): Test_Strategy(temp_data){
	
}
