#if !defined(AFX_ANALASISDLG_H__86ABDC5E_E905_4594_B9E2_931EC6792FA9__INCLUDED_)
#define AFX_ANALASISDLG_H__86ABDC5E_E905_4594_B9E2_931EC6792FA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnalasisDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnalasisDlg dialog

class CAnalasisDlg : public CDialog
{
// Construction
public:
	CAnalasisDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAnalasisDlg)
	enum { IDD = IDD_DIALOGAnalasis };
	CString	m_report;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalasisDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAnalasisDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALASISDLG_H__86ABDC5E_E905_4594_B9E2_931EC6792FA9__INCLUDED_)
