
// SDI_Watch.h : main header file for the SDI_Watch application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSDIWatchApp:
// See SDI_Watch.cpp for the implementation of this class
//

class CSDIWatchApp : public CWinApp
{
public:
	CSDIWatchApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIWatchApp theApp;
