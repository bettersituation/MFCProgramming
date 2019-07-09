
// intro_ModalDlg.h : header file
//

#pragma once
#include "CClockHelpDlg.h"

// CintroModalDlg dialog
class CintroModalDlg : public CDialogEx
{
// Construction
public:
	CintroModalDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTRO_MODAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CString m_strYear;
	CString m_strYear;
	CString m_strSecond;
	CString m_strMonth;
	CString m_strMinute;
	CString m_strHour;
	CString m_strDay;
	CString m_strAMPM;
	bool m_bRadioClockType;
	afx_msg void OnRadio12();
	afx_msg void OnRadio24();
	bool m_bCheckYear;
	bool m_bCheckHour;
	afx_msg void OnClickedCheckYear();
	afx_msg void OnClickedCheckHour();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedButtonHelp();
	bool m_bViewHelp;
	CClockHelpDlg m_dlgClockHelp;
};
