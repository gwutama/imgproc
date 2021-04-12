#pragma once

#include <string>
#include <memory>
#include <fstream>
#include "bitmapfile.h"
#include "bitmapcommon.h"

class BitmapWriter
{
public:
    explicit BitmapWriter(std::shared_ptr<BitmapFile>& bmpFile);
    bool write(const std::string& filePath);

private:
    void writeFileHeader();
    void writeOldInfoHeader();

    void writeV5InfoHeader();

    void writeColorTable();
    void writePixelData();

    uint32_t calculateBitmapFileSize();
    uint32_t calculateBitmapDataOffset();

private:
    std::shared_ptr<BitmapFile> mBmpFile;
    std::ofstream mOfs;
};
