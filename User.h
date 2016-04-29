#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
class User{
private:
	vector<string> search_history;
	void Add_Example();
	void Clear_History();
	void Add_History(string Word);
};
#endif
