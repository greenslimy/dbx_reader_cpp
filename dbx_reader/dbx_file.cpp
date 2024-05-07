#include "dbx_file.h"

DbxFile::DbxFile(std::uint8_t** buffer, size_t size) {
    dataBuffer = new Buffer(*buffer, size);
    header = new DbxHeader(dataBuffer);
    uint32_t entries = header->GetField(IndexedMessagesCount);
    indexed = new MessageTree(
        dataBuffer, 
        header->GetField(MessageTreeNodesPtr),
        entries);

    
}

