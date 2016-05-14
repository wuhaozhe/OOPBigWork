#ifndef CONSOLE_H
#define CONSOLE_H
#include <Database.h>
#include <fstream>
#include <ctime>
#include <User.h>
#include <Memory_Strategy.h>
#include <Memory_Strategy_Shanbay.h>
#include <Memory_Strategy_Towords.h>
#include <NewWords_Strategy.h>
#include <NewWords_Strategy1.h>
#include <Test_Strategy.h>
#include <Test_Strategy_TF.h>
#include <Test_Strategy_Multi.h>
#include "Output.h"
#include "Output_Screen.h"
class Console{
private:
	Output *Out;
	Database *data;
	User *Current_User = NULL;
	Memory_Strategy *memory_strategy;       //记忆策略 1表示扇贝模式，2表示百词斩模式 
	NewWords_Strategy *newwords_strategy;		//生词统计解释策略
	Test_Strategy *test_strategy;       //在线单词测试策略 1.判断题，2.选择题 
	std::vector<std::string> get_out_console;       //从文本中获得输出 
	
	void Change_Memory_Strategy();
	
	std::string Get_Word(std::string Temp_Word);      //获得单词释义
	void Show_Search_History();     //显示查询历史
	void Search();   //在search中，根据用户要求决定是显示查询历史还是查单词 
	void Test();	//选择测试模式并测试 1.判断题 2.选择题  
	void NewWords();
	void Memory(); 
	
public:
	void Run();
	void Setup();
	Console(Database *temp_data, Output *temp_out); 
	Console() = default;
};
#endif
