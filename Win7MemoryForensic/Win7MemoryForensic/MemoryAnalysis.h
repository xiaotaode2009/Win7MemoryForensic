#pragma once
#include "stdafx.h"
#include "FileRead.h"
#include "ProcessStructure.h"
#include <afxtempl.h>
#include "Win7MemoryForensic.h"
#include "AddressTranslation.h"
class MemoryAnalysis{
public:
	MemoryAnalysis(char* Filepath);
	MemoryAnalysis();
	~MemoryAnalysis();
	uint32_t FindKpcr();
	int Open_Image();
	uint32_t readline();
	void Eprocess_inti();
	void Moduel_inti(int Eprocess_address,int DTB);
	void DLL_printf(uint32_t InLoadOrderModuleList_Virtual,uint32_t DTB);
public:
	char* filepath;
	FILE* image_file;
	CArray<PROCESS,PROCESS> process_array;
	CArray<Moduel,Moduel> moduel_array;
};
//extern MemoryAnalysis memory_Analysis;