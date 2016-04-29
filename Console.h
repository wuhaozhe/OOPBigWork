#ifndef CONSOLE_H
#define CONSOLE_H
#include"database.h"
class Console{
private:
	database *data;
	User *Current_User;
	ReciteStrategy *recite_strategy;       //记忆策略 
	NewWordsStrategy *newwords_strategy;		//生词统计解释策略
	TestWordsStrategy *test_strategy;       //在线单词测试策略 
	
	int GetWord(string query);
	void ChangeReciteStrategy();
	void SearchWords();
	void TestWords();
	Console(database *temp_data, User *temp_user, ); 
	Console() = default;
public:
	void Run();
};
#endif
