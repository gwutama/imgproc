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
} __attribute__((packed));

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
} __attribute__((packed));

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-ciexyz
// https://github.com/tpn/winsdk-7/blob/master/v7.1A/Include/WinGDI.h
struct CieXyz
{
    int32_t ciexyzX;
    int32_t ciexyzY;
    int32_t ciexyzZ;
} __attribute__((packed));

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-ciexyztriple
struct CieXyzTriple
{
    CieXyz ciexyzRed;
    CieXyz ciexyzGreen;
    CieXyz ciexyzBlue;
} __attribute__((packed));

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapv5header
struct BitmapV5Header
{
    uint32_t bV5Size;
    int32_t bV5Width;
    int32_t bV5Height;
    uint16_t bV5Planes;
    uint16_t bV5BitCount;
    uint32_t bV5Compression;
    uint32_t bV5SizeImage;
    int32_t bV5XPelsPerMeter;
    int32_t bV5YPelsPerMeter;
    uint32_t bV5ClrUsed;
    uint32_t bV5ClrImportant;
    uint32_t bV5RedMask;
    uint32_t bV5GreenMask;
    uint32_t bV5BlueMask;
    uint32_t bV5AlphaMask;
    uint32_t bV5CSType;
    CieXyzTriple bV5Endpoints;
    uint32_t bV5GammaRed;
    uint32_t bV5GammaGreen;
    uint32_t bV5GammaBlue;
    uint32_t bV5Intent;
    uint32_t bV5ProfileData;
    uint32_t bV5ProfileSize;
    uint32_t bV5Reserved;
} __attribute__((packed));

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-rgbquad
struct BitmapRgbQuad
{
    // 4 bytes, 32 bit
    uint8_t rgbBlue = 0;
    uint8_t rgbGreen = 0;
    uint8_t rgbRed = 0;
    uint8_t rgbReserved = 0;
} __attribute__((packed));

enum class BitmapVersion
{
    Unknown,
    Old,
    V5
};

typedef std::vector<BitmapRgbQuad> RgbQuadArray;
const uint32_t BITMAP_FILEHEADER_SIZE = sizeof(BitmapFileHeader);
const uint32_t BITMAP_INFOHEADER_SIZE = sizeof(BitmapInfoHeader);
const uint32_t BITMAP_V5HEADER_SIZE = sizeof(BitmapV5Header);
const uint32_t BITMAP_RGBQUAD_SIZE = sizeof(BitmapRgbQuad);
