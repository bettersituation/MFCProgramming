
// Intro_DialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Intro_Dialog.h"
#include "Intro_DialogDlg.h"
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


// CIntroDialogDlg dialog



CIntroDialogDlg::CIntroDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INTRO_DIALOG_DIALOG, pParent)
	, m_strEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bChecked[0] = m_bChecked[1] = FALSE;
}

void CIntroDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRING, m_strEdit);
	DDX_Control(pDX, IDC_LIST_OUTPUT, m_listBox);
	DDX_Control(pDX, IDC_COMBO_AUTO, m_cbListItem);
}

BEGIN_MESSAGE_MAP(CIntroDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK2, &CIntroDialogDlg::OnBnClickedCheck2)
	ON_LBN_SELCHANGE(IDC_LIST_OUTPUT, &CIntroDialogDlg::OnLbnSelchangeListOutput)
	ON_CBN_SELCHANGE(IDC_COMBO_AUTO, &CIntroDialogDlg::OnCbnSelchangeComboAuto)
	ON_COMMAND(IDC_RADIO1, &CIntroDialogDlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &CIntroDialogDlg::OnRadio2)
	ON_BN_CLICKED(IDC_CHECK1, &CIntroDialogDlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CIntroDialogDlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CIntroDialogDlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CIntroDialogDlg::OnClickedButtonDelete)
END_MESSAGE_MAP()


// CIntroDialogDlg message handlers

BOOL CIntroDialogDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIntroDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIntroDialogDlg::OnPaint()
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
HCURSOR CIntroDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIntroDialogDlg::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
	if (m_bChecked[1] == FALSE) {
		m_bChecked[1] = TRUE;
		m_listBox.AddString(_T("2번 체크 박스 상태 TRUE"));
	}
	else {
		m_bChecked[1] = FALSE;
		m_listBox.AddString(_T("2번 체크 박스 상태 FALSE"));
	}
	UpdateComboBox();
}


void CIntroDialogDlg::OnLbnSelchangeListOutput()
{
	// TODO: Add your control notification handler code here
}


void CIntroDialogDlg::OnCbnSelchangeComboAuto()
{
	// TODO: Add your control notification handler code here
}


void CIntroDialogDlg::UpdateComboBox()
{
	// TODO: Add your implementation code here.
	int nCnt = m_listBox.GetCount();
	m_cbListItem.ResetContent();

	for (int i = 0; i < nCnt; ++i) {
		CString strItem;
		strItem.Format(_T("리스트 항목: %d"), i + 1);
		m_cbListItem.AddString(strItem);
	}
}


void CIntroDialogDlg::OnRadio1()
{
	// TODO: Add your command handler code here
	m_listBox.AddString(_T("1번 라디오 버튼 선택"));
	UpdateComboBox();
}


void CIntroDialogDlg::OnRadio2()
{
	// TODO: Add your command handler code here
	m_listBox.AddString(_T("2번 라디오 버튼 선택"));
	UpdateComboBox();
}


void CIntroDialogDlg::OnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	if (m_bChecked[0] == FALSE) {
		m_bChecked[0] = TRUE;
		m_listBox.AddString(_T("1번 체크 박스 상태 TRUE"));
	}
	else {
		m_bChecked[0] = FALSE;
		m_listBox.AddString(_T("1번 체크 박스 상태 FALSE"));
	}
	UpdateComboBox();
}


void CIntroDialogDlg::OnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strEdit.IsEmpty() == FALSE) {
		m_listBox.AddString(m_strEdit);
		m_strEdit.Empty();
	}
	else {
		AfxMessageBox(_T("에디트 상자에 문자열을 넣습니다."));
	}
	UpdateData(FALSE);
	UpdateComboBox();
}


void CIntroDialogDlg::OnClickedButtonInsert()
{
	// TODO: Add your control notification handler code here
	CString strSelText;
	int index = m_cbListItem.GetCurSel();
	if (index != CB_ERR) {
		m_listBox.GetText(index, strSelText);
		m_listBox.AddString(strSelText);
		UpdateComboBox();
	}
	else {
		AfxMessageBox(_T("콤보 박스에서 삽입할 아이템을 선택하세요"));
	}
}


void CIntroDialogDlg::OnClickedButtonDelete()
{
	// TODO: Add your control notification handler code here
	int index = m_cbListItem.GetCurSel();
	if (index != CB_ERR) {
		m_listBox.DeleteString(index);
		UpdateComboBox();
	}
	else {
		AfxMessageBox(_T("콤보 박스에서 삭제할 아이템을 선택하세요"));
	}
}
