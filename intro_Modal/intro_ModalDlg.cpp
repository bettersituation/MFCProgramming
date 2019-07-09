
// intro_ModalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "intro_Modal.h"
#include "intro_ModalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CintroModalDlg dialog



CintroModalDlg::CintroModalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INTRO_MODAL_DIALOG, pParent)
	, m_strYear(_T(""))
	, m_strMonth(_T(""))
	, m_strDay(_T(""))
	, m_strAMPM(_T(""))
	, m_strHour(_T(""))
	, m_strMinute(_T(""))
	, m_strSecond(_T(""))
	, m_bCheckYear(false)
	, m_bCheckHour(false)
	, m_bRadioClockType(false)
	, m_bViewHelp(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CintroModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Check(pDX, IDC_CHECK_YEAR, m_strYear);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_strYear);
	DDX_Text(pDX, IDC_EDIT_SECOND, m_strSecond);
	DDX_Text(pDX, IDC_EDIT_MONTH, m_strMonth);
	DDX_Text(pDX, IDC_EDIT_MINUTE, m_strMinute);
	DDX_Text(pDX, IDC_EDIT_HOUR, m_strHour);
	DDX_Text(pDX, IDC_EDIT_DAY, m_strDay);
	DDX_Text(pDX, IDC_EDIT_AMPM, m_strAMPM);
}

BEGIN_MESSAGE_MAP(CintroModalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_12, &CintroModalDlg::OnRadio12)
	ON_COMMAND(IDC_RADIO_24, &CintroModalDlg::OnRadio24)
	ON_BN_CLICKED(IDC_CHECK_YEAR, &CintroModalDlg::OnClickedCheckYear)
	ON_BN_CLICKED(IDC_CHECK_HOUR, &CintroModalDlg::OnClickedCheckHour)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_HELP, &CintroModalDlg::OnClickedButtonHelp)
END_MESSAGE_MAP()


// CintroModalDlg message handlers

BOOL CintroModalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	((CButton*)GetDlgItem(IDC_RADIO_12))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_CHECK_HOUR))->SetCheck(TRUE);

	GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_MONTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DAY)->ShowWindow(SW_HIDE);

	m_bRadioClockType = true;
	m_bCheckHour = true;
	m_bCheckYear = false;
	
	SetTimer(0, 1000, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CintroModalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CintroModalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CintroModalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CintroModalDlg::OnRadio12()
{
	// TODO: Add your command handler code here
	m_bRadioClockType = true;
}


void CintroModalDlg::OnRadio24()
{
	// TODO: Add your command handler code here
	m_bRadioClockType = false;
}


void CintroModalDlg::OnClickedCheckYear()
{
	// TODO: Add your control notification handler code here
	if (m_bCheckYear == false) {
		GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MONTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DAY)->ShowWindow(SW_SHOW);
		m_bCheckYear = true;
	}
	else {
		GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_MONTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DAY)->ShowWindow(SW_HIDE);
		m_bCheckYear = false;
	}
}


void CintroModalDlg::OnClickedCheckHour()
{
	// TODO: Add your control notification handler code here
	if (m_bCheckHour == false) {
		GetDlgItem(IDC_EDIT_AMPM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_HOUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MINUTE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_SECOND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_HOUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MINUTE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SECOND)->ShowWindow(SW_SHOW);
		m_bCheckHour = true;
	}
	else {
		GetDlgItem(IDC_EDIT_AMPM)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_HOUR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_MINUTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SECOND)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HOUR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_MINUTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SECOND)->ShowWindow(SW_HIDE);
		m_bCheckHour = false;
	}
}


void CintroModalDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	int hour;
	CTime timer;
	timer = CTime::GetCurrentTime();

	m_strYear.Format(_T("%d"), timer.GetYear());
	m_strMonth.Format(_T("%d"), timer.GetMonth());
	m_strDay.Format(_T("%d"), timer.GetDay());

	hour = timer.GetHour();
	if (m_bRadioClockType) {
		if (hour >= 12) {
			m_strAMPM = _T("PM");
			if (hour >= 13) {
				hour -= 12;
			}
		}
		else {
			m_strAMPM = _T("AM");
		}
	}
	else {
		m_strAMPM.Empty();
	}
	m_strHour.Format(_T("%d"), hour);
	m_strMinute.Format(_T("%d"), timer.GetMinute());
	m_strSecond.Format(_T("%d"), timer.GetSecond());
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void CintroModalDlg::OnClickedButtonHelp()
{
	// TODO: Add your control notification handler code here
	if (m_bViewHelp == false) {
		
		m_dlgClockHelp.Create(IDD_DIALOG_HELP, this);

		CRect rectMain, rectHelp;
		GetWindowRect(&rectMain);

		m_dlgClockHelp.GetWindowRect(&rectHelp);
		m_dlgClockHelp.MoveWindow(rectMain.right, rectMain.top,
			rectHelp.Width(), rectHelp.Height());

		m_dlgClockHelp.ShowWindow(SW_SHOW);
		m_bViewHelp = true;
	}
	else {
		m_dlgClockHelp.ShowWindow(SW_HIDE);
		m_dlgClockHelp.DestroyWindow();
		m_bViewHelp = false;
	}
}
