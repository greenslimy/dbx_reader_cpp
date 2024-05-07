#pragma once
#include <iostream>

class Block {
	
	

public:
	uint32_t Marker;	//File position
	uint32_t Length;	//Length of this Block's buffer
	char* DataBuffer;	//Contents of this data block
	Block(uint32_t marker, uint32_t length, char* buffer);

};