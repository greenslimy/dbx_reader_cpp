#pragma once
#include <iostream>
#include <fstream>

class Conditions {
public:
	Conditions(std::ifstream& s);

private:
	void ReadConditions(std::ifstream& s) const;
};