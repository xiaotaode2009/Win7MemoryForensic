// ImageInformation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Win7MemoryForensic.h"
#include "ImageInformation.h"
#include "afxdialogex.h"


// ImageInformation �Ի���

IMPLEMENT_DYNAMIC(ImageInformation, CDialogEx)

ImageInformation::ImageInformation(CWnd* pParent /*=NULL*/)
	: CDialogEx(ImageInformation::IDD, pParent)
{

}

ImageInformation::~ImageInformation()
{
}

void ImageInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageInformation, CDialogEx)
	ON_BN_CLICKED(IDOK, &ImageInformation::OnBnClickedOk)
END_MESSAGE_MAP()


// ImageInformation ��Ϣ�������


void ImageInformation::OnBnClickedOk()
{
	
	
	
}
