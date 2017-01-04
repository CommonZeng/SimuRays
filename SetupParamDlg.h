#if !defined(AFX_SETUPPARAMDLG_H__C26A35AC_8452_44E3_8C22_DC3481A734E1__INCLUDED_)
#define AFX_SETUPPARAMDLG_H__C26A35AC_8452_44E3_8C22_DC3481A734E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetupParamDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetupParamDlg dialog

class CSetupParamDlg : public CDialog
{
// Construction
public:
	CSetupParamDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetupParamDlg)
	enum { IDD = IDD_DIALOGSetupParam };
	UINT	m_reflectdelay;
	long	m_simnumber;
	UINT	m_raydelay;
	UINT	m_sourcex;
	UINT	m_sourcey;
	double	m_absorb;
	double	m_dieoutenergy;
	double	m_indexni;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetupParamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetupParamDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETUPPARAMDLG_H__C26A35AC_8452_44E3_8C22_DC3481A734E1__INCLUDED_)
