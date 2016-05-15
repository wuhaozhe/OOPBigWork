#ifndef OUTPUT_SCREEN_H
#define OUTPUT_SCREEN_H
#include <iostream>
#include "Output.h"
class Output_Screen: public Output{
public:
	void Print(std::string Str);
};
#endif 
