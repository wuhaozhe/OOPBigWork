#ifndef TEST_STRATEGY_H
#define TEST_STRATEGY_H
#include "Test_Strategy.h"
class Test_Strategy_TF: public Test_Strategy{
public:
	bool Test_Word(std::string Temp_word);
	Test_Strategy_TF(Database *temp_data);
	Test_Strategy_TF() = default;
	std::string Get_Query(std::string Temp_Word);
	bool Check(std::string Temp);
};
#endif
