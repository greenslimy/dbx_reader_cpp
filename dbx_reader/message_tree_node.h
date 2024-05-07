#pragma once
#include "buffer.h"

const uint8_t HeaderLength = 0xC;

								//--------	-	x---------| Is meta-data?
								//--------	-	|  x------| Seems to always be 00
/* Flag Field Definition */		//--------	-	|  |  x---| Value type?
const uint8_t					//--------	-	| _| _| __| Index
EmailId =				 0x80,	//10000000	-	1 00 00 000
FlagId =				 0x81,	//10000001	-	1 00 00 001
CreatedTime =			 0x02,	//00000010	-	0 00 00 010
/**/
MessageBodyRootPointer = 0x84,	//10000100	-	1 00 00 100
TidySubject =			 0x05,	//00000101	-	0 00 00 101
ReceivedTime =			 0x06,	//00000110	-	0 00 00 110
/**/

FullSubject =			 0x08,	//00001000	-	0 00 01 000
/**/
LongAddress =			 0x0A,	//00001010	-	0 00 01 010
/**/
/**/
SenderName =			 0x0D,	//00001101	-	0 00 01 101
SenderAddress =			 0x0E,	//00001110	-	0 00 01 110
/**/

BodyBlockCount =		 0x90,	//10010000	-	1 00 10 000
UnsureValueIndex =		 0x91,	//10010001	-	1 00 10 001
SentTime =				 0x12,	//00010010	-	0 00 10 010
RecipientName =			 0x13,	//00010011	-	0 00 10 011
RecipientAddress =		 0x14,	//00010100	-	0 00 10 100
/**/
/**/
/**/

/**/
MailAccountName =		 0x1A,	//00011010	-	0 00 11 010
MailAccountKey =		 0x1B,	//00011011	-	0 00 11 011
BuiltMessageData =		 0x1C;	//00011100	-	0 00 11 100
/**/
/**/
/**/

/* The following 17 (0x11) flags must always be present:
	0x80 - Email Identifier,
	0x81 - Some sort of flag identifier, 
	0x02 - Created Time, 
	0x84 - Message Body Root Pointer, 
	0x05 - Tidy Subject, 
	0x06 - Received Time, 
	0x08 - Full Subject, 
	0x0D - Sender Name, 
	0x0E - Sender Address, 
	0x90 - ? (Seems to always be 3), 
	0x91 - ? (Usually a larger number - 2 bytes minimum), 
	0x12 - Sent Time, 
	0x13 - Recipient Name, 
	0x14 - Recipient Address, 
	0x1A - OE Mail Account Name, 
	0x1B - OE Mail Account Key, 
	0x1C - Built message data?
*/
const struct MessageTreeNodeHeader {
	uint32_t marker;
	uint32_t length;
	uint16_t indexedLength;
	uint8_t numFlags;
	uint8_t numChanges;
};

class MessageTreeNode {
public:
	MessageTreeNodeHeader nodeHeader;
	MessageTreeNode(MessageTreeNodeHeader header, Buffer body);
	uint32_t getField(uint8_t field);
private:
	Buffer nodeData;
	uint32_t* fields;
};