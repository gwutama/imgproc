#include "bitmapfile.h"
#include <fstream>
#include <cmath>
#include <iostream>

std::shared_ptr<BitmapFile> BitmapFile::fromFile(const std::string &filePath)
{
    std::ifstream ifs(filePath, std::ifstream::in | std::ifstream::binary);

    if (!ifs)
    {
        std::cout << "Unable to read file: " << filePath << std::endl;
        return {};
    }

    auto bmpFile = std::shared_ptr<BitmapFile>(new BitmapFile);
    bmpFile->mFileName = filePath;

    // read bitmap file header
    char bitmapFileHeader[BITMAP_FILEHEADER_SIZE];
    ifs.read(bitmapFileHeader, BITMAP_FILEHEADER_SIZE);
    auto fileHeaderRef = bmpFile->getFileHeader();
    memcpy(fileHeaderRef.get(), bitmapFileHeader, BITMAP_FILEHEADER_SIZE);

    // read bitmap info header
    uint32_t ifsOffset = BITMAP_FILEHEADER_SIZE;
    char bitmapInfoHeader[BITMAP_INFOHEADER_SIZE];
    ifs.seekg(ifsOffset, ifs.beg);
    ifs.read(bitmapInfoHeader, BITMAP_INFOHEADER_SIZE);
    auto infoHeaderRef = bmpFile->getInfoHeader();
    memcpy(infoHeaderRef.get(), bitmapInfoHeader, BITMAP_INFOHEADER_SIZE);

    if (infoHeaderRef->biBitCount != 8 &&
        infoHeaderRef->biBitCount != 16)
    {
        std::cout << "Unsupported bit count: " << infoHeaderRef->biBitCount << std::endl;
        return {};
    }

    // read color table
    ifsOffset = ifsOffset + BITMAP_INFOHEADER_SIZE;
    auto colorTableSize = infoHeaderRef->biClrUsed;

    // Calculate default color table size if it is set to 0
    if (colorTableSize == 0)
    {
        colorTableSize = pow(2, infoHeaderRef->biBitCount);
    }

    auto colorTableNumBytes = colorTableSize * BITMAP_RGBQUAD_SIZE;
    bmpFile->mColorTable->reserve(colorTableNumBytes);

    for (int i = 0; i < colorTableNumBytes; i = i + 4)
    {
        BitmapRgbQuad rgbQuad{};
        char buffer[BITMAP_RGBQUAD_SIZE];
        ifs.seekg(ifsOffset + i, ifs.beg);
        ifs.read(buffer, BITMAP_RGBQUAD_SIZE);
        memcpy(&rgbQuad, buffer, BITMAP_RGBQUAD_SIZE);
        bmpFile->mColorTable->push_back(rgbQuad);
    }

    // read pixel data
    auto pixelSize = infoHeaderRef->biWidth * infoHeaderRef->biHeight;
    auto pixelDataNumBytes = pixelSize * (infoHeaderRef->biBitCount / 8);
    auto pixelDataRef = bmpFile->getPixelData();
    pixelDataRef->reserve(pixelDataNumBytes);

    ifsOffset = ifsOffset + colorTableNumBytes;
    ifs.seekg(ifsOffset, ifs.beg);

    for (int i = 0; i < pixelDataNumBytes; i++)
    {
        int c = ifs.get();
        auto b = static_cast<uint8_t>(c);
        pixelDataRef->push_back(b);
    }

    ifs.close();

    return bmpFile;
}


bool BitmapFile::write()
{
    return write(mFileName);
}


bool BitmapFile::write(const std::string &path)
{
    std::ofstream ofs(path, std::ofstream::out | std::ofstream::binary);

    if (!ofs)
    {
        std::cout << "Unable to write file: " << path << std::endl;
        return false;
    }

    // Write file header
    char fileHeader[BITMAP_FILEHEADER_SIZE];
    memcpy(fileHeader, mFileHeader.get(), BITMAP_FILEHEADER_SIZE);
    ofs.write(fileHeader, BITMAP_FILEHEADER_SIZE);

    // Write info header
    char infoHeader[BITMAP_INFOHEADER_SIZE];
    memcpy(infoHeader, mInfoHeader.get(), BITMAP_INFOHEADER_SIZE);
    ofs.write(infoHeader, BITMAP_INFOHEADER_SIZE);

    // Write color table
    auto iter = mColorTable->begin();

    while (iter != mColorTable->end())
    {
        char buffer[4]
        {
            static_cast<char>(iter->rgbBlue),
            static_cast<char>(iter->rgbGreen),
            static_cast<char>(iter->rgbRed),
            static_cast<char>(iter->rgbReserved)
        };
        ofs.write(buffer, BITMAP_RGBQUAD_SIZE);
        iter++;
    }

    // Write pixel data
    auto iter2 = mPixelData->begin();

    while (iter2 != mPixelData->end())
    {
        char c = static_cast<char>(*iter2);
        ofs.write(&c, 1);
        iter2++;
    }

    ofs.close();

    return true;
}
