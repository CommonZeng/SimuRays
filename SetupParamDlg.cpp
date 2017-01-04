// SetupParamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Simurays.h"
#include "SetupParamDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetupParamDlg dialog


CSetupParamDlg::CSetupParamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupParamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetupParamDlg)
	m_reflectdelay = 0;
	m_simnumber = 10000;
	m_raydelay = 0;
	m_sourcex = 0;
	m_sourcey = 0;
	m_absorb = 0.0;
	m_dieoutenergy = 0.0;
	m_indexni = 0.0;
	//}}AFX_DATA_INIT
}


void CSetupParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetupParamDlg)
	DDX_Text(pDX, IDC_EDIT_reflectdelay, m_reflectdelay);
	DDX_Text(pDX, IDC_EDIT_simnumber, m_simnumber);
	DDV_MinMaxLong(pDX, m_simnumber, 3, 2147483647);
	DDX_Text(pDX, IDC_EDIT_raydelay, m_raydelay);
	DDX_Text(pDX, IDC_EDIT_sourcex, m_sourcex);
	DDX_Text(pDX, IDC_EDIT_sourcey, m_sourcey);
	DDX_Text(pDX, IDC_EDIT_absorb, m_absorb);
	DDX_Text(pDX, IDC_EDIT_dieoutenergy, m_dieoutenergy);
	DDV_MinMaxDouble(pDX, m_dieoutenergy, 0., 0.5);
	DDX_Text(pDX, IDC_EDIT_indexni, m_indexni);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetupParamDlg, CDialog)
	//{{AFX_MSG_MAP(CSetupParamDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetupParamDlg message handlers

