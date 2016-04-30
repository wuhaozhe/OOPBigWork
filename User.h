#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
class User{
private:
	std::vector<std::string> Search_History;       //查询历史 
	int Difficulty_Of_User;				//用户所设定的难度 
	int Memory_Strategy;				//用户所设定的记忆策略 
public:
	int Get_Difficulty();         //获得用户设定难度 
	int Get_Memory_Strategy();		//获得记忆策略 
	std::vector<std::string> Get_Search_History();     //获得查询历史 
	void Add_Example(std::string Word, std::string Example);		//加入例句			
	void Clear_History();         //清空查询历史 
	void Add_History(std::string Word);        //加入查询历史
	void Change_Memory_Strategy(int Wanted_Strategy);      //更改查询历史
	User();
};
#endif
