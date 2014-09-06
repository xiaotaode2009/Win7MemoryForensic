
// Win7MemoryForensicView.cpp : CWin7MemoryForensicView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CWin7MemoryForensicView 构造/析构

CWin7MemoryForensicView::CWin7MemoryForensicView()
{
	// TODO: 在此处添加构造代码

}

CWin7MemoryForensicView::~CWin7MemoryForensicView()
{
}

BOOL CWin7MemoryForensicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWin7MemoryForensicView 绘制

void CWin7MemoryForensicView::OnDraw(CDC* /*pDC*/)
{
	CWin7MemoryForensicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// CWin7MemoryForensicView 诊断

#ifdef _DEBUG
void CWin7MemoryForensicView::AssertValid() const
{
	CView::AssertValid();
}

void CWin7MemoryForensicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWin7MemoryForensicDoc* CWin7MemoryForensicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWin7MemoryForensicDoc)));
	return (CWin7MemoryForensicDoc*)m_pDocument;
}
#endif //_DEBUG


// CWin7MemoryForensicView 消息处理程序
