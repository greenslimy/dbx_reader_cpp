#include "dbx_database.h"

using namespace std;

DbxDatabase::DbxDatabase(ifstream& s, int bufferSize) {
	Buffer = new uint8_t[bufferSize];
	ReadDatabase(s, bufferSize);

	cout << "Reading \"" << GetFolderName() << "\" database." << endl;
	cout << "Source type: " << SOURCE_TYPES[GetSourceType()] << endl;
}

void DbxDatabase::ReadDatabase(ifstream& s, int bufferSize) const {
	s.read((char*)Buffer, bufferSize);
}

char* DbxDatabase::GetFolderName() {
	return (char*)(Buffer + 0x105);
}

uint8_t DbxDatabase::GetSourceType() {
	return *(Buffer + 0x4);
}