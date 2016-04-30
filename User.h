#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#include <memory.h>
#include "database.h"
class User{
private:
	std::vector<std::string> Search_History;       //查询历史 
	int Difficulty_Of_User;				//用户所设定的难度 
	int Memory_Strategy_Number;				//用户所设定的记忆策略 
	std::map<std::string, std::pair<int, int>> Memorized_Words_Times;
	Database *wordslist;
	std::string User_Memorized_filename;
	std::string User_Examples_filename;
public:
	int Get_Difficulty();         //获得用户设定难度 
	int Get_Memory_Strategy();		//获得记忆策略 
	std::vector<std::string> Get_Search_History();     //获得查询历史 
	std::pair<int, int> Get_Memorized_Times(std::string Temp_Word);   //第一个是背对，第二个是背过 
	void Add_Example(std::string Word, std::string Example);		//加入例句			
	void Clear_History();         //清空查询历史 
	void Add_History(std::string Word);        //加入查询历史
	void Change_Memory_Strategy_Number(int Wanted_Strategy);      //更改记忆策略 
	void Change_Difficulty_Of_User(int Temp_Difficulty);
	User(Database *temporary);
	User() = default;
};
#endif
