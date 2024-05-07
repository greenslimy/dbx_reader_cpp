#pragma once
#include "message_tree_node.h"

class MessageTree {
public:
	MessageTree(Buffer* buffer, uint32_t indexedMessagesTreePtr, uint32_t databaseEntries);
	MessageTreeNode* getNode(uint32_t nodeIndex);
private:
	Buffer* dataBuffer;
	MessageTreeNode** nodePtrs;
	void ReadMessageTree(uint32_t indexedMessagesTreePtr, uint32_t databaseEntries) const;
};