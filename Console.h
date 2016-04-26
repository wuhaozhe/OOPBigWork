#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <vector>
#include <string>
class Console{
private:
//	vector<µ¥´Ê> WordsList;
	User *Current_User;
	ReciteStrategy *recite_strategy;
	NewWordsStrategy *newwords_strategy;
	Console();
	void Login();
	void Regist();
	int GetWord(string query);
	void ChangeReciteStrategy();
	void SearchWords(); 
public:
	void Run();
};
#endif
