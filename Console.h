#ifndef CONSOLE_H
#define CONSOLE_H
#include"database.h"
class Console{
private:
	database *data;
	User *Current_User;
	Memory_Strategy *memory_strategy;       //记忆策略 1表示扇贝模式，2表示百词斩模式 
	NewWords_Strategy *newwords_strategy;		//生词统计解释策略
	Test_Words_Strategy *test_strategy;       //在线单词测试策略 
	
	void ChangeReciteStrategy();
	
	std::string Get_Word(std::string Temp_Word);      //获得单词释义
	void Show_Search_History();     //显示查询历史
	void Search();   //在search中，根据用户要求决定是显示查询历史还是查单词 
	
	Console(database *temp_data, User *temp_user); 
	Console() = default;
public:
	void Run();
};
#endif
