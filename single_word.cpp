#include "Single_Word.h"
string Single_Word::Get_Chinese()
{
	return Chinese;
}
string Single_Word::Get_Word()
{
	return Word;
}
int Get_Difficulty()
{
	return Difficulty;
}
vector<string> Single_Word::Get_Example()
{
	return Example;
}
void Add_Example(string Temp_Example)
{
	Example::push_back(Temp_Example);
}
Single_word::(string temp)
{
	Difficulty = temp[0] - '0';
	int i = 1;
	while(temp[i] != ' ')
	{
		Word += temp[i];
		i++;
	}
	i += 2;
	for(; i <= (temp.size() - 1); i++)
		Word += temp[i];
}

