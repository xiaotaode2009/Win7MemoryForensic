
// Win7MemoryForensicView.cpp : CWin7MemoryForensicView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Win7MemoryForensic.h"
#endif

#include "Win7MemoryForensicDoc.h"
#include "Win7MemoryForensicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWin7MemoryForensicView

IMPLEMENT_DYNCREATE(CWin7MemoryForensicView, CView)

BEGIN_MESSAGE_MAP(CWin7MemoryForensicView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWin7MemoryForensicView ����/����

CWin7MemoryForensicView::CWin7MemoryForensicView()
{
	// TODO: �ڴ˴���ӹ������

}

CWin7MemoryForensicView::~CWin7MemoryForensicView()
{
}

BOOL CWin7MemoryForensicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CWin7MemoryForensicView ����

void CWin7MemoryForensicView::OnDraw(CDC* /*pDC*/)
{
	CWin7MemoryForensicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CWin7MemoryForensicView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWin7MemoryForensicView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWin7MemoryForensicView ���

#ifdef _DEBUG
void CWin7MemoryForensicView::AssertValid() const
{
	CView::AssertValid();
}

void CWin7MemoryForensicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWin7MemoryForensicDoc* CWin7MemoryForensicView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWin7MemoryForensicDoc)));
	return (CWin7MemoryForensicDoc*)m_pDocument;
}
#endif //_DEBUG


// CWin7MemoryForensicView ��Ϣ�������
