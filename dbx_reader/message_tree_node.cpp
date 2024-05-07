#include "message_tree_node.h"

//const std::string DAYS[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
//const std::string MONTHS[12] = { "December", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" };

MessageTreeNode::MessageTreeNode(MessageTreeNodeHeader header, Buffer body) : nodeData(body) {
	nodeHeader = header;
	fields = new uint32_t[32];
	
	for (int f = 0;f < header.numFlags;f++) {
		uint32_t flag = body.readInt(f * sizeof(uint32_t));
		uint8_t index =   flag & 0x0000001F;
		uint32_t value = (flag & 0xFFFFFF00) >> 8;

		fields[index] = value;
	}
}

uint32_t MessageTreeNode::getField(uint8_t field) {
	return fields[field & 0x1F];
}