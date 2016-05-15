#ifndef NEWWORDS_STRATEGY1_H 
#define NEWWORDS_STRATEGY1_H
#include "NewWords_Strategy.h"
class NewWords_Strategy1: public NewWords_Strategy{
public:
	std::string GetText(std::string Filename);
	NewWords_Strategy1(User *temp_user, Database *temp_data);
	NewWords_Strategy1() = default;
	
	~NewWords_Strategy1();
};
#endif
