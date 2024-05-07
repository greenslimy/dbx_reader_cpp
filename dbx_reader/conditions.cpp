#include "conditions.h"

using namespace std;

char* ConditionData;

Conditions::Conditions(ifstream& s) {
	ReadConditions(s);
}

void Conditions::ReadConditions(ifstream& s) const {
	uint32_t marker;
	uint32_t length;
	
	s.read((char*)&marker, 4);
	s.read((char*)&length, 4);

	ConditionData = new char[length];
	s.read(ConditionData, length);
}