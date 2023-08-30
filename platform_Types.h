/**
* @brief        Processor type
* @implements   CPU_TYPE_enumeration
*/

#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_
/**********************************/
#define CPU_TYPE_8   8
#define CPU_TYPE_16  16
#define CPU_TYPE_32  32
#define CPU_TYPE_64  64
/**********************************/
#define CPU_TYPE (CPU_TYPE_64)
/**********************************/
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;
#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;
typedef long double float128;
#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;
#elif (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned short long uint24;
typedef unsigned long uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed short long sint24;
typedef signed long sint32;

typedef float flaot32;
#endif
/**********************************/
#endif // _PLATFORM_TYPES_H_
