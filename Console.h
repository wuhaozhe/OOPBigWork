#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <vector>
#include <string>
class Console{
private:
//	vector<单词> *WordsList;
	User *Current_User;
	ReciteStrategy *recite_strategy;//Console是其友元 
	NewWordsStrategy *newwords_strategy;//Console是其友元 
	Console();
	void Login();
	void Regist();
	int GetWord(string query);
	void ChangeReciteStrategy();
	void SearchWords();
	void TestWords();
public:
	void Run();
};
#endif
