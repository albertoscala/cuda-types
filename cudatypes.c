#include "cudatypes.h"

// half_t conversions

half_t half_from_int(int x)
{
    
}

//TODO: Final subnormal logic
//TODO: Rounding
//TODO: Overflow -> INF
//TODO: Underflow -> subnormal/zero

half_t half_from_float(float x)
{
    // Return value
    uint16_t b_bytes = 0x0;

    // Get float bytes
    uint32_t a_bytes;
    memcpy(&a_bytes, &x, sizeof(float));

    // Decompose float
    uint32_t a_sign = a_bytes >> 31;
    uint32_t a_exp = (a_bytes >> 23) & 0xFF;
    uint32_t a_mantissa = a_bytes & 0x7FFFFF;

    // Special cases

    // INF or NaN
    if (a_exp == 255)
    {
        if (a_mantissa == 0)
        {
            b_bytes |= (a_sign & 0x1) << 15;
            b_bytes |= INF;
            return (half_t) b_bytes;
        }
        else
        {   //TODO: Improving to Signaling NaN (sNaN)
            b_bytes |= (a_sign & 0x1) << 15;
            b_bytes |= 0x7C00;
            b_bytes |= 0x0200;  // Quiet NaN (qNaN)
            return (half_t) b_bytes;
        }
    }

    // Zero
    if (a_exp == 0)
    {
        if (a_mantissa == 0)
        {
            b_bytes |= (a_sign & 0x1) << 15;
            b_bytes |= 0x0000;
        }
        else
        {   //TODO: Handle float subnormal

        }
    }

    // Exponent conversion

    // Removing the bias
    a_exp -= 127;
    // Adding new bias
    a_exp += 15;

    // Mantissa conversion
    a_mantissa >>= 13;

    // Recomposing the number
    b_bytes |= (a_sign & 0x1) << 15;
    b_bytes |= (a_exp & 0x1F) << 10;
    b_bytes |= a_mantissa;

    return (half_t) b_bytes;
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
