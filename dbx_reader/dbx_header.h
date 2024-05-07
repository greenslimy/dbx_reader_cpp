#pragma once
#include "buffer.h"

/* Header has a length of 0x24bc/9404 dec bytes.
2351 32-bit integers */
const int HeaderEntries = 0x92f;
	
/* Header Field Definition */
const uint16_t Magic = 0x0,
CLSID = 0x4,
MessageTreeNodesPtr = 0x30,
BufferLengthPtr = 0x7C,
MessageConditionsPtr = 0x88,
FolderConditionsPtr = 0x8C,
IndexedMessagesCount = 0xC4,
DeletedMessagesCount = 0xC8,
IndexedFoldersCount = 0xCC,
IndexedMessagesTreeRootPtr = 0xE4,
DeletedMessagesTreeRootPtr = 0xE8,
IndexedFoldersTreeRootPtr = 0xEC,
ConditionsBlockSize = 0x280;


/**
 * https://www.infobyte.hr/oedbx/index.html
 */
class DbxHeader {
public:
	DbxHeader(Buffer* bufferPtr);
	uint32_t GetField(uint16_t Field);

private:
	Buffer* BufferPtr;	//Point to the main buffer so we don't need to store multiple copies
	//uint32_t *Buffer;
	//void ReadHeader(std::ifstream& s) const;
};