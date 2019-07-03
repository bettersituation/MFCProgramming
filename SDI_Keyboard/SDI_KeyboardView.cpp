
// SDI_KeyboardView.cpp : implementation of the CSDIKeyboardView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDI_Keyboard.h"
#endif

#include "SDI_KeyboardDoc.h"
#include "SDI_KeyboardView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIKeyboardView

IMPLEMENT_DYNCREATE(CSDIKeyboardView, CView)

BEGIN_MESSAGE_MAP(CSDIKeyboardView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSDIKeyboardView construction/destruction

CSDIKeyboardView::CSDIKeyboardView() noexcept
	: m_strOutput(_T(""))
	, m_ptLocation(0)
{
	// TODO: add construction code here

}

CSDIKeyboardView::~CSDIKeyboardView()
{
}

BOOL CSDIKeyboardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDIKeyboardView drawing

void CSDIKeyboardView::OnDraw(CDC* pDC)
{
	CSDIKeyboardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOut(m_ptLocation.x, m_ptLocation.y, m_strOutput);
}


// CSDIKeyboardView printing

BOOL CSDIKeyboardView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIKeyboardView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIKeyboardView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSDIKeyboardView diagnostics

#ifdef _DEBUG
void CSDIKeyboardView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIKeyboardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIKeyboardDoc* CSDIKeyboardView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIKeyboardDoc)));
	return (CSDIKeyboardDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIKeyboardView message handlers


void CSDIKeyboardView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	int nCharIndex;
	nCharIndex = m_strOutput.GetLength();

	if (nChar == VK_BACK) {
		m_strOutput.Delete(nCharIndex - 1, 1);
	}
	else {
		m_strOutput += (WCHAR)nChar;
	}
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CSDIKeyboardView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_LEFT:
		m_ptLocation.x--;
		break;
	case VK_RIGHT:
		m_ptLocation.x++;
		break;
	case VK_UP:
		m_ptLocation.y--;
		break;
	case VK_DOWN:
		m_ptLocation.y++;
		break;
	case VK_PRIOR:
		m_ptLocation.y -= 50;
		break;
	case VK_NEXT:
		m_ptLocation.y += 50;
		break;
	case VK_HOME:
		m_ptLocation = CPoint(0, 0);
		break;
	}
	if (m_ptLocation.x < 0) {
		m_ptLocation.x = 0;
		AfxMessageBox(_T("왼쪽으로 더 이동할 수 없습니다."));
	}
	if (m_ptLocation.x > m_ptClientSize.x) {
		m_ptLocation.x = m_ptClientSize.x;
		AfxMessageBox(_T("오른쪽으로 더 이동할 수 없습니다."));
	}
	if (m_ptLocation.y < 0) {
		m_ptLocation.y = 0;
		AfxMessageBox(_T("위로 더 이동할 수 없습니다."));
	}
	if (m_ptLocation.y > m_ptClientSize.y) {
		m_ptLocation.y = m_ptClientSize.y;
		AfxMessageBox(_T("아래로 더 이동할 수 없습니다."));
	}
	
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CSDIKeyboardView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;
	Invalidate();
}


void CSDIKeyboardView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_ptLocation.x = point.x;
	m_ptLocation.y = point.y;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CSDIKeyboardView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_strOutput.IsEmpty() == false) {
		if (AfxMessageBox(_T("문자를 모두 지우겠습니까?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_strOutput.Empty();
		}
	}
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
