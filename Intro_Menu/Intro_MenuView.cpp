
// Intro_MenuView.cpp : implementation of the CIntroMenuView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Intro_Menu.h"
#endif

#include "Intro_MenuDoc.h"
#include "Intro_MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIntroMenuView

IMPLEMENT_DYNCREATE(CIntroMenuView, CView)

BEGIN_MESSAGE_MAP(CIntroMenuView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_LINE, &CIntroMenuView::OnLine)
	ON_COMMAND(ID_ELIPSE, &CIntroMenuView::OnElipse)
	ON_COMMAND(ID_FACE_COLOR, &CIntroMenuView::OnFaceColor)
	ON_COMMAND(ID_CROSS, &CIntroMenuView::OnCross)
	ON_COMMAND(ID_LINE_COLOR, &CIntroMenuView::OnLineColor)
	ON_COMMAND(ID_POLYGON, &CIntroMenuView::OnPolygon)
	ON_COMMAND(ID_VERTICAL, &CIntroMenuView::OnVertical)
	ON_COMMAND(ID_BDIAGONAL, &CIntroMenuView::OnBdiagonal)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CIntroMenuView::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_ELIPSE, &CIntroMenuView::OnUpdateElipse)
	ON_UPDATE_COMMAND_UI(ID_POLYGON, &CIntroMenuView::OnUpdatePolygon)
	ON_WM_RBUTTONDOWN()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// CIntroMenuView construction/destruction

CIntroMenuView::CIntroMenuView() noexcept
{
	// TODO: add construction code here

}

CIntroMenuView::~CIntroMenuView()
{
}

BOOL CIntroMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CIntroMenuView drawing

void CIntroMenuView::OnDraw(CDC* /*pDC*/)
{
	CIntroMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CIntroMenuView printing

BOOL CIntroMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIntroMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIntroMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CIntroMenuView diagnostics

#ifdef _DEBUG
void CIntroMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CIntroMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIntroMenuDoc* CIntroMenuView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIntroMenuDoc)));
	return (CIntroMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CIntroMenuView message handlers


void CIntroMenuView::OnLine()
{
	// TODO: Add your command handler code here
	// AfxMessageBox(_T("직선을 그립니다."));
	m_nDrawMode = LINE_MODE;
}


void CIntroMenuView::OnElipse()
{
	// TODO: Add your command handler code here
	// AfxMessageBox(_T("원을 그립니다."));
	m_nDrawMode = ELIPSE_MODE;
}


void CIntroMenuView::OnPolygon()
{
	// TODO: Add your command handler code here
	// AfxMessageBox(_T("다각형을 그립니다."));
	m_nDrawMode = POLYGON_MODE;
}


void CIntroMenuView::OnFaceColor()
{
	// TODO: Add your command handler code here
	AfxMessageBox(_T("면의 색상을 변경합니다."));
}


void CIntroMenuView::OnLineColor()
{
	// TODO: Add your command handler code here
	AfxMessageBox(_T("선의 색상을 변경합니다."));
}


void CIntroMenuView::OnCross()
{
	// TODO: Add your command handler code here
	// AfxMessageBox(_T("십자가 패턴으로 변경합니다."));
	m_nHatchStyle = HS_CROSS;
}


void CIntroMenuView::OnVertical()
{
	// TODO: Add your command handler code here
	// AfxMessageBox(_T("수직 패턴으로 변경합니다."));
	m_nHatchStyle = HS_VERTICAL;
}


void CIntroMenuView::OnBdiagonal()
{
	// TODO: Add your command handler code here
	// AfxMessageBox(_T("대각선 패턴으로 변경합니다."));
	m_nHatchStyle = HS_BDIAGONAL;
}


void CIntroMenuView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nDrawMode == LINE_MODE ? 1 : 0);
}


void CIntroMenuView::OnUpdateElipse(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nDrawMode == ELIPSE_MODE ? 1 : 0);
}


void CIntroMenuView::OnUpdatePolygon(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nDrawMode == POLYGON_MODE ? 1 : 0);
}


void CIntroMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnRButtonDown(nFlags, point);
	OnContextMenu(this, point);
}


void CIntroMenuView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	ClientToScreen(&point);
	OnContextMenu(this, point);
}


void CIntroMenuView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: Add your message handler code here
#ifndef SHARED_HANDLERS
	// theApp.GetContextMenuBar ShowPopupMenu(IDR_MENU1, point.x, point.y, this, TRUE);
#endif
}
