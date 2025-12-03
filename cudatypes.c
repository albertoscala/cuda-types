#include "cudatypes.h"

// half_t conversions

half_t half_from_int(int x)
{

}

half_t half_from_float(float x)
{
    // Get float bytes
    uint32_t a_bytes;
    memcpy(&a_bytes, &x, sizeof(float));

    // Decompose float
    uint32_t a_sign = a_bytes >> 31;
    uint32_t a_exp = (a_bytes >> 23) & 0xFF;
    uint32_t a_mantissa = a_bytes & 0x7FFFFF;

    // Exponent conversion

    // Removing the bias
    a_exp -= 127;
    // Adding new bias
    a_exp += 15;

    // Mantissa conversion
    a_mantissa >>= 13;

    // Encoding
    half_t h_x;
    uint16_t b_bytes = 0x0;

    // Recomposing the number
    b_bytes |= (a_sign & 0x1) << 15;
    b_bytes |= (a_exp & 0x1F) << 10;
    b_bytes |= a_mantissa;

    memcpy(&h_x, &b_bytes, sizeof(half_t));
    return h_x;
}

half_t half_from_double(double x)
{

}


// bfloat16_t conversions

bfloat16_t bfloat16_from_int(int x)
{

}

bfloat16_t bfloat16_from_float(float x)
{

}

bfloat16_t bfloat16_from_double(double x)
{

}

// tf32_t conversions

tf32_t tf32_from_int(int x)
{

}

tf32_t tf32_from_float(float x)
{

}

tf32_t tf32_from_double(double x)
{

}
