#include "stdafx.h"
#include "fileread.h"
uint8_t FileRead::grab_8_LE(FILE *image_file) 
{
	uint8_t data_grab = 0;
	fread (&data_grab, 1, 1, image_file);
	return data_grab;
}

uint16_t FileRead::grab_16_LE(FILE *image_file)
{
	uint8_t byte1 = 0;
	uint16_t byte2 = 0;
	fread(&byte1, 1, 1, image_file);
	fread(&byte2, 1, 1, image_file);
	byte2 = byte2 << 8;
	byte2 += byte1;
	return byte2;
}

uint32_t FileRead::grab_32_LE(FILE *image_file)
{
	uint8_t byte1 = 0;
	uint8_t byte2 = 0;
	uint8_t byte3 = 0;
	uint32_t byte4 = 0;	
	fread(&byte1, 1, 1, image_file);
	fread(&byte2, 1, 1, image_file);
	fread(&byte3, 1, 1, image_file);
	fread(&byte4, 1, 1, image_file);
	byte4 = byte4 << 8;
	byte4 += byte3;
	byte4 = byte4 << 8;
	byte4 += byte2;
	byte4 = byte4 << 8;
	byte4 += byte1;
	return byte4;
}

uint32_t FileRead::grab_32_BE(FILE *image_file)
{
	uint32_t byte1 = 0;
	uint8_t byte2 = 0;
	uint8_t byte3 = 0;
	uint8_t byte4 = 0;
	fread(&byte1, 1, 1, image_file);
	fread(&byte2, 1, 1, image_file);
	fread(&byte3, 1, 1, image_file);
	fread(&byte4, 1, 1, image_file);
	byte1 = byte1 << 8;
	byte1 += byte2;
	byte1 = byte1 << 8;
	byte1 += byte3;
	byte1 = byte1 << 8;
	byte1 += byte4;
	return byte1;
}

uint64_t FileRead::grab_64_LE(FILE *image_file)
{
	uint8_t byte1 = 0;
	uint8_t byte2 = 0;
	uint8_t byte3 = 0;
	uint8_t byte4 = 0;
	uint8_t byte5 = 0;
	uint8_t byte6 = 0;
	uint8_t byte7 = 0;
	uint64_t byte8 = 0;
	fread(&byte1, 1, 1, image_file);
	fread(&byte2, 1, 1, image_file);
	fread(&byte3, 1, 1, image_file);
	fread(&byte4, 1, 1, image_file);
	fread(&byte5, 1, 1, image_file);
	fread(&byte6, 1, 1, image_file);
	fread(&byte7, 1, 1, image_file);
	fread(&byte8, 1, 1, image_file);
	byte8 = byte8 << 8;
	byte8 += byte7;
	byte8 = byte8 << 8;
	byte8 += byte6;
	byte8 = byte8 << 8;
	byte8 += byte5;
	byte8 = byte8 << 8;
	byte8 += byte4;
	byte8 = byte8 << 8;
	byte8 += byte3;
	byte8 = byte8 << 8;
	byte8 += byte2;
	byte8 = byte8 << 8;
	byte8 += byte1;
	return byte8;
}


uint64_t FileRead::grab_64_BE(FILE *image_file)
{	
	uint64_t byte1 = 0;
	uint8_t byte2 = 0;
	uint8_t byte3 = 0;
	uint8_t byte4 = 0;
	uint8_t byte5 = 0;
	uint8_t byte6 = 0;
	uint8_t byte7 = 0;
	uint8_t byte8 = 0;
	fread(&byte1, 1, 1, image_file);
	fread(&byte2, 1, 1, image_file);
	fread(&byte3, 1, 1, image_file);
	fread(&byte4, 1, 1, image_file);
	fread(&byte5, 1, 1, image_file);
	fread(&byte6, 1, 1, image_file);
	fread(&byte7, 1, 1, image_file);
	fread(&byte8, 1, 1, image_file);
	byte1 = byte1 << 8;
	byte1 += byte2;
	byte1 = byte1 << 8;
	byte1 += byte3;
	byte1 = byte1 << 8;
	byte1 += byte4;
	byte1 = byte1 << 8;
	byte1 += byte5;
	byte1 = byte1 << 8;
	byte1 += byte6;
	byte1 = byte1 << 8;
	byte1 += byte7;
	byte1 = byte1 << 8;
	byte1 += byte8;
	return byte1;
}
