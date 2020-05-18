// Cache2003.h : main header file for the CACHE2003 application
//

#if !defined(AFX_CACHE2003_H__8D60A6C3_5F9B_4B72_A08F_9C831D79BE0C__INCLUDED_)
#define AFX_CACHE2003_H__8D60A6C3_5F9B_4B72_A08F_9C831D79BE0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCache2003App:
// See Cache2003.cpp for the implementation of this class
//

class CCache2003App : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CCache2003App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCache2003App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCache2003App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CACHE2003_H__8D60A6C3_5F9B_4B72_A08F_9C831D79BE0C__INCLUDED_)
