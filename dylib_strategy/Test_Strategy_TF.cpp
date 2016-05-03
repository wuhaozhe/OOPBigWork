#include "Test_Strategy_TF.h"
bool Test_Strategy_TF::Test_Word(std::string Temp_Word){
	int Temp1, Temp2, answer;
	Temp1 = rand()%2;
	std::cout << Temp_Word << std::endl;
	if (Temp1 == 0) std::cout << data->Get_Chinese(Temp_Word) << std::endl;
	else{
		while (1){
			Temp2 = rand()%data->Get_Words_Size();
			if (data->Get_English(Temp2) != Temp_Word) break;
		}
		std::cout << data->Get_Chinese(data->Get_English(Temp2)) << std::endl;
	}
	std::cout << "choose t means true, f means false" << std::endl;
	char Temp[200];
	while (1){
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1){
			if (Temp[0] == 't') { answer = 0; break; }
			if (Temp[0] == 'f') { answer = 1; break; }
		}
	}
	return (answer == Temp1);
}
Test_Strategy_TF::Test_Strategy_TF(Database *temp_data): Test_Strategy(temp_data){
}
