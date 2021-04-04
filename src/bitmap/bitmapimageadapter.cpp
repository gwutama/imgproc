#include "bitmapimageadapter.h"

BitmapImageAdapter::BitmapImageAdapter(std::shared_ptr<BitmapFile> bitmapFile) :
    mBitmapFile(bitmapFile)
{
}


uint8_t BitmapImageAdapter::bitDepth()
{
    return mBitmapFile->getInfoHeader()->biBitCount;
}


Size BitmapImageAdapter::resolution()
{
    auto header = mBitmapFile->getInfoHeader();

    Size s
    {
        static_cast<uint32_t>(header->biWidth),
        static_cast<uint32_t>(header->biHeight)
    };

    return s;
}


std::shared_ptr<ByteArray> BitmapImageAdapter::pixelData()
{
    return mBitmapFile->getPixelData();
}


std::shared_ptr<ByteArray> BitmapImageAdapter::pixelDataCopy()
{
    auto copy = std::shared_ptr<ByteArray>(new ByteArray);
    auto pixelData = mBitmapFile->getPixelData();
    auto iter = pixelData->begin();

    while (iter != pixelData->end())
    {
        auto data = *iter;
        copy->push_back(data);
        iter++;
    }

    return copy;
}