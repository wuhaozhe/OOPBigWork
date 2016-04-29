#include "Database.h"
Single_Word Database::Get_Single_Word(string Temp_Word){
	int l = 0, r = Word.size()-1, mid;
	while (l < r){
		mid = (l+r)/2;
		if (Temp_Word == Words[mid].Get_Word) return Words[mid];
		else if (Temp_Word < Words[mid].Get_Word) r = mid-1;
		else l = mid+1;
	}
	return Words[l];
}
Database::Database(ifstream &fin){
	string temp;
	while(fin.getline(temp, 400)) Words.push_back(new Single_Word(temp));
}
bool Datebase::Exist(string Temp_word){
	int l = 0, r = Word.size()-1, mid;
	if  (Temp_Word < Words[0].Get_Word) return 0;
	while (l < r){
		mid = (l+r+1)/2;
		if (Temp_Word >= Words[mid].Get_Word) l = mid;
		else r = mid-1;
	}
	return (Temp_Word == Words[l].Get_Word);
}
string Database::Get_Chinese(string Temp_Word){
	if (Exist(Temp_Word)) return Get_Single_Word(Temp_Word).Get_Chinese();
	else return "";
}
int Database::Get_Difficulty(string Temp_Word){
	if (Exist(Temp_Word)) return Get_Single_Word(Temp_Word).Get_Difficulty();
	else return 0;

vector<string> Get_Examples(string Temp_Word){
	if (Exist(Temp_Word)) return Get_Single_Word(Temp_Word).Get_Example();
	else { vector<string> Temp; Temp.clear(); return Temp; }
}
void Add_Example(string Temp_Word, string Temp_Example){
	if (Exist(Temp_Word)) Get_Single_Word(Temp_Word).Add_Example(Temp_Example);
	else std::cout << Temp_Word << "doesn't exist." << std::endl;
}
