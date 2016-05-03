#ifndef TEST_WORDS_STRATEGY
#define TEST_WORDS_STRATEGY
#include <Database.h>
#include <User.h>
class Test_Strategy{
	std::vector<std::string> get_out_console;
public:
	const int times;
	Database *data;
	virtual bool Test_Word(std::string Temp_Word) = 0;
	Test_Strategy(Database *temp_data);
	Test_Strategy() = default;
	void Run();
};
#endif
