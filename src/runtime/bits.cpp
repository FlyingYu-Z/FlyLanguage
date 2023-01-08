//
// Created by flying on 2023/1/8.
//

#include "bits.h"

int32_t floatToIntBits(float f)
{
    char * c = (char*)&f;
    int32_t i = 0;
    i |= (int32_t)((c[3] << 24)     & 0xff000000);
    i |= (int32_t)((c[2] << 16)     & 0x00ff0000);
    i |= (int32_t)((c[1] << 8)      & 0x0000ff00);
    i |= (int32_t)((c[0])           & 0x000000ff);
    return i;
}