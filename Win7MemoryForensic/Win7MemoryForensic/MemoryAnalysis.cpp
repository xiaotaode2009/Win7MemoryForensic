#include "stdafx.h"
#include "MemoryAnalysis.h"
MemoryAnalysis::MemoryAnalysis(char* Filepath){
	this->filepath = Filepath;
}

//MemoryAnalysis::MemoryAnalysis(){}

MemoryAnalysis::~MemoryAnalysis(){};

int MemoryAnalysis::Open_Image(){
	if (( this->image_file = fopen( this->filepath, "rb" )) == NULL ) {
		return 1;
	}
	else return 0;
};
uint32_t MemoryAnalysis::readline(){
	this->Open_Image();
	FileRead read;
	uint32_t tmp = read.grab_32_BE(this->image_file);
	return tmp;
}
void MemoryAnalysis::Eprocess_inti(){
	this->Open_Image();

    FileRead read;
	long end_of_file;
	uint32_t data_from_memdump=0;
	uint32_t data_from_memdump2=0;
	uint32_t data_from_memdump3=0;
	fseek (this->image_file,0, SEEK_END);
	end_of_file = ftell(image_file);
	if (end_of_file < 100) 
	{
		AfxMessageBox("The Memory Image is to small");
	}	
	rewind (this->image_file);
	while (!feof(this->image_file))
	{
		int loaction1=ftell(this->image_file);
		data_from_memdump = read.grab_32_LE(this->image_file);
		data_from_memdump2 = read.grab_32_LE(this->image_file);
		if((data_from_memdump==0x00260003)&&(data_from_memdump2==0x00000000))
		{
			int loaction = ftell(this->image_file);
			fseek(this->image_file,0x10,SEEK_CUR);
			UINT32 DTB = read.grab_32_LE(this->image_file);
			fseek(this->image_file,0x98,SEEK_CUR);
			UINT32 PID = read.grab_32_LE(this->image_file);
			fseek(this->image_file,0x88,SEEK_CUR);
			UINT32 PPID = read.grab_32_LE(this->image_file);
			fseek(this->image_file,0x28,SEEK_CUR);
			char* eprocess_name = new char[15];
			for (int i = 0; i < 15; i++) eprocess_name[i] = read.grab_8_LE(this->image_file);
			fseek(this->image_file,0x2d,SEEK_CUR);
			uint32_t peb_address = read.grab_32_LE(this->image_file);
			fseek(this->image_file,0xc8,SEEK_CUR);
			data_from_memdump3 = read.grab_32_LE(this->image_file); 
			UINT32 VADroot = read.grab_32_LE(this->image_file);
			if(data_from_memdump3==0x00000103){
				PROCESS tmp;
				tmp.Eprocess_address = 
				tmp.DirectoryTableBase = DTB;
				tmp.Pid = PID;
				tmp.PPid = PPID;
				tmp.strName = eprocess_name;
				tmp.VadRootVirAddr = VADroot;
				tmp.Peb = peb_address;
				this->process_array.Add(tmp);
			}

			fseek(this->image_file,loaction,SEEK_SET);

		}
	}
	
	 fclose(this->image_file);
}


void MemoryAnalysis::DLL_printf(uint32_t InLoadOrderModuleList_Virtual,uint32_t DTB ){
	AddressTranslation address_transition;
	FileRead read;
	Moduel tmp;
	uint32_t InLoadOrderModuleList_Physical = address_transition.VirtualaddressToPhysicalAddress(InLoadOrderModuleList_Virtual,DTB);
	fseek(this->image_file,InLoadOrderModuleList_Physical,SEEK_SET);
	uint32_t Flink = read.grab_32_LE(this->image_file);
	fseek(this->image_file,0x14,SEEK_CUR);
	tmp.base = read.grab_32_LE(this->image_file);
	tmp.entryPoint = read.grab_32_LE(this->image_file);
	tmp.size = read.grab_32_LE(this->image_file);
	uint16_t Length = read.grab_16_LE(image_file);
	uint16_t MaximumLength = read.grab_16_LE(image_file);
	uint32_t Name_virtual = read.grab_32_LE(image_file);
	uint32_t Name_physical = address_transition.VirtualaddressToPhysicalAddress(Name_virtual,DTB);
	fseek(image_file,Name_physical,SEEK_SET);
	char* LoadName = new char[Length/2];
	for (int i=0;i<Length/2;i++)
	{
		LoadName[i] = read.grab_8_LE(this->image_file);
		uint8_t tmp = read.grab_8_LE(this->image_file);
	}
	int tmp2 = Length/2-1;
	LoadName[tmp2]='\0';
	tmp.path = LoadName;
	this->moduel_array.Add(tmp);
	//MessageBox(NULL,NULL,_T(LoadName),NULL);
	if(Flink !=0 && Length!=0) DLL_printf(Flink,DTB);
}


void MemoryAnalysis::Moduel_inti(int peb_virtual,int DTB){
		this->Open_Image();

	FileRead read;
	AddressTranslation address_transition;
	int location_first = ftell(image_file);
	rewind(image_file);
	/*fseek(image_file,Eprocess_address+0x1a8,SEEK_SET);
	uint32_t peb_virtual = read.grab_32_LE(this->image_file);*/
	//uint32_t peb_physical = address_transition(peb_virtual,DTB);
	uint32_t peb_physical = address_transition.VirtualaddressToPhysicalAddress(peb_virtual,DTB);
	fseek(image_file,peb_physical+0xc,SEEK_SET);
	uint32_t ldr_virtual = read.grab_32_LE(this->image_file);
	uint32_t ldr_physical = address_transition.VirtualaddressToPhysicalAddress(ldr_virtual,DTB);
	fseek(image_file,ldr_physical+0xc,SEEK_SET);
	uint32_t InLoadOrderModuleList_Virtual = read.grab_32_LE(image_file);
	//DLL_printf(InLoadOrderModuleList_Virtual,DTB);
	DLL_printf(InLoadOrderModuleList_Virtual,DTB);
}






//MemoryAnalysis memory_Analysis = MemoryAnalysis(theApp.path.GetBuffer(theApp.path.GetLength()));