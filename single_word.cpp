#include "Single_Word.h"
std::string Single_Word::Get_Chinese()
{
	return Chinese;
}
std::string Single_Word::Get_Word()
{
	return Word;
}
int Single_Word::Get_Difficulty()
{
	return Difficulty;
}
std::vector<std::string> Single_Word::Get_Example()
{
	return Example;
}
void Single_Word::Add_Example(std::string Temp_Example)
{
	Example.push_back(Temp_Example);
}
Single_Word::Single_Word(std::string temp)
{
	Difficulty = temp[0] - '0';
	int i = 1;
	while(temp[i] != ' ')
	{
		Word += temp[i];
		i++;
	}
	i += 2;
	for(; i <= (temp.size() - 2); i++)
		Chinese += temp[i];
}
