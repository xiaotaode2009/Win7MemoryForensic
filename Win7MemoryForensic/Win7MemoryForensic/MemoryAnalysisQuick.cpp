#include "stdafx.h"
#include "MemoryAnalysisQuick.h"
const DWORD bufSize = 12*1024*1024;
const DWORD EPROCESS_LENGTH_WIN7 = 0x2c0;
MemoryAnalysisQuick::MemoryAnalysisQuick(void)
{
	mEprocessActiveAmountWin7=0;
	pTmpBuf =  NULL;
	pTmpBuf = (char*)malloc(bufSize);	
	ppEprocessResultWin7 = new char*[100];
	for(int i=0;i<100;i++)	ppEprocessResultWin7[i] = new char[EPROCESS_LENGTH_WIN7];
}
MemoryAnalysisQuick::~MemoryAnalysisQuick(){

}

void MemoryAnalysisQuick::EprocessInit(){
	CString strImageFilePath = theApp.path;
	CFile file(strImageFilePath,CFile::modeReadWrite | CFile::shareDenyWrite);
	DWORD fileLen = file.GetLength();
	DWORD loffset(0);
	while(loffset < fileLen){
		file.Seek(loffset,CFile::begin);
		file.Read(pTmpBuf,bufSize);
		ExtractEprocessWin7(pTmpBuf,bufSize);
		memset(pTmpBuf,0,bufSize);
		loffset += bufSize;
		//TRACE("XIAOTAO");
		//CString loffset;
		//loffset.Format("%d",loffset);
		//MessageBox(NULL,loffset,"",MB_OK);
	}
	EprocessStructureInit();
}

void MemoryAnalysisQuick::ExtractEprocessWin7(const char* Memory,DWORD memLen){
		if(!(Memory&&memLen)) return;
	DWORD loops = 0;
	if(memLen>EPROCESS_LENGTH_WIN7) loops = memLen - EPROCESS_LENGTH_WIN7;		
	char pattern1[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; 
	char pattern2[] = {0xfd,0x7f};								
	char pattern3[] = {0x03,0x01,0x00,0x00};					
	int matchAmount = 0;		
	for (DWORD i=0;i<loops;i+=4096)
	{
		if(memLen>4096)  
		{
			for(int j=0;j<=4096-EPROCESS_LENGTH_WIN7;j++)  
			{
				int k;
				for(k=0;k<8;k++)					
				{
					if(Memory[i+j+0x0a8+k]==pattern1[k])  
						++matchAmount;		
					else
						break;
				}
				for(k=0;k<2;k++)
				{
					if(Memory[i+j+0x1aa+k]==pattern2[k])	
						++matchAmount;		
					else
						break;
				}
				for(k=0;k<4;k++)
				{
					if(Memory[i+j+0x274+k]==pattern3[k])	
						++matchAmount;		
					else
						break;
				}
				if (matchAmount==14)  
				{
					for(int l=0;l<EPROCESS_LENGTH_WIN7;l++)
					{
						ppEprocessResultWin7[mEprocessActiveAmountWin7][l]=Memory[i+j+l];
					}										
					mEprocessActiveAmountWin7++;	

				}
				matchAmount = 0;		
			}
		}
		else					
		{
			for(int j=0;j<=memLen-EPROCESS_LENGTH_WIN7;j++)		
			{
				int k;
				for(k=0;k<8;k++)					
				{
					if(Memory[i+j+0x0a8+k]==pattern1[k])  
						++matchAmount;		
					else
						break;
				}
				for(k=0;k<2;k++)
				{
					if(Memory[i+j+0x1aa+k]==pattern2[k])	
						++matchAmount;		
					else
						break;
				}
				for(k=0;k<4;k++)
				{
					if(Memory[i+j+0x274+k]==pattern3[k])	
						++matchAmount;		
					else
						break;
				}
				if (matchAmount==14)  
				{
					for(int l=0;l<EPROCESS_LENGTH_WIN7;l++)
					{
						ppEprocessResultWin7[mEprocessActiveAmountWin7][l] = Memory[i+j+l];
					}
					mEprocessActiveAmountWin7++;	
				}
				matchAmount = 0;		
			}
		}
		memLen = memLen - 4096; 
	}
}


void MemoryAnalysisQuick::EprocessStructureInit(){
	int mNewCount = mEprocessActiveAmountWin7;
	CString mumber;
	mumber.Format("%d",mNewCount);
	MessageBox(NULL,mumber,"",MB_OK);
	if (mNewCount<=0)
	{
		MessageBox(NULL,"进程初始化失败。","提示",MB_OK);
	}
	else
	{
		PROCESS mOneProcess;
		char* pProcessName = new char[16];
		char* tmpAddr=new char[4];
		DWORD* pTmpPageDirBase(NULL);
		DWORD* pTmpVadRootVA(NULL);
		DWORD mPid(0);
		DWORD mPPid(0);
		for (int j=0;j<mNewCount;j++)
		{
			char* pEprocessResult =ppEprocessResultWin7[j];
			pProcessName = pEprocessResult+0x16c;
			tmpAddr=pEprocessResult+0x18;
			pTmpPageDirBase=(DWORD*)tmpAddr;
			tmpAddr=pEprocessResult+0x0b4;
			mPid=*((DWORD*)tmpAddr);
			tmpAddr=pEprocessResult+0x140;
			mPPid=*((DWORD*)tmpAddr);
			tmpAddr= pEprocessResult + 0x278;	
			pTmpVadRootVA= (DWORD*)tmpAddr;
			//CString strProcessNum;
			CString strProcessName;
			//mOldCount++;
			//strProcessNum.Format("%d",mOldCount);
			strProcessName.Format("%s",pProcessName);
			mOneProcess.strName=strProcessName;
			mOneProcess.Pid=mPid;
			mOneProcess.PPid=mPPid;
			mOneProcess.DirectoryTableBase=*pTmpPageDirBase;
			mOneProcess.VadRootVirAddr=*pTmpVadRootVA;
			process_array.Add(mOneProcess);
		}
	}
}