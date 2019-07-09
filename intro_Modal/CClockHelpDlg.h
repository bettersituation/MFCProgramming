#pragma once


// CClockHelpDlg dialog

class CClockHelpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClockHelpDlg)

public:
	CClockHelpDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CClockHelpDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HELP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
