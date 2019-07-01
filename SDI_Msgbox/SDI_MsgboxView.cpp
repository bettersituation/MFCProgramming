
// SDI_MsgboxView.cpp : implementation of the CSDIMsgboxView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDI_Msgbox.h"
#endif

#include "SDI_MsgboxDoc.h"
#include "SDI_MsgboxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIMsgboxView

IMPLEMENT_DYNCREATE(CSDIMsgboxView, CView)

BEGIN_MESSAGE_MAP(CSDIMsgboxView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSDIMsgboxView construction/destruction

CSDIMsgboxView::CSDIMsgboxView() noexcept
{
	// TODO: add construction code here

}

CSDIMsgboxView::~CSDIMsgboxView()
{
}

BOOL CSDIMsgboxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDIMsgboxView drawing

void CSDIMsgboxView::OnDraw(CDC* /*pDC*/)
{
	CSDIMsgboxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSDIMsgboxView printing

BOOL CSDIMsgboxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIMsgboxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIMsgboxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSDIMsgboxView diagnostics

#ifdef _DEBUG
void CSDIMsgboxView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIMsgboxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIMsgboxDoc* CSDIMsgboxView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIMsgboxDoc)));
	return (CSDIMsgboxDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIMsgboxView message handlers


int CSDIMsgboxView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	AfxMessageBox(_T("윈도우가 생성되었습니다."), MB_OKCANCEL | MB_ICONINFORMATION);
	return 0;
}


void CSDIMsgboxView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	AfxMessageBox(_T("왼쪽 마우스를 더블클릭 했습니까?"), MB_YESNO | MB_ICONQUESTION);
	CView::OnLButtonDblClk(nFlags, point);
}


void CSDIMsgboxView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	AfxMessageBox(_T("윈도우가 종료되었습니다."), MB_YESNO | MB_ICONWARNING);
}
