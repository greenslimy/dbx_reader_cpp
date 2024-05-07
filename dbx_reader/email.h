#pragma once
#include "message_tree_node.h"
#include "message_body_block.h"
#include <string>

class EmailMessage {
public:
	EmailMessage(MessageTreeNode* msgNode, uint8_t** fileBufferPtr);
	std::string getMessageBody();
private:
	void traverseMessageBlocks(uint32_t marker, uint8_t** fileBufferPtr, uint8_t index);
	MessageTreeNode* node;
	bool countedBlocks = false;
	uint8_t numBodyBlocks = 0;	//Blocks are <= 512 bytes in length
	uint32_t bodyLength = 0;	//Unlikely any message is > 4GB
	MessageBodyBlock** bodyBlocks;
};