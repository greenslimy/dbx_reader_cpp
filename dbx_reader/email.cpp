#include "email.h"
#include <iostream>
#include <sstream>

EmailMessage::EmailMessage(MessageTreeNode* msgNode, uint8_t** fileBufferPtr) : node(msgNode) {
	node = msgNode;
	uint32_t rootMarker = node->getField(MessageBodyRootPointer);
	traverseMessageBlocks(rootMarker, fileBufferPtr, 0);	//Quickly traverse the list to determine the number of blocks this email has. TODO: Is there a better way of determining this?
	printf("Found %d body blocks. Total body length: %d bytes.\n", numBodyBlocks, bodyLength);
	//std::cout << "Found " << itoa(numBodyBlocks) << " body blocks." << std::endl;
	bodyBlocks = new MessageBodyBlock*[numBodyBlocks];
	countedBlocks = true;
	traverseMessageBlocks(rootMarker, fileBufferPtr, 0);	//Do it again, but this time we are initializing the blocks
}

std::string EmailMessage::getMessageBody() {
	std::stringstream ss;

	for (int block = 0;block < numBodyBlocks;block++) {
		ss << bodyBlocks[block]->getBodyData();
	}

	return ss.str();
}

void EmailMessage::traverseMessageBlocks(uint32_t marker, uint8_t** fileBufferPtr, uint8_t index) {
	MessageBodyBlockHeader header = *(MessageBodyBlockHeader*)(*fileBufferPtr + marker);
	if (header.currMarker == marker) {
		if (!countedBlocks) {
			bodyLength += header.usedBytes;
			numBodyBlocks++;
		} else {
			Buffer body(*fileBufferPtr + marker + 0x10, header.usedBytes);
			bodyBlocks[index] = new MessageBodyBlock(header, body);
		}

		if (header.nextMarker != 0x00000000) {	//There is another block, recurse until we find the end.
			traverseMessageBlocks(header.nextMarker, fileBufferPtr, index + 1);
		}
	} else {	//The markers do not match. This is an issue.
		std::cout << "Markers do not match!" << std::endl;
	}
}