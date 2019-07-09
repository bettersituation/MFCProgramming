
// Intro_Menu.h : main header file for the Intro_Menu application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CIntroMenuApp:
// See Intro_Menu.cpp for the implementation of this class
//

class CIntroMenuApp : public CWinApp
{
public:
	CIntroMenuApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CIntroMenuApp theApp;
