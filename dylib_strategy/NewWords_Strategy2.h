#ifndef NEWWORDS_STRATEGY2_H
#define NEWWORDS_STRATEGY2_H
#include "NewWords_Strategy.h"
#include <fstream>
class NewWords_Strategy2: public NewWords_Strategy{
public:
	std::string GetText(std::string Filename);
	NewWords_Strategy2(User *temp_user, Database *temp_data);
	NewWords_Strategy2() = default;
};
#endif
