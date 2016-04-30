#ifndef TEST_WORDS_STRATEGY
#define TEST_WORDS_STRATEGY
#include "database.h"
#include "User.h"
class Test_Strategy{
public:
	const int times;
	Database *data;
	virtual bool Test_Word(string Temp_Word) = 0;
	Test_Strategy(Database *temp_data);
	Test_Strategy() = default;
	void Run();
};
#endif
