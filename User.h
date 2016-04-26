#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
class User{
private:
	vector<string> search_history;
	void AddExample();
	void ClearHistory();
	void AddHistory(string Word);
};
#endif
