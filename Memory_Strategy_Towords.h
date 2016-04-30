#ifndef MEMORY_STRATEGY_TOWORDS
#define MEMORY_STRATEGY_TOWORDS
#include "Memory_Strategy.h"
class Memory_Strategy_Towords: public Memory_Strategy{
public:
	Memory_Strategy_Towords(User *temp_user, Database *temp_data);
	Memory_Strategy_Towords() = default;
};
#endif
