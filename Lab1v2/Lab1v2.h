
// Lab1v2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLab1v2App:
// See Lab1v2.cpp for the implementation of this class
//

class CLab1v2App : public CWinApp
{
public:
	CLab1v2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLab1v2App theApp;
