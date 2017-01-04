// SimuraysDoc.cpp : implementation of the CSimuraysDoc class
//

#include "stdafx.h"
#include "Simurays.h"

#include "SimuraysDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimuraysDoc

IMPLEMENT_DYNCREATE(CSimuraysDoc, CDocument)

BEGIN_MESSAGE_MAP(CSimuraysDoc, CDocument)
	//{{AFX_MSG_MAP(CSimuraysDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimuraysDoc construction/destruction

CSimuraysDoc::CSimuraysDoc()
{
	// TODO: add one-time construction code here

}

CSimuraysDoc::~CSimuraysDoc()
{
}

BOOL CSimuraysDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSimuraysDoc serialization

void CSimuraysDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSimuraysDoc diagnostics

#ifdef _DEBUG
void CSimuraysDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSimuraysDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSimuraysDoc commands
