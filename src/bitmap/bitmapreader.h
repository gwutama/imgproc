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
    void readFileHeader(std::shared_ptr<BitmapFile>& bmpFile);
    void readOldInfoHeader(std::shared_ptr<BitmapFile>& bmpFile);
    void readOldColorTable(std::shared_ptr<BitmapFile>& bmpFile);
    void readOldPixelData(std::shared_ptr<BitmapFile>& bmpFile);

    std::shared_ptr<BitmapFile> readV5Format();

    uint32_t calculateColorTableNumBytes(uint8_t bitDepth, uint32_t colorTableSize);
    void readBytes(char* dest, uint32_t offset, uint32_t size);

private:
    std::ifstream mIfs;
    std::string mFilePath;
};
