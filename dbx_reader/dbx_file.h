#pragma once
#include <iostream>
#include <fstream>
#include "buffer.h"
#include "dbx_header.h"
#include "dbx_database.h"
#include "conditions.h"
#include "message_tree.h"

class DbxFile {
public:
	DbxFile(std::uint8_t** buffer, size_t size);
	DbxHeader* header;
	MessageTree* indexed;
private:
	Buffer* dataBuffer;
};