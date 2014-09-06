#pragma once
#include "MemoryAnalysis.h"
#include "FileRead.h"


// AddressTranslation �Ի���

class AddressTranslation : public CDialogEx
{
	DECLARE_DYNAMIC(AddressTranslation)

public:
	AddressTranslation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddressTranslation();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDRESSTRANSLATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	uint32_t StringToHex(char* str);
	uint32_t VirtualaddressToPhysicalAddress(uint32_t Virtual_Address,uint32_t DTB);
	CString m_virtual_address;
	CString m_physical_address;
	CString m_dtb;
};
