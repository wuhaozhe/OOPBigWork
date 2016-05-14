#ifndef TEST_WORDS_STRATEGY
#define TEST_WORDS_STRATEGY
#include <Database.h>
#include <User.h>
class Test_Strategy{
	std::vector<std::string> get_out_console;
	double level;
	int Answer, Count;
public:
	const int times;
	Database *data;
	virtual bool Test_Word(std::string Temp_Word) = 0;
	Test_Strategy(Database *temp_data);
	Test_Strategy() = default;
	void Init();
	bool End();
	std::string Get_Word();
	std::string Work(bool Result);
	void Set_Answer(int Temp);
	int Get_Answer();
	
	virtual std::string Get_Query(std::string Temp_Word) = 0;
	virtual bool Check(std::string Temp) = 0;
};
#endif
