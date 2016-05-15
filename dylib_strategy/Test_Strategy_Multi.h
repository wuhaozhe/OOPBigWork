#ifndef TEST_STRATEGY_MULTI
#define TEST_STRATEGY_MULTI
#include "Test_Strategy.h"
class Test_Strategy_Multi: public Test_Strategy{
public:
	bool Test_Word(std::string Temp_word);
	Test_Strategy_Multi(Database *temp_data);
	Test_Strategy_Multi() = default;
	std::string Get_Query(std::string Temp_Word);
	bool Check(std::string Temp);
	
	~Test_Strategy_Multi();
};
#endif
