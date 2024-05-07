#include "dbx_header.h"
#include <iostream>

DbxHeader::DbxHeader(Buffer* bufferPtr) {
    BufferPtr = bufferPtr;
    std::cout << "Database name: \"" << bufferPtr->readString(0x25C1) << "\"" << std::endl;
}

uint32_t DbxHeader::GetField(uint16_t index) {
    return BufferPtr->readInt(index);
}