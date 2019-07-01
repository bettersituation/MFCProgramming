
// SDI_WatchView.cpp : implementation of the CSDIWatchView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDI_Watch.h"
#endif

#include "SDI_WatchDoc.h"
#include "SDI_WatchView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIWatchView

IMPLEMENT_DYNCREATE(CSDIWatchView, CView)

BEGIN_MESSAGE_MAP(CSDIWatchView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSDIWatchView construction/destruction

CSDIWatchView::CSDIWatchView() noexcept
	: m_bTimerRun(false)
	, m_bTimerType(true)
{
	// TODO: add construction code here
}

CSDIWatchView::~CSDIWatchView()
{
}

BOOL CSDIWatchView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDIWatchView drawing

void CSDIWatchView::OnDraw(CDC* pDC)
{
	CSDIWatchDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CSDIWatchView printing

BOOL CSDIWatchView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIWatchView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIWatchView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSDIWatchView diagnostics

#ifdef _DEBUG
void CSDIWatchView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIWatchView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIWatchDoc* CSDIWatchView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIWatchDoc)));
	return (CSDIWatchDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIWatchView message handlers


int CSDIWatchView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(0, 1000, NULL);
	m_bTimerRun = TRUE;
	return 0;
}


void CSDIWatchView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	int hour;
	CString str;
	CTime timer;
	timer = CTime::GetCurrentTime();

	if (m_bTimerType) {
		m_strTimer.Format(_T("현재는 %d년 %d월 %d일 %d시 %d분 %d초"),
			timer.GetYear(), timer.GetMonth(), timer.GetDay(),
			timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	}
	else {
		hour = timer.GetHour();
		if (hour >= 12) {
			str = _T("PM");
			if (hour >= 13) {
				hour -= 12;
			}
		}
		else {
			str = _T("AM");
		}
		m_strTimer.Format(_T("지금은 %s %d시 %d분 %d초"),
			str, hour, timer.GetMinute(), timer.GetSecond());
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CSDIWatchView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bTimerType) {
		if (AfxMessageBox(_T("시, 분, 초 형태로 표시하시겠습니까?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_bTimerType = FALSE;
		}
	}
	else {
		if (AfxMessageBox(_T("년월일 시분초 형태로 표시하겠습니까?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_bTimerType = TRUE;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CSDIWatchView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bTimerRun) {
		if (AfxMessageBox(_T("시계를 멈추겠습니까?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES) {
			KillTimer(0);
			m_bTimerRun = FALSE;
		}
	}
	else {
		if (AfxMessageBox(_T("시계를 동작시키겠습니까?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES) {
			SetTimer(0, 1000, NULL);
			m_bTimerRun = TRUE;
		}
	}
	CView::OnRButtonDown(nFlags, point);
}


void CSDIWatchView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	if (m_bTimerRun) {
		KillTimer(0);
	}
}
