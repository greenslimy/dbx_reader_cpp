#pragma once
#include <stdint.h>

class Buffer {
public:
	Buffer(uint8_t* bytes, size_t length);
	uint8_t* getBytePtr(size_t offset);
	uint8_t* readBytes(size_t offset, size_t length);
	uint32_t readInt(size_t offset);
	uint64_t readLong(size_t offset);
	char* readString(size_t offset);
private:
	uint8_t* buffer;
	size_t size;
};