#pragma once
#include <exception>
#include <iostream>
#include <string>

using namespace std;
class PacmanError: public logic_error
{
public:
	PacmanError(const char& m) : logic_error("PacmanError " + m) {};
	~PacmanError();
};

