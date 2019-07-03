
// SDI_Keyboard.h : main header file for the SDI_Keyboard application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSDIKeyboardApp:
// See SDI_Keyboard.cpp for the implementation of this class
//

class CSDIKeyboardApp : public CWinApp
{
public:
	CSDIKeyboardApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIKeyboardApp theApp;
