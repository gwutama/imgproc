#pragma once

#include <string>
#include <memory>
#include <fstream>
#include "bitmapfile.h"

class BitmapReader
{
public:
    explicit BitmapReader(const std::string& filePath);
    std::shared_ptr<BitmapFile> read();

private:
    uint32_t readHeaderSize();

    std::shared_ptr<BitmapFile> readOldFormat();
    void readOldInfoHeader(std::shared_ptr<BitmapFile>& bmpFile);

    std::shared_ptr<BitmapFile> readV5Format();
    void readV5Header(std::shared_ptr<BitmapFile>& bmpFile);

    void readFileHeader(std::shared_ptr<BitmapFile>& bmpFile);
    void readColorTable(std::shared_ptr<BitmapFile>& bmpFile, uint32_t ifsOffset);
    void readPixelData(std::shared_ptr<BitmapFile>& bmpFile, uint32_t ifsOffset);

    uint32_t calculateColorTableNumBytes(uint8_t bitDepth, uint32_t colorTableSize);
    void readBytes(char* dest, uint32_t offset, uint32_t size);

private:
    std::ifstream mIfs;
    std::string mFilePath;
};
