#pragma once

#include <vector>
#include "common.h"

#define BITMAP_FILEHEADER_SIZE 14
#define BITMAP_INFOHEADER_SIZE 40
#define BITMAP_RGBQUAD_SIZE 4

// https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-storage
// https://docs.microsoft.com/en-us/windows/win32/winprog/windows-data-types

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapfileheader
struct BitmapFileHeader
{
    // 14 bytes
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

// https://docs.microsoft.com/en-us/previous-versions//dd183376(v=vs.85)
// https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-header-types
struct BitmapInfoHeader
{
    // 40 bytes
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-rgbquad
struct BitmapRgbQuad
{
    // 4 bytes, 16 bit
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
    uint8_t rgbReserved;
};

typedef std::vector<BitmapRgbQuad> RgbQuadArray;
