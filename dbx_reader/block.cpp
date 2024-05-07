#include "block.h"

using namespace std;

Block::Block(uint32_t marker, uint32_t length, char* buffer) {
	Marker = marker;
	Length = length;
	DataBuffer = buffer;
}