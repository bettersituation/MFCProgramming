
// SDI_MsgboxView.h : interface of the CSDIMsgboxView class
//

#pragma once


class CSDIMsgboxView : public CView
{
protected: // create from serialization only
	CSDIMsgboxView() noexcept;
	DECLARE_DYNCREATE(CSDIMsgboxView)

// Attributes
public:
	CSDIMsgboxDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSDIMsgboxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // debug version in SDI_MsgboxView.cpp
inline CSDIMsgboxDoc* CSDIMsgboxView::GetDocument() const
   { return reinterpret_cast<CSDIMsgboxDoc*>(m_pDocument); }
#endif

