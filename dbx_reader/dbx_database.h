#pragma once
#include <iostream>
#include <fstream>
#include <string>

const std::string SOURCE_TYPES[4] = {"Newsgroups", "IMAP", "[Unknown 2]", "Local Folder"};

class DbxDatabase {
public:
	DbxDatabase(std::ifstream& s, int bufferSize);
	char* GetFolderName();
	uint8_t GetSourceType();

private:
	uint8_t* Buffer;
	void ReadDatabase(std::ifstream& s, int bufferSize) const;
};