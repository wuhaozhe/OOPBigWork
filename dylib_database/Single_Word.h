#ifndef Single_Word_H
#define Single_Word_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
class Single_Word
{
	std::string Word;       //english
	std::string Chinese;
	int Difficulty;
	std::vector<std::string> Example;		//获得例句 
public:	
	std::string Get_Word();        //获得单词 
	std::string Get_Chinese();		//获得单词释义 
	int Get_Difficulty();		//获得难度 
	void Add_Example(std::string Temp_Example);       //加入例句 
	std::vector<std::string> Get_Example();                  //获得该单词例句 
	Single_Word(std::string temp); 
	Single_Word() = default;
};
#endif
