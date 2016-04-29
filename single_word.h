#ifndef single_word_H
#define single_word_H
#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
class single_word
{
	string word;       //english
	string chinese;
	int difficulty;
	vector<string> example;		//获得例句 
public:	
	string getword();        //获得单词 
	string getchinese();		//获得单词释义 
	int get_difficulty();		//获得难度 
	void add_example(string temp_example);       //加入例句 
	vector<string> get_example();                  //获得该单词例句 
	single_word(const ifstream& fin);
	single_word() = default;
};
#endif
