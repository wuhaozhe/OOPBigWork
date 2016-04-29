#ifndef Single_Word_H
#define Single_Word_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
class Single_Word
{
	string Word;       //english
	string Chinese;
	int Difficulty;
	vector<string> Example;		//获得例句 
public:	
	string Get_Word();        //获得单词 
	string Get_Chinese();		//获得单词释义 
	int Get_Difficulty();		//获得难度 
	void Add_Example(string Temp_Example);       //加入例句 
	vector<string> Get_Example();                  //获得该单词例句 
	Single_Word(ifstream& fin);
	Single_Word() = default;
};
#endif
