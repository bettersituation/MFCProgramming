
// SDI_Msgbox.h : main header file for the SDI_Msgbox application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSDIMsgboxApp:
// See SDI_Msgbox.cpp for the implementation of this class
//

class CSDIMsgboxApp : public CWinApp
{
public:
	CSDIMsgboxApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIMsgboxApp theApp;
