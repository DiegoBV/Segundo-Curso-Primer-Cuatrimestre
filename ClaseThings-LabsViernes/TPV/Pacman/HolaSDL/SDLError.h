#pragma once
#include "PacManError.h"
class SDLError: public PacmanError
{
public:
	SDLError(const char& m) : PacmanError(m) {};
	~SDLError();
};

