#pragma once


// ImageFileOpen �Ի���

class ImageFileOpen : public CDialogEx
{
	DECLARE_DYNAMIC(ImageFileOpen)

public:
	ImageFileOpen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ImageFileOpen();

// �Ի�������
	enum { IDD = IDD_DIALOG_OPEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
