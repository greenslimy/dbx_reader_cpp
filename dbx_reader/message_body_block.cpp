#include "message_body_block.h"

MessageBodyBlock::MessageBodyBlock(MessageBodyBlockHeader header, Buffer body) : blockBody(body) {
	blockHeader = header;
}

char* MessageBodyBlock::getBodyData() {
	return blockBody.readString(0);	//No NULL bytes should be present in the body's data
}