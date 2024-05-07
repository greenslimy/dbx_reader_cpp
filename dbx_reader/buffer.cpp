#include "buffer.h"
#include <iostream>

Buffer::Buffer(uint8_t* bytes, size_t length)  {
    buffer = new uint8_t[length + 1];
    memcpy(buffer, bytes, length);
    buffer[length] = '\0';
    this->size = length;
}

uint8_t* Buffer::getBytePtr(size_t offset) {
    return (buffer + offset);
}

//Reads [length] bytes from the stream, starting at [offset]
uint8_t* Buffer::readBytes(size_t offset, size_t length) {
    uint8_t* data = new uint8_t[length];
    data = (buffer + offset);

    return data;
}

//Reads a 32-bit integer from the stream
uint32_t Buffer::readInt(size_t offset) {
    return *(uint32_t*)(buffer + offset);
}

//Reads a 64-bit long (8 bytes) from the stream
uint64_t Buffer::readLong(size_t offset) {
    return *(uint64_t*)(buffer + offset);
}

//Reads a C-String (NULL-terminated) from the position in the buffer
char* Buffer::readString(size_t offset) {
    return (char*)(buffer + offset);
}