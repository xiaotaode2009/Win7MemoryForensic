#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Load_Moduel{
	DWORD base;
	DWORD size;
	DWORD entryPoint;
	CString path;
}Moduel;

typedef struct _PROCESS_STRUCT
{
	DWORD Eprocess_address;
	CString strName;
	DWORD DirectoryTableBase;
	DWORD VadRootVirAddr;
	DWORD Pid;
	DWORD PPid;
	DWORD Peb;
	//CArray<Moduel&,Moduel&> LoadModule;
}PROCESS;
