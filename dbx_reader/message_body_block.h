#pragma once
#include "buffer.h"

const struct MessageBodyBlockHeader {
	uint32_t currMarker;	//Current position of the Message Block
	uint32_t allocBytes;	//Bytes allocated to this Block (Usually 0x200)
	uint32_t usedBytes;		//Bytes actually used for data
	uint32_t nextMarker;	//Pointer to the next Message Block. If 0x00000000, this is the final Block.
};

class MessageBodyBlock {
public:
	MessageBodyBlock(MessageBodyBlockHeader header, Buffer body);
	char* getBodyData();
private:
	MessageBodyBlockHeader blockHeader;
	Buffer blockBody;
};