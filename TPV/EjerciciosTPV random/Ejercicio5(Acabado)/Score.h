#pragma once
#include "Vector.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Score
{
private:
	struct ScoreReg {
		string nom;
		int punt;
	};
	Vector<ScoreReg> scores;

public:
	Score();
	~Score();
	bool Load(const string& fileName);
	void printTopScores(uint number);
	void addScore(const string& name, uint score);
	bool save(const string& fileName);
	void muestraVector();
};

