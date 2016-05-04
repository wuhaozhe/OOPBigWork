#ifndef NEWWORDS_STRATEGY
#define NEWWORDS_STRATEGY
#include <Database.h>
#include <User.h>
class NewWords_Strategy{
	std::vector<std::string> get_out_console;
public:
	User *Current_User;
	Database *data;
	virtual std::string GetText() = 0;
	void Run();
	NewWords_Strategy(User *temp_user, Database *temp_data);
	NewWords_Strategy() = default;
};
#endif 