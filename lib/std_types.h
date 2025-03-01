#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <cstdint> // Include standard fixed-width integer types

// Avoid redefining NULL if it's already defined
#ifndef NULL
#define NULL    ((void*)0)
#endif

// Boolean macros
#ifndef TRUE
#define TRUE    (1)
#endif

#ifndef FALSE
#define FALSE   (0)
#endif

// Pin state macros
#ifndef HIGH
#define HIGH    (1)
#endif

#ifndef LOW
#define LOW     (0)
#endif

// Switch state macros
#ifndef ON
#define ON      (1)
#endif

#ifndef OFF
#define OFF     (0)
#endif

// Use standard fixed-width integer types from <cstdint>
using uint8_t = std::uint8_t;
using int8_t = std::int8_t;
using uint16_t = std::uint16_t;
using int16_t = std::int16_t;
using uint32_t = std::uint32_t;
using int32_t = std::int32_t;
using uint64_t = std::uint64_t;
using int64_t = std::int64_t;

// Floating-point types
using float32_t = float;
using float64_t = double;

#endif // STD_TYPES_H_