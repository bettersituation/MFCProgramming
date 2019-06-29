
// intro_SDIView.cpp : implementation of the CintroSDIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "intro_SDI.h"
#endif

#include "intro_SDIDoc.h"
#include "intro_SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CintroSDIView

IMPLEMENT_DYNCREATE(CintroSDIView, CView)

BEGIN_MESSAGE_MAP(CintroSDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CintroSDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CintroSDIView construction/destruction

CintroSDIView::CintroSDIView() noexcept
{
	// TODO: add construction code here

}

CintroSDIView::~CintroSDIView()
{
}

BOOL CintroSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CintroSDIView drawing

void CintroSDIView::OnDraw(CDC* pDC)
{
	CintroSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOut(10, 10, m_strWindowSize);
	pDC->TextOut(10, 50, m_strPointText);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CintroSDIView printing


void CintroSDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CintroSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CintroSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CintroSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CintroSDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	m_bDrag = FALSE;
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CintroSDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	// theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CintroSDIView diagnostics

#ifdef _DEBUG
void CintroSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CintroSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CintroSDIDoc* CintroSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CintroSDIDoc)));
	return (CintroSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CintroSDIView message handlers


void CintroSDIView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_strWindowSize.Format(_T("윈도우 넓이는 %d, 높이는 %d입니다."), cx, cy);
	Invalidate();
}


void CintroSDIView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bDrag = TRUE;
	m_strOutput = _T("왼쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CintroSDIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bDrag = TRUE;
	m_strOutput = _T("오른쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CintroSDIView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	m_strOutput = _T("키보드를 눌렀습니다.");
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CintroSDIView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bDrag == TRUE) {
		m_strOutput = _T("마우스를 드래그 하고 있습니다.");
	}
	else {
		m_strOutput = _T("마우스를 이동 중입니다.");
	}

	m_ptMouseMove = point;
	m_strPointText.Format(_T("X: %d, Y:%d"), m_ptMouseMove.x, m_ptMouseMove.y);

	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CintroSDIView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bDrag = FALSE;

	CView::OnLButtonUp(nFlags, point);
}


void CintroSDIView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	m_strOutput = _T("키보드가 떼였습니다.");
	Invalidate();

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
