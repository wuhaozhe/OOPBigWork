#ifndef MEMORY_STRATEGY_TOWORDS
#define MEMORY_STRATEGY_TOWORDS
#include "Memory_Strategy.h"
class Memory_Strategy_Towords: public Memory_Strategy{
	int answer;
	std::vector<std::string> get_out_console;
public:
	Memory_Strategy_Towords(User *temp_user, Database *temp_data);
	Memory_Strategy_Towords() = default;
	std::string Get_Query();
	bool Check(std::string Temp);
	std::string Work(std::string Ans);
};
#endif
