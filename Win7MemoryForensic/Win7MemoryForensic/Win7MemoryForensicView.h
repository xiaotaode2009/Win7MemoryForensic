
// Win7MemoryForensicView.h : CWin7MemoryForensicView ��Ľӿ�
//

#pragma once


class CWin7MemoryForensicView : public CView
{
protected: // �������л�����
	CWin7MemoryForensicView();
	DECLARE_DYNCREATE(CWin7MemoryForensicView)

// ����
public:
	CWin7MemoryForensicDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CWin7MemoryForensicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Win7MemoryForensicView.cpp �еĵ��԰汾
inline CWin7MemoryForensicDoc* CWin7MemoryForensicView::GetDocument() const
   { return reinterpret_cast<CWin7MemoryForensicDoc*>(m_pDocument); }
#endif

