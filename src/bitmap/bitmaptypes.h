#pragma once

#include <vector>
#include "common.h"


// https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-storage
// https://docs.microsoft.com/en-us/windows/win32/winprog/windows-data-types

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapfileheader
struct BitmapFileHeader
{
    // 14 bytes
    uint16_t bfType = 19778; // BM
    uint32_t bfSize = 0;
    uint16_t bfReserved1 = 0;
    uint16_t bfReserved2 = 0;
    uint32_t bfOffBits = 0;
}__attribute__((packed));

// https://docs.microsoft.com/en-us/previous-versions//dd183376(v=vs.85)
// https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-header-types
// https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-wmf/4e588f70-bd92-4a6f-b77f-35d0feaf7a57
struct BitmapInfoHeader
{
    // 40 bytes
    uint32_t biSize = 40;
    int32_t biWidth = 0;
    int32_t biHeight = 0;
    uint16_t biPlanes = 1;
    uint16_t biBitCount = 0;
    uint32_t biCompression = 0;
    uint32_t biSizeImage = 0;
    int32_t biXPelsPerMeter = 0;
    int32_t biYPelsPerMeter = 0;
    uint32_t biClrUsed = 0;
    uint32_t biClrImportant = 0;
}__attribute__((packed));

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-rgbquad
struct BitmapRgbQuad
{
    // 4 bytes, 32 bit
    uint8_t rgbBlue = 0;
    uint8_t rgbGreen = 0;
    uint8_t rgbRed = 0;
    uint8_t rgbReserved = 0;
}__attribute__((packed));

typedef std::vector<BitmapRgbQuad> RgbQuadArray;

const uint32_t BITMAP_FILEHEADER_SIZE = sizeof(BitmapFileHeader);
const uint32_t BITMAP_INFOHEADER_SIZE = sizeof(BitmapInfoHeader);
const uint32_t BITMAP_RGBQUAD_SIZE = sizeof(BitmapRgbQuad);
