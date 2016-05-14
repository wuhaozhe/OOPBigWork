#include "Test_Strategy_TF.h"
std::string Test_Strategy_TF::Get_Query(std::string Temp_Word){
	std::string Query; Query.clear();
	int Temp1, Temp2, answer;
	Temp1 = rand()%2;
	Query += std::cout << Temp_Word << std::endl;
	if (Temp1 == 0) Query += data->Get_Chinese(Temp_Word) + "\n";
	else{
		while (1){
			Temp2 = rand()%data->Get_Words_Size();
			if (data->Get_English(Temp2) != Temp_Word) break;
		}
		Query += data->Get_Chinese(data->Get_English(Temp2)) + "\n";
	}
	Query += "choose T means true, F means false";
	Set_Answer(Temp1);
	return Query;
}
bool Test_Strategy_TF::Check(std::string Temp){
	return Temp.size() == 1 && (Temp[0] == 'T' || Temp[0] == 'F');
}
bool Test_Strategy_TF::Test_Word(std::string Temp_Word){
	int answer;
	if (Temp_Word[0] == 'T') answer = 0;
	if (Temp_Word[0] == 'F') answer = 1;
	return (answer == Get_Answer());
}
Test_Strategy_TF::Test_Strategy_TF(Database *temp_data): Test_Strategy(temp_data){
}
