// SimuraysView.h : interface of the CSimuraysView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIMURAYSVIEW_H__E16628B8_3BC2_4896_AFD7_40631469BF32__INCLUDED_)
#define AFX_SIMURAYSVIEW_H__E16628B8_3BC2_4896_AFD7_40631469BF32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct boundpoint
{
CPoint coordinate;
CVector normal;
struct boundpoint* pnext;
};


struct screenpoint
{
CPoint coordinate;
double intensity;
struct screenpoint* pnext;
};


class CSimuraysView : public CView
{
protected: // create from serialization only
	CSimuraysView();
	DECLARE_DYNCREATE(CSimuraysView)

// Attributes
public:
	CSimuraysDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimuraysView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void drawscreen(CDC* pDC);
	boundpoint* praypos;
	bool fromsource;
	bool m_existfile;
	bool m_drawn;
	double m_indexni;
	double m_dieoutenergy;
	double m_absorb;
	double m_deviation;
	double m_receivedenergy;
	UINT m_sourcey;
	UINT m_sourcex;
	UINT m_reflectdelay;
	UINT m_raydelay;
	long m_simnumber;
	long screenpos;
	screenpoint * hpscreenpoint;
	boundpoint * hpboundpoint;
	bool split(CRay* pray,CIndex index);
	unsigned long raynumber;
	virtual ~CSimuraysView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSimuraysView)
	afx_msg void OnSimStart();
	afx_msg void OnSimDraw();
	afx_msg void OnFileNew();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void OnSimSetupparam();
	afx_msg void OnSimAnalasis();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SimuraysView.cpp
inline CSimuraysDoc* CSimuraysView::GetDocument()
   { return (CSimuraysDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMURAYSVIEW_H__E16628B8_3BC2_4896_AFD7_40631469BF32__INCLUDED_)
