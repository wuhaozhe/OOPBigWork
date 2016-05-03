#include "Test_Strategy.h"
class Test_Strategy_Multi: public Test_Strategy{
public:
	bool Test_Word(std::string Temp_word);
	Test_Strategy_Multi(Database *temp_data);
	Test_Strategy_Multi() = default;
};
