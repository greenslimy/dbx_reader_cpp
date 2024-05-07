#include "message_tree.h"
#include <iostream>

MessageTree::MessageTree(Buffer* buffer, uint32_t indexedMessagesTreePtr, uint32_t databaseEntries) {
	dataBuffer = buffer;
	nodePtrs = new MessageTreeNode*[databaseEntries];

	ReadMessageTree(indexedMessagesTreePtr, databaseEntries);
}

MessageTreeNode* MessageTree::getNode(uint32_t nodeIndex) {
	return nodePtrs[nodeIndex];
}

void MessageTree::ReadMessageTree(uint32_t indexedMessagesTreePtr, uint32_t entries) const {
	for (int entryIndex = 0;entryIndex < entries;entryIndex++) {
		uint32_t tableMarker = dataBuffer->readInt((indexedMessagesTreePtr + 0x18) + (entryIndex * HeaderLength));
		MessageTreeNodeHeader header = *(MessageTreeNodeHeader*)dataBuffer->readBytes(tableMarker, HeaderLength);
		if (header.marker != tableMarker) {	//Break before body if the length is too high
			printf("Error @ %d, header too long: %d\n", entryIndex, header.length);
			break;
		}
		Buffer body(dataBuffer->readBytes(tableMarker + HeaderLength, header.length), header.length);
		MessageTreeNode* node = new MessageTreeNode(header, body);
		nodePtrs[entryIndex] = node;
		//std::cout << "Email id: " << *(uint32_t*)node->getFieldPtr(EmailId) << std::endl;
		//std::cout << "Email subject: " << body.readString(tableMarker + *node->getFieldPtr(TidySubject)) << std::endl;
	}
}