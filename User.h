#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
class User{
private:
	vector<string> search_history;
	virtual void AddExample() = 0;
	void ClearHistory();
	void AddHistory(string Word);
};
#endif
