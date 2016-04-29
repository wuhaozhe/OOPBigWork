#ifndef _Database_H
#define _Database_H
#include "Single_Word.h"
class Database     //存单词的数据库
{
private:
	std::vector<Single_Word> Words;  //存储单词  
	Single_Word& Get_Single_Word(std::string Temp_Word);   //获得该单词所属的类 
	Database() = default;
public:
	Database(std::ifstream &fin);
	bool Exist(std::string Temp_Word);  //该单词是否存在 
	std::string Get_Chinese(std::string Temp_Word);		//获得该单词释义  如果不存在返回空串 
	int Get_Difficulty(std::string Temp_Word);		//获得该单词难度  如果不存在返回0 
	std::vector<std::string> Get_Examples(std::string Temp_Word);     //获得该单词例句的vector
	void Add_Example(std::string Temp_Word, std::string Temp_Example);
};
#endif
