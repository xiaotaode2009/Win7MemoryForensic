#pragma once


// ImageInformation �Ի���

class ImageInformation : public CDialogEx
{
	DECLARE_DYNAMIC(ImageInformation)

public:
	ImageInformation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ImageInformation();

// �Ի�������
	enum { IDD = IDD_DIALOG_IMAGEINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
