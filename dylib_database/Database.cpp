#include "Database.h"
Single_Word& Database::Get_Single_Word(std::string Temp_Word){
	int l = 0, r = Words.size()-1, mid;
	while (l < r){
		mid = (l+r)/2;
		if (Temp_Word == Words[mid].Get_Word()) return Words[mid];
		else if (Temp_Word < Words[mid].Get_Word()) r = mid-1;
		else l = mid+1;
	}
	return Words[l];
}
Database::Database(std::ifstream &fin){
	char original[400] = {0};
	while(fin.getline(original, 400))
	{
		std::string temp(original);
		Words.push_back(Single_Word(temp));
	}
}
std::string Database::Get_English(int number){
	return Words[number].Get_Word();
}
bool Database::Exist(std::string Temp_Word){
	int l = 0, r = Words.size()-1, mid;
	if  (Temp_Word < Words[0].Get_Word()) return 0;
	while (l < r){
		mid = (l+r+1)/2;
		if (Temp_Word >= Words[mid].Get_Word()) l = mid;
		else r = mid-1;
	}
	return (Temp_Word == Words[l].Get_Word());
}
std::string Database::Get_Chinese(std::string Temp_Word){
	if (Exist(Temp_Word)) return Get_Single_Word(Temp_Word).Get_Chinese();
	else return "";
}
int Database::Get_Difficulty(std::string Temp_Word){
	if (Exist(Temp_Word)) return Get_Single_Word(Temp_Word).Get_Difficulty();
	else return 0;
}
std::vector<std::string> Database::Get_Examples(std::string Temp_Word){    
	if (Exist(Temp_Word)) { return Get_Single_Word(Temp_Word).Get_Example();}
	else { std::vector<std::string> Temp; Temp.clear(); return Temp; }
}
void Database::Add_Example(std::string Temp_Word, std::string Temp_Example){
	if (Exist(Temp_Word)) Get_Single_Word(Temp_Word).Add_Example(Temp_Example);
	//else std::cout << Temp_Word << "doesn't exist." << std::endl;
}
int Database::Get_Words_Size(){
	return Words.size();
}
