#ifndef MEMORY_STRATEGY
#define MEMORY_STRATEGY
#include "User.h"
#include "Database.h"
#include <ctime>
#include <queue>
#include <cstdlib>
class Memory_Strategy{
	std::queue<std::string> Wanted_Words;     //存储此次被单词中要背的单词 
	std::queue<int> Whether_Used;       //存储该单词是否背过      1表示曾经在字典中出现过， 0表示未出现过 
	std::queue<int> Amount_Recited_Times;    //该单词背诵次数 
	int Word_Num;          //用户需要的单词个数  10最后删掉 
	int Difficulty;           //用户设定难度 
public:
	User *Current_User;
	Database *data;
	void Get_Words_Queue();         //获得要背单词的队列 
	virtual Word_Factory(std::string Temp_Word) = 0;        //对单词进行处理 
	void After_Factory(std::string Temp_Word){};           //对该单词进行各种信息改动 
	void Run(){};
	Memory_Strategy(User *temp_user, Database *temp_data);
	Memory_Strategy() = default;
};
#endif
