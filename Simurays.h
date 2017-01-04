// Simurays.h : main header file for the SIMURAYS application
//

#if !defined(AFX_SIMURAYS_H__0845EEA3_1F0F_4910_9B9F_A715CAD8A311__INCLUDED_)
#define AFX_SIMURAYS_H__0845EEA3_1F0F_4910_9B9F_A715CAD8A311__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "CRay.h"
/////////////////////////////////////////////////////////////////////////////
// CSimuraysApp:
// See Simurays.cpp for the implementation of this class
//

class CSimuraysApp : public CWinApp
{
public:
	CSimuraysApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimuraysApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSimuraysApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMURAYS_H__0845EEA3_1F0F_4910_9B9F_A715CAD8A311__INCLUDED_)
