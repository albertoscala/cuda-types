#include <stdint.h>
#include <string.h>

// #define PRIh16
// #define PRIbf16 
// #define PRItf32

// Utility masks

#define INF 0x7C00

// Constructors

#define HALF(x) _Generic((x),   \
    int: half_from_int,         \
    float: half_from_float,     \
    double: half_from_double    \
)(x)

#define BFLOAT16(x) _Generic((x),   \
    int: bfloat16_from_int,         \
    float: bfloat16_from_float,     \
    double: bfloat16_from_double    \
)(x)

#define TF32(x) _Generic((x),   \
    int: tf32_from_int,         \
    float: tf32_from_float,     \
    double: tf32_from_double    \
)(x)

// Type definitions

typedef uint16_t half_t;
typedef uint16_t bfloat16_t;
typedef uint32_t tf32_t;

// half_t conversions

half_t half_from_int(int x);
half_t half_from_float(float x);
half_t half_from_double(double x);

// bfloat16_t conversions

bfloat16_t bfloat16_from_int(int x);
bfloat16_t bfloat16_from_float(float x);
bfloat16_t bfloat16_from_double(double x);

// tf32_t conversions

tf32_t tf32_from_int(int x);
tf32_t tf32_from_float(float x);
tf32_t tf32_from_double(double x);
