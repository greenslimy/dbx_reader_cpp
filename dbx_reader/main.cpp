#include <iostream>
#include <fstream>
#include "dbx_file.h"
#include "email.h"

void getSelection(DbxFile* file, uint8_t** buffer) {
    uint32_t entries = file->header->GetField(IndexedMessagesCount);
    uint32_t selected = 0;
    std::cout << "Which email would you like to inspect? [0-" << entries << "]: ";
    std::cin >> selected;

    if (selected >= 0 && selected <= entries) {
        std::cout << "Selected: " << selected << std::endl;
        EmailMessage message(file->indexed->getNode(selected), buffer);
        std::cout << message.getMessageBody();

        getSelection(file, buffer);
    }
    else {
        std::cout << "Invalid selection" << std::endl;
        getSelection(file, buffer);
    }
}

int main(int argc, char* argsv[])
{
    if (argc > 1) {
        std::ifstream file;
        file.open(argsv[1], std::ios::binary | std::ios::ate);

        size_t fileSize = 0;
        if (file.is_open()) {
            fileSize = file.tellg();
            file.seekg(0, std::ios::beg);
            uint8_t* buffer = new uint8_t[fileSize];
            file.read((char*)buffer, fileSize);
            file.close();

            DbxFile dbx(&buffer, fileSize);
            getSelection(&dbx, &buffer);
        } else {
            std::cout << "Unable to open file!";
        }
    } else {
        std::cout << "You must supply a .dbx file path to read." << std::endl;
    }
}

