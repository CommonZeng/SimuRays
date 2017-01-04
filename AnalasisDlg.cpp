// AnalasisDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Simurays.h"
#include "AnalasisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnalasisDlg dialog


CAnalasisDlg::CAnalasisDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnalasisDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnalasisDlg)
	m_report = _T("");
	//}}AFX_DATA_INIT
}


void CAnalasisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnalasisDlg)
	DDX_Text(pDX, IDC_EDIT1, m_report);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAnalasisDlg, CDialog)
	//{{AFX_MSG_MAP(CAnalasisDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalasisDlg message handlers
