// AddressTranslation.cpp : 实现文件
//

#include "stdafx.h"
#include "Win7MemoryForensic.h"
#include "AddressTranslation.h"
#include "afxdialogex.h"
#include "windows.h"
#include "string"
using std::string;



// AddressTranslation 对话框

IMPLEMENT_DYNAMIC(AddressTranslation, CDialogEx)

AddressTranslation::AddressTranslation(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddressTranslation::IDD, pParent)
{

	m_virtual_address = _T("");
	m_physical_address = _T("");
	m_dtb = _T("");
}

AddressTranslation::~AddressTranslation()
{
}

void AddressTranslation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_VIRTUAL_ADDRESS, m_virtual_address);
	DDV_MaxChars(pDX, m_virtual_address, 30);
	DDX_Text(pDX, IDC_EDIT_PHYSICAL_ADDRESS, m_physical_address);
	DDV_MaxChars(pDX, m_physical_address, 30);
	DDX_Text(pDX, IDC_EDIT_DTB, m_dtb);
	DDV_MaxChars(pDX, m_dtb, 30);
}


BEGIN_MESSAGE_MAP(AddressTranslation, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddressTranslation::OnBnClickedOk)
END_MESSAGE_MAP()


// AddressTranslation 消息处理程序


void AddressTranslation::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	uint32_t Virtual_Address = 0;
	uint32_t DTB = 0;
	CString str1,str2;
	GetDlgItemText(IDC_EDIT_VIRTUAL_ADDRESS,str1);
	GetDlgItemText(IDC_EDIT_DTB,str2);
	//Virtual_Address = strtol(str1, NULL, 16);
	char* VAddress = (LPSTR)(LPCTSTR)str1;
	Virtual_Address = StringToHex(VAddress);
	//int size=sizeof(uint32_t);
	DTB = strtol(str2, NULL, 16);
	/*char *path = theApp.path.GetBuffer(theApp.path.GetLength());
	FILE* image_file = fopen( path, "rb" );
	uint32_t pde_address = DTB+((Virtual_Address&0xffc00000)>>20);
	fseek(image_file,pde_address,SEEK_SET);
	uint32_t pde = read.grab_32_LE(image_file);
	uint32_t pte_address = (pde&0xfffff000)+((Virtual_Address&0x003ff000)>>10);
	fseek(image_file,pte_address,SEEK_SET);
	uint32_t	PTE = read.grab_32_LE(image_file);
	uint32_t physcial_address = (PTE&0xfffff000)+(Virtual_Address&0x00000fff);*/
	uint32_t physcial_address = VirtualaddressToPhysicalAddress(Virtual_Address,DTB);
	CString Str;
	Str.Format("%x",physcial_address);
	//Str.Fomat(“%d”,physcial_address);
	SetDlgItemText(IDC_EDIT_PHYSICAL_ADDRESS,Str);

	//SetDlgItemText(IDC_EDIT_PHYSICAL_ADDRESS,str1
}

uint32_t AddressTranslation::VirtualaddressToPhysicalAddress(uint32_t Virtual_Address,uint32_t DTB){

	char *path = theApp.path.GetBuffer(theApp.path.GetLength());
	FILE* image_file = fopen( path, "rb" );
	FileRead read;
	uint32_t pde_address = DTB+((Virtual_Address&0xffc00000)>>20);
	fseek(image_file,pde_address,SEEK_SET);
	uint32_t pde = read.grab_32_LE(image_file);
	uint32_t pte_address = (pde&0xfffff000)+((Virtual_Address&0x003ff000)>>10);
	fseek(image_file,pte_address,SEEK_SET);
	uint32_t	PTE = read.grab_32_LE(image_file);
	uint32_t physcial_address = (PTE&0xfffff000)+(Virtual_Address&0x00000fff);
	return physcial_address;
		fclose(image_file);
}

uint32_t  AddressTranslation::StringToHex(char* str){
	uint32_t	result = 0;
	string str2 = str;
	for(int i=0;i<str2.length();i++){
		char tmp = str2[i];
		if(tmp>='0'&&tmp<='9') result = result*16 + tmp - '0';
		else if(tmp>='A'&&tmp<='Z') result= result*16+ tmp - 'A' + 10;
		else if(tmp>='a'&&tmp<='z')  result= result*16 + tmp - 'a' + 10;
		else return 0;
	}
	return result;
}