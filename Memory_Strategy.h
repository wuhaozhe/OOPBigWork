#ifndef MEMORY_STRATEGY
#define MEMORY_STRATEGY
#include "User.h"
#include "Database.h"
class Memory_Strategy{
public:
	User *Current_User;
	Database *data;
	void Run();
	Memory_Strategy(User *temp_user, Database *temp_data);
	Memory_Strategy() = default;
};
#endif
