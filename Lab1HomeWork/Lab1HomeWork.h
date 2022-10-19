
// Lab1HomeWork.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLab1HomeWorkApp:
// See Lab1HomeWork.cpp for the implementation of this class
//

class CLab1HomeWorkApp : public CWinApp
{
public:
	CLab1HomeWorkApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLab1HomeWorkApp theApp;
