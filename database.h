#ifndef _Database_H
#define _Database_H
#include "Single_Word.h"
class Database     //存单词的数据库
{
private:
	vector<Single_Word> Words;  //存储单词  
	Single_Word Get_Single_Word(string Temp_Word);   //获得该单词所属的类 
	Database(ifstream &fin);
	Database() = default;
public:
	bool Exist(string Temp_Word);  //该单词是否存在 
	string Get_Chinese(string Temp_Word);		//获得该单词释义  如果不存在返回空串 
	int Get_Difficulty(string Temp_Word);		//获得该单词难度  如果不存在返回0 
	vector<string> Get_Examples(string Temp_Word);     //获得该单词例句的vector
	void Add_Example(string Temp_Word, string Temp_Example);
};
#endif
