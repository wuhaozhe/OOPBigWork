#include "Test_Strategy_Multi.h"
bool Test_Strategy_Multi::Test_Word(std::string Temp_Word){
	int Temp1, Temp2, answer;
	Temp1 = rand()%4+1;
	std::cout << Temp_Word << std::endl;
	for (int i = 1; i <= 4; ++i){
		std::cout << (char)('A'-1+i) << " ";
		if (i == Temp1) std::cout << data->Get_Chinese(Temp_Word);
		else{
			while (1){
				Temp2 = rand()%data->Get_Words_Size();
				if (data->Get_English(Temp2) != Temp_Word) break;
			}
			std::cout << data->Get_Chinese(data->Get_English(Temp2));
		}
		std::cout << std::endl;
	}
	std::cout << "please choose A B C or D" << std::endl;
	char Temp[200];
	while (1){
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1){
			if (Temp[0] == 'A') { answer = 1; break; }
			if (Temp[0] == 'B') { answer = 2; break; }
			if (Temp[0] == 'C') { answer = 3; break; }
			if (Temp[0] == 'D') { answer = 4; break; }
		}
	}
	return (answer == Temp1);
}
Test_Strategy_Multi::Test_Strategy_Multi(Database *temp_data): Test_Strategy(temp_data){
	
}
