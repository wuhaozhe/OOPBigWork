#include "NewWords_Strategy.h"
#include <set>
void NewWords_Strategy::Run(){
	std::string Text = GetText(); Text += "."; int Len = Text.size();
	std::set<std::string> List; List.clear();
	std::string Temp_Word = "";
	for (int i = 0; i < Len; ++i)
	if ((Text[i] >= 'a' && Text[i] <= 'z') || (Text[i] >= 'A' && Text[i] <= 'Z')){
		if (Text[i] >= 'A' && Text[i] <= 'Z') Text[i] = Text[i]-'A'+'a';
		Temp_Word += Text[i];
	}
	else{
		if (Temp_Word != ""){
			if (!(data->Exist(Temp_Word)) || (data->Get_Difficulty(Temp_Word) > Current_User->Get_Difficulty() && Current_User->Get_Memorized_Times(Temp_Word).first == 0)){
				if (List.count(Temp_Word) == 0){
					std::cout <<get_out_console[0] << Temp_Word << std::endl;
					if (data->Exist(Temp_Word)) std::cout << data->Get_Chinese(Temp_Word) << std::endl;
					else std::cout << get_out_console[1] << std::endl;
					List.insert(Temp_Word);
				}
			}
		}
		Temp_Word = "";
	}
	List.clear();
}
NewWords_Strategy::NewWords_Strategy(User *temp_user, Database *temp_data): Current_User(temp_user), data(temp_data){
	std::ifstream fin;
	#ifdef _WIN32
		fin.open("NewWords_Strategy_Windows.txt");
	#else
		fin.open("NewWords_Strategy_linux.txt");
	#endif
	std::string get_in;
	while(getline(fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	fin.close();
}
