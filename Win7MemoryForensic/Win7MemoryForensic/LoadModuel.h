#pragma once
#include "ProcessStructure.h"
class LoadModuel
{
public:
	LoadModuel(void);
	CArray<Moduel,Moduel> process_array;
	void  load_init(int PID );
	~LoadModuel(void);
};

