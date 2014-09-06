#ifndef __PROCESS_H__
#define __PROCESS_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned __int64 uint64_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t;
typedef signed __int64 int64_t;
class FileRead{
public:
	uint8_t grab_8_LE(FILE *image_file);
	uint16_t grab_16_LE(FILE *image_file);
	uint32_t grab_32_LE(FILE *image_file);
	uint32_t grab_32_BE(FILE *image_file);
	uint64_t grab_64_LE(FILE *image_file);
	uint64_t grab_64_BE(FILE *image_file);
};
#endif
