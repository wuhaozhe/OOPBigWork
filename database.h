#ifndef _database_H
#define _database_H
#include"single_word.h"
class database     //存单词的数据库
{
private:
	vector<single_word> words;  //存储单词  
	single_word get_single_word(string temp_word);   //获得该单词所属的类 
	database(const ifstream &fin);
	database() = default;
public:
	bool exist(string temp_word);  //该单词是否存在 
	string get_chinese(string temp_word);		//获得该单词释义 
	int get_difficulty(string temp_word);		//获得该单词难度 
	vector<string> get_examples(string temp_word);     //获得该单词例句的vector
	void add_example(string temp_word, string temp_example);
};
#endif
