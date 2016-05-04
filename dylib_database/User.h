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
#include "Database.h"
class User{
private:
	std::vector<std::string> Search_History;       //��ѯ��ʷ 
	int Difficulty_Of_User;				//�û����趨���Ѷ� 
	int Memory_Strategy_Number;				//�û����趨�ļ������ 
	std::map<std::string, std::pair<int, int>> Memorized_Words_Times;
	Database *wordslist;
	std::string User_Memorized_filename;
	std::string User_Examples_filename;
	std::vector<std::string> get_out_console; 
public:
	int Get_Difficulty();         //����û��趨�Ѷ� 
	int Get_Memory_Strategy();		//��ü������ 
	std::vector<std::string> Get_Search_History();     //��ò�ѯ��ʷ 
	std::pair<int, int> Get_Memorized_Times(std::string Temp_Word);   //��һ���Ǳ��ԣ��ڶ����Ǳ��� 
	std::map<std::string, std::pair<int, int>> Whole_Memorized_Words();    //�����Ƿ񱳹��õ��� 
	void Add_Example(std::string Word, std::string Example);		//��������			
	void Clear_History();         //��ղ�ѯ��ʷ 
	void Add_History(std::string Word);        //�����ѯ��ʷ
	void Change_Memory_Strategy_Number(int Wanted_Strategy);      //���ļ������ 
	void Change_Difficulty_Of_User(int Temp_Difficulty);
	void Change_Memory_times(std::string Temp_Word, int Right_Times, int Recited_times);
	User(Database *temporary);
	User() = default;
};
#endif