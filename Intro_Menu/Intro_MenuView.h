
// Intro_MenuView.h : interface of the CIntroMenuView class
//
enum DRAW_MODE { LINE_MODE, ELIPSE_MODE, POLYGON_MODE };
#pragma once


class CIntroMenuView : public CView
{
protected: // create from serialization only
	CIntroMenuView() noexcept;
	DECLARE_DYNCREATE(CIntroMenuView)

// Attributes
public:
	CIntroMenuDoc* GetDocument() const;

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
	virtual ~CIntroMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLine();
	afx_msg void OnElipse();
	afx_msg void OnFaceColor();
	afx_msg void OnCross();
	afx_msg void OnLineColor();
	afx_msg void OnPolygon();
	afx_msg void OnVertical();
	afx_msg void OnBdiagonal();
	int m_nDrawMode;
	int m_nHatchStyle;
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePolygon(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT /* nFlags */, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

#ifndef _DEBUG  // debug version in Intro_MenuView.cpp
inline CIntroMenuDoc* CIntroMenuView::GetDocument() const
   { return reinterpret_cast<CIntroMenuDoc*>(m_pDocument); }
#endif

