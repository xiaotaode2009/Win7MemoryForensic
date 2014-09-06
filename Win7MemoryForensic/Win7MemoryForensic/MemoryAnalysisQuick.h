#pragma once
#include "stdafx.h"
#include "ProcessStructure.h"
#include <afxtempl.h>
#include "Win7MemoryForensic.h"
class MemoryAnalysisQuick
{
public:
	MemoryAnalysisQuick(void);
	~MemoryAnalysisQuick();
	int mEprocessActiveAmountWin7;
	char** ppEprocessResultWin7; 
	char* pTmpBuf;
	CArray<PROCESS,PROCESS> process_array;
	void EprocessInit( );
	void ExtractEprocessWin7(const char* Memory,DWORD memLen);
	void EprocessStructureInit();
protected:

private:

};