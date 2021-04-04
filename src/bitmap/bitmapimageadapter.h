#pragma once

#include "../gsimageadapterbase.h"

class BitmapImageAdapter final : public GsImageAdapterBase
{
public:
    explicit BitmapImageAdapter(std::shared_ptr<BitmapFile> bitmapFile);
    uint8_t bitDepth() override;
    Size resolution() override;
    std::shared_ptr<ByteArray> pixelData() override;
    std::shared_ptr<ByteArray> pixelDataCopy() override;

private:
    std::shared_ptr<BitmapFile> mBitmapFile;
};
