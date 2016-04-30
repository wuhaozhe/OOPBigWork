#include "NewWords_Strategy.h"
class NewWords_Strategy1: public NewWords_Strategy{
public:
	std::string GetText();
	NewWords_Strategy1(User *temp_user, Database *temp_data);
	NewWords_Strategy1() = default;
};
