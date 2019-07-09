
// intro_Modal.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CintroModalApp:
// See intro_Modal.cpp for the implementation of this class
//

class CintroModalApp : public CWinApp
{
public:
	CintroModalApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CintroModalApp theApp;
