// SimuraysView.cpp : implementation of the CSimuraysView class
//

#include "stdafx.h"
#include "Simurays.h"
#include "SetupParamDlg.h"
#include "AnalasisDlg.h"
#include "SimuraysDoc.h"
#include "SimuraysView.h"

#define PI 3.1415927

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimuraysView

IMPLEMENT_DYNCREATE(CSimuraysView, CView)

BEGIN_MESSAGE_MAP(CSimuraysView, CView)
//{{AFX_MSG_MAP(CSimuraysView)
ON_COMMAND(ID_SIM_START, OnSimStart)
ON_COMMAND(ID_SIM_DRAW, OnSimDraw)
ON_COMMAND(ID_FILE_NEW, OnFileNew)
ON_COMMAND(ID_FILE_SAVE, OnFileSave)
ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
ON_COMMAND(ID_SIM_SETUPPARAM, OnSimSetupparam)
ON_COMMAND(ID_SIM_ANALASIS, OnSimAnalasis)
//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimuraysView construction/destruction

CSimuraysView::CSimuraysView()
{
	// TODO: add construction code here
	screenpos=205;
	m_simnumber=10000;
	m_raydelay=0;
	m_reflectdelay=0;
	m_sourcex=110;
	m_sourcey=350;
	m_absorb=0.0000001;
	m_dieoutenergy=0.001;
	m_indexni=1.5;
	m_receivedenergy=0;
	m_deviation=0;
	m_drawn=false;
	m_existfile=false;
}

CSimuraysView::~CSimuraysView()
{
}

BOOL CSimuraysView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSimuraysView drawing

void CSimuraysView::OnDraw(CDC* pDC)
{
	CSimuraysDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if(false==m_existfile){
		CBrush BrushGray(RGB(150,150,150));
		pDC->FillRect(CRect(0,0,2000,2000),&BrushGray);
	}
	else{
		CBrush BrushWhite(RGB(255,255,255));
		pDC->FillRect(CRect(0,0,2000,2000),&BrushWhite);
		drawscreen(pDC);
		
	}
	if(true==m_drawn){	
		
		
		
		boundpoint* pboundpoint;
		pboundpoint=hpboundpoint;
		CClientDC dc(this);
		dc.MoveTo(pboundpoint->coordinate);
		while(NULL!=pboundpoint->pnext){
			
			
			dc.LineTo(pboundpoint->coordinate);
			if(NULL!=pboundpoint->pnext){
				pboundpoint=pboundpoint->pnext;
			}
			else
			{
				break;
			}
			
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSimuraysView printing

BOOL CSimuraysView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSimuraysView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSimuraysView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSimuraysView diagnostics

#ifdef _DEBUG
void CSimuraysView::AssertValid() const
{
	CView::AssertValid();
}

void CSimuraysView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimuraysDoc* CSimuraysView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimuraysDoc)));
	return (CSimuraysDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSimuraysView message handlers

void CSimuraysView::OnSimStart() 
{
	CClientDC dc(this);
	CBrush BrushWhite(RGB(255,255,255));
	dc.FillRect(CRect(0,0,2000,2000),&BrushWhite);
	
	
	CPen PenBlack;
	PenBlack.CreatePen(PS_SOLID,1,RGB(0,0,0));
	dc.SelectObject(&PenBlack);
	CPoint startpoint;
	
	
	CPoint endpoint;
	startpoint.x=100;
	startpoint.y=screenpos;
	endpoint.x=1099;
	endpoint.y=screenpos;
	dc.Rectangle(startpoint.x-5,startpoint.y-5,startpoint.x+5,startpoint.y+5);
	dc.Rectangle(endpoint.x-5,endpoint.y-5,endpoint.x+5,endpoint.y+5);
	dc.MoveTo(startpoint);
	dc.LineTo(endpoint);
	
	
	CPen PenRed;
	PenRed.CreatePen(PS_SOLID,1,RGB(255,0,0));
	dc.SelectObject(&PenRed);
	dc.MoveTo(m_sourcex,m_sourcey);
	dc.Ellipse(m_sourcex-5,m_sourcey-5,m_sourcex+5,m_sourcey+5);
	
	dc.SelectObject(&PenBlack);
	
	
	boundpoint* pboundpoint;
	pboundpoint=hpboundpoint;
	dc.MoveTo(pboundpoint->coordinate);
	while(NULL!=pboundpoint->pnext){
		
		
		dc.LineTo(pboundpoint->coordinate);
		if(NULL!=pboundpoint->pnext){
			pboundpoint=pboundpoint->pnext;
		}
		else
		{
			break;
		}
		
	}
	CPoint originpoint;
	originpoint.x=100;
	originpoint.y=300;
	
	dc.LineTo(originpoint);
	screenpoint* pscreenpoint;	
	pscreenpoint=hpscreenpoint;
	while(NULL!=pscreenpoint)
	{
		pscreenpoint->intensity=0;
		pscreenpoint=pscreenpoint->pnext;
	}
	unsigned long i;
	unsigned long simnumber;
	simnumber=m_simnumber;
	m_receivedenergy=0;
	m_deviation=0;
	for(i=1;i<=simnumber;i++){
		CRay ray;
		ray.absorb=m_absorb;
		ray.curpoint.x=m_sourcex;
		ray.curpoint.y=m_sourcey;
		double angle;
		angle=(PI)/2-PI/simnumber*i;
		ray.direction.x=cos(angle);
		ray.direction.y=sin(angle);
		ray.number=raynumber;
		raynumber++;
		CVector normal;
		normal.x=1;
		normal.y=1;
		normal.unit();
		CIndex index;
		index.ni=m_indexni;
		index.nr=1;	
		fromsource=true;
		split(&ray,index);
		Sleep(m_raydelay);
		//MessageBox("one ray done");
	}
	//Calculate and draw the received intensity of the screen
	
	
	pscreenpoint=hpscreenpoint;
	double maxintensity;
	maxintensity=0;
	
	while(NULL!=pscreenpoint)
	{
		
		
		
		if(maxintensity<pscreenpoint->intensity)
		{
			maxintensity=pscreenpoint->intensity;
		}
		pscreenpoint=pscreenpoint->pnext;
	}
	pscreenpoint=hpscreenpoint;
	while(NULL!=pscreenpoint)
	{
		
		
		dc.MoveTo(pscreenpoint->coordinate);
		dc.LineTo(pscreenpoint->coordinate.x,pscreenpoint->coordinate.y-(pscreenpoint->intensity)*200/maxintensity);
		m_receivedenergy+=pscreenpoint->intensity;
		pscreenpoint=pscreenpoint->pnext;
	}
	//Calculate deviation
	pscreenpoint=hpscreenpoint;
	while(NULL!=pscreenpoint)
	{
		m_deviation+=(m_receivedenergy/1000-pscreenpoint->intensity)*(m_receivedenergy/1000-pscreenpoint->intensity);
		pscreenpoint=pscreenpoint->pnext;
	}
	m_deviation/=1000;
	
	CMenu   *mmenu=GetParent()->GetMenu();  
	mmenu->GetSubMenu(3)->EnableMenuItem(3,MF_BYPOSITION   |MF_ENABLED);
	GetParent()->DrawMenuBar();   
	
}

bool CSimuraysView::split(CRay *pray,  CIndex index)
{
	double distance;
	double shortest;
	double k21,k22;
	double alfa1,alfa2,k1,k2;
	boundpoint* pboundpoint;
	screenpoint* pscreenpoint;
	bool aliverefl;
	bool aliverefr;
	bool onbound;
	bool onscreen;
	aliverefl=true;
	aliverefr=true;
	CClientDC dc(this);
	
	//	boundpoint* praypos;
	
	onbound=true;
	onscreen=false;
	while(aliverefl)
	{
		
		pboundpoint=hpboundpoint;
		pscreenpoint=hpscreenpoint;
		shortest=1000000;
		CRay* newpray=new CRay;
		raynumber++;
		newpray->number=raynumber;
		newpray->curpoint=pray->curpoint;
		newpray->energy=pray->energy;
		newpray->direction.x=pray->direction.x;
		newpray->direction.y=pray->direction.y;
		CPen PenRed;
		PenRed.CreatePen(PS_SOLID,1,RGB(255,0,0));
		CPen PenGreen;
		PenGreen.CreatePen(PS_SOLID,1,RGB(0,255,0));
		CPen PenBlue;
		PenBlue.CreatePen(PS_SOLID,1,RGB(0,0,255));
		if(0==raynumber%3)
		{	
			dc.SelectObject(&PenRed);
		}
		else{
			if(1==raynumber%3)
			{
				
				
				dc.SelectObject(&PenGreen);
			}else{
				
				if(2==raynumber%3)
				{
					
					dc.SelectObject(&PenBlue);
				}
			}
			
			
		}
		
		dc.MoveTo(pray->curpoint);
		while(NULL!=pboundpoint)
		{
			
			if(0==pray->direction.x){alfa1=PI/2;}else{
				k1=pray->direction.y/pray->direction.x;
				alfa1=atan(k1);}
			
			
			if(pboundpoint->coordinate.y!=pray->curpoint.y||pboundpoint->coordinate.x!=pray->curpoint.x)
			{
				
				k21=(pboundpoint->coordinate.y-pray->curpoint.y);
				k22=(pboundpoint->coordinate.x-pray->curpoint.x);
				k2=k21/k22;
				alfa2=atan(k2);
			}else
			{
				alfa2=alfa1+1;
			}
			if(pboundpoint->coordinate.y!=pray->curpoint.y&&pboundpoint->coordinate.x==pray->curpoint.x){alfa2=PI/2;}
			if(fabs((alfa1-alfa2))/PI*180<1&&pray->direction.x*k22>0&&pray->direction.y*k21>=0)
			{
				
				distance=(pray->curpoint.x-pboundpoint->coordinate.x)*(pray->curpoint.x-pboundpoint->coordinate.x)+(pray->curpoint.y-pboundpoint->coordinate.y)*(pray->curpoint.y-pboundpoint->coordinate.y);
				if(shortest>distance){
					praypos=pboundpoint;
					shortest=distance;
				}
				
			}
			
			
			if(NULL!=pboundpoint->pnext)
			{
				pboundpoint=pboundpoint->pnext;
			}
			else
			{
				
				break;
			}
			
		}
		
		
		fromsource=false;
		pscreenpoint=hpscreenpoint;
		
		if(1000000==shortest){
			onbound=false;
			while(NULL!=pscreenpoint)
			{
				
				if(0==pray->direction.x){alfa1=PI/2;}else{
					k1=pray->direction.y/pray->direction.x;
					alfa1=atan(k1);}
				
				
				k21=(pscreenpoint->coordinate.y-pray->curpoint.y);
				k22=(pscreenpoint->coordinate.x-pray->curpoint.x);
				k2=k21/k22;
				alfa2=atan(k2);
				
				if(pscreenpoint->coordinate.x==pray->curpoint.x){alfa2=PI/2;}
				if(fabs((alfa1-alfa2))/PI*180<1&&pray->direction.x*k22>0&&pray->direction.y*k21>0)
				{
					
					pray->curpoint=pscreenpoint->coordinate;
					dc.LineTo(pray->curpoint);
					pscreenpoint->intensity+=pray->energy;
					pray->energy=0;
					aliverefl=false;
					onscreen=true;
					break;
					
				}
				
				
				if(NULL!=pscreenpoint->pnext)
				{
					pscreenpoint=pscreenpoint->pnext;
				}
				else
				{
					pray->curpoint.x+=200*pray->direction.x;
					pray->curpoint.y+=200*pray->direction.y;
					dc.LineTo(pray->curpoint);
					pray->energy=0;
					aliverefl=false;
					onscreen=false;
					Sleep(m_reflectdelay);	
					return 0;
					
					
				}
			}
			aliverefl=false;
		}
		else
		{
			pray->curpoint=praypos->coordinate;
			newpray->curpoint=praypos->coordinate;
			dc.LineTo(pray->curpoint);
			if(index.ni>index.nr)
			{
				if(pray->energy-shortest*m_absorb>=m_dieoutenergy)
				{
					
					pray->energy-=shortest*m_absorb;
					newpray->energy-=shortest*m_absorb;
					
				}
				else
				{
					pray->energy=0;newpray->energy=0;
					aliverefl=false;onbound=false;	Sleep(m_reflectdelay);		return 0;
					
				}
			}
		}
		if(true==onbound)
		{
			aliverefr=newpray->refract(praypos->normal,index,m_dieoutenergy);
			if(true==aliverefr)
			{
				CIndex newindex;
				newindex.ni=index.nr;
				newindex.nr=index.ni;
				split(newpray,newindex);
			}
			//else{free(newpray);}
			
			aliverefl=pray->reflect(praypos->normal,index,m_dieoutenergy);
			//pray->energy*=0.5;
		}
		Sleep(m_reflectdelay);	
	}
	return 0;
}

void CSimuraysView::OnSimDraw() 
{
	// TODO: Add your command handler code here
	bool firsttime;
	CPoint startpoint;
	CPoint originpoint;
	originpoint.x=100;
	originpoint.y=300;
	CClientDC dc(this);
	CBrush BrushWhite(RGB(255,255,255));
	dc.FillRect(CRect(0,0,2000,2000),&BrushWhite);
	drawscreen(&dc);
	CPen PenBlack;
	PenBlack.CreatePen(PS_SOLID,1,RGB(0,0,0));
	dc.SelectObject(&PenBlack);
	dc.MoveTo(originpoint);
	dc.Rectangle(originpoint.x-5,originpoint.y-5,originpoint.x+5,originpoint.y+5);
	startpoint.x=100;
	startpoint.y=300;
	//	dc.LineTo(startpoint);
	HCURSOR   hCursor;  
	hCursor=LoadCursor(NULL,IDC_CROSS);  
	
	SetCursor(hCursor);    
	
	CPoint cursorpos;
	cursorpos=startpoint;
	ClientToScreen(&cursorpos);
	SetCursorPos(cursorpos.x,cursorpos.y);
	dc.MoveTo(startpoint);
	dc.Rectangle(startpoint.x-5,startpoint.y-5,startpoint.x+5,startpoint.y+5);
	
	boundpoint *pboundpoint;
	hpboundpoint=new boundpoint;
	hpboundpoint->coordinate=startpoint;
	pboundpoint=hpboundpoint;
	
	firsttime=true;
	
	while(originpoint.x!=cursorpos.x||originpoint.y!=cursorpos.y||true==firsttime)
	{
		GetCursorPos(&cursorpos);ScreenToClient(&cursorpos);
		if(pboundpoint->coordinate.x!=cursorpos.x||pboundpoint->coordinate.y!=cursorpos.y)
		{
			dc.LineTo(cursorpos);	
			pboundpoint->pnext=new boundpoint;
			pboundpoint->normal.x=cursorpos.y-pboundpoint->coordinate.y;
			pboundpoint->normal.y=-cursorpos.x+pboundpoint->coordinate.x;
			
			
			dc.LineTo(cursorpos.x+1*pboundpoint->normal.x,cursorpos.y+1*pboundpoint->normal.y);
			dc.MoveTo(cursorpos);
			pboundpoint=pboundpoint->pnext;
			pboundpoint->coordinate=cursorpos;
			if(abs(originpoint.x-cursorpos.x)>5&&abs(originpoint.y-cursorpos.y)>5)
			{
				firsttime=false;
			}
			if(abs(originpoint.x-cursorpos.x)<=1&&abs(originpoint.y-cursorpos.y)<=1&&false==firsttime)
			{
				break;
			}
		}
	}
	dc.LineTo(originpoint);
	
	
	
	pboundpoint->pnext=NULL;
	AfxMessageBox("Done.",MB_ICONINFORMATION);
	m_drawn=true;
	CMenu   *mmenu=GetParent()->GetMenu();  
	mmenu->GetSubMenu(3)->EnableMenuItem(2,MF_BYPOSITION   |  MF_ENABLED);
	GetParent()->DrawMenuBar();   
	
}



void CSimuraysView::OnFileNew() 
{
	CMenu   *mmenu=GetParent()->GetMenu();  
	mmenu->EnableMenuItem(3,MF_BYPOSITION   |   MF_ENABLED);   
	mmenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION   |  MF_ENABLED);
	mmenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION   |  MF_ENABLED);
	
	mmenu->GetSubMenu(3)->EnableMenuItem(2,MF_BYPOSITION   |  MF_GRAYED| MF_DISABLED);
	mmenu->GetSubMenu(3)->EnableMenuItem(3,MF_BYPOSITION   |  MF_GRAYED| MF_DISABLED);
	GetParent()->DrawMenuBar();   
	CString strtitle;
	strtitle="无标题";
	strtitle+=" - Simurays";
	AfxGetApp()->m_pMainWnd->SetWindowText(strtitle); 
	CPoint startpoint;
	CPoint originpoint;
	CPoint endpoint;
	originpoint.x=100;
	originpoint.y=300;
	
	
	
	
	CClientDC dc(this);
	CBrush BrushWhite(RGB(255,255,255));
	dc.FillRect(CRect(0,0,2000,2000),&BrushWhite);
	
	startpoint.x=100;
	startpoint.y=screenpos;
	endpoint.x=1099;
	endpoint.y=screenpos;
	
	
	
	CPoint cursorpos;
	cursorpos=startpoint;
	dc.MoveTo(startpoint);
	dc.Rectangle(startpoint.x-5,startpoint.y-5,startpoint.x+5,startpoint.y+5);
	
	screenpoint* pscreenpoint;
	hpscreenpoint=new screenpoint;
	hpscreenpoint->coordinate=startpoint;
	pscreenpoint=hpscreenpoint;
	pscreenpoint->intensity=0;
	while(cursorpos.x<=endpoint.x)
	{
		
		cursorpos.x+=1;
		dc.LineTo(cursorpos);
		pscreenpoint->pnext=new screenpoint;
		pscreenpoint=pscreenpoint->pnext;
		pscreenpoint->intensity=0;
		pscreenpoint->coordinate=cursorpos;
		
	}
	dc.LineTo(endpoint);
	dc.Rectangle(endpoint.x-5,endpoint.y-5,endpoint.x+5,endpoint.y+5);
	pscreenpoint->pnext=new screenpoint;
	pscreenpoint=pscreenpoint->pnext;
	pscreenpoint->coordinate=endpoint;
	pscreenpoint->intensity=0;
	
	pscreenpoint->pnext=NULL;
	
	
	CPen PenRed;
	PenRed.CreatePen(PS_SOLID,1,RGB(255,0,0));
	dc.SelectObject(&PenRed);
	dc.MoveTo(m_sourcex,m_sourcey);
	dc.Ellipse(m_sourcex-5,m_sourcey-5,m_sourcex+5,m_sourcey+5);
	
	
	
	
	m_simnumber=10000;
	m_raydelay=0;
	m_reflectdelay=0;
	m_sourcex=110;
	m_sourcey=350;
	m_absorb=0.0000001;
	m_dieoutenergy=0.001;
	m_indexni=1.5;
	m_receivedenergy=0;
	m_deviation=0;
	
	m_existfile=true;
	// TODO: Add your command handler code here
	
}

void CSimuraysView::OnFileSave() 
{
	// TODO: Add your command handler code here
	
	CFileDialog fileDlg(FALSE,NULL,NULL,OFN_OVERWRITEPROMPT);
	fileDlg.m_ofn.lpstrTitle="保存文件";
	fileDlg.m_ofn.lpstrFilter="Simurays 文件(*.smr)\0*.smr\0\0";
	fileDlg.m_ofn.lpstrDefExt="smr";
	if(IDOK == fileDlg.DoModal())
		
	{	
		CFile destFile(fileDlg.GetPathName(),CFile::modeCreate|CFile::modeWrite);
		
		boundpoint *pboundpoint;
		pboundpoint=hpboundpoint;
		
		
		
		while(NULL!=pboundpoint){
			
			
			
			
			
			destFile.Write(pboundpoint, sizeof(boundpoint));
			if(NULL!=pboundpoint->pnext){
				pboundpoint=pboundpoint->pnext;
			}else{break;}
		}
		
		destFile.Close();
		CString strtitle;
		strtitle=fileDlg.GetPathName();
		strtitle+=" - Simurays";
		AfxGetApp()->m_pMainWnd->SetWindowText(strtitle); 
		
	}
}

void CSimuraysView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle="打开文件";
	fileDlg.m_ofn.lpstrFilter="Simurays文件(*.smr)\0*.smr\0\0";
	
	
				if(IDOK == fileDlg.DoModal())
				{
					CMenu   *mmenu=GetParent()->GetMenu();  
					mmenu->EnableMenuItem(3,MF_BYPOSITION   |   MF_ENABLED);   
					mmenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION  | MF_GRAYED| MF_DISABLED);
					mmenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION   |  MF_ENABLED);
					
					mmenu->GetSubMenu(3)->EnableMenuItem(2,MF_BYPOSITION   | MF_ENABLED);
					mmenu->GetSubMenu(3)->EnableMenuItem(3,MF_BYPOSITION   |  MF_GRAYED| MF_DISABLED);
					GetParent()->DrawMenuBar();   
					
					CClientDC dc(this);
					
					boundpoint readboundpoint;
					boundpoint* pboundpoint;
					pboundpoint=new boundpoint;
					hpboundpoint=pboundpoint;
					
					CBrush BrushWhite(RGB(255,255,255));
					dc.FillRect(CRect(0,0,2000,2000),&BrushWhite);
					CFile fileOpen;
					if(!fileOpen.Open(fileDlg.GetPathName(), CFile::modeRead))
					{
						AfxMessageBox("打开文件失败", MB_OK | MB_ICONERROR);
						
					}
					CString strtitle;
					strtitle=fileDlg.GetPathName();
					strtitle+=" - Simurays";
					AfxGetApp()->m_pMainWnd->SetWindowText(strtitle); 
					
					
					while(true){
						fileOpen.Read(&readboundpoint, sizeof(boundpoint));
						
						pboundpoint->coordinate=readboundpoint.coordinate;
						pboundpoint->normal=readboundpoint.normal;
						
						if(NULL!=readboundpoint.pnext){
							pboundpoint->pnext=new boundpoint;
							pboundpoint=pboundpoint->pnext;
						}
						else
						{
							pboundpoint->pnext=NULL;break;
						}
					}
					
					fileOpen.Close();
					
					pboundpoint=hpboundpoint;
					
					dc.MoveTo(pboundpoint->coordinate);
					while(NULL!=pboundpoint->pnext)
					{
						
						
						dc.LineTo(pboundpoint->coordinate);
						if(NULL!=pboundpoint->pnext){
							pboundpoint=pboundpoint->pnext;
						}
						else
						{
							break;
						}
						
					}
					m_existfile=true;
					m_drawn=true;
					
					
					
					CPoint startpoint;
					CPoint originpoint;
					CPoint endpoint;
					originpoint.x=100;
					originpoint.y=300;
					
					
					
					
					startpoint.x=100;
					startpoint.y=screenpos;
					endpoint.x=1099;
					endpoint.y=screenpos;
					//	dc.LineTo(startpoint);
					
					
					CPoint cursorpos;
					cursorpos=startpoint;
					dc.MoveTo(startpoint);
					dc.Rectangle(startpoint.x-5,startpoint.y-5,startpoint.x+5,startpoint.y+5);
					
					screenpoint* pscreenpoint;
					hpscreenpoint=new screenpoint;
					hpscreenpoint->coordinate=startpoint;
					pscreenpoint=hpscreenpoint;
					pscreenpoint->intensity=0;
					while(cursorpos.x<=endpoint.x)
					{
						
						cursorpos.x+=1;
						dc.LineTo(cursorpos);
						pscreenpoint->pnext=new screenpoint;
						pscreenpoint=pscreenpoint->pnext;
						pscreenpoint->intensity=0;
						pscreenpoint->coordinate=cursorpos;
						
					}
					dc.LineTo(endpoint);
					dc.Rectangle(endpoint.x-5,endpoint.y-5,endpoint.x+5,endpoint.y+5);
					pscreenpoint->pnext=new screenpoint;
					pscreenpoint=pscreenpoint->pnext;
					pscreenpoint->coordinate=endpoint;
					pscreenpoint->intensity=0;
					
					pscreenpoint->pnext=NULL;
					
					
					CPen PenRed;
					PenRed.CreatePen(PS_SOLID,1,RGB(255,0,0));
					dc.SelectObject(&PenRed);
					dc.MoveTo(m_sourcex,m_sourcey);
					dc.Ellipse(m_sourcex-5,m_sourcey-5,m_sourcex+5,m_sourcey+5);
					
					
					
					m_simnumber=10000;
					m_raydelay=0;
					m_reflectdelay=0;
					m_sourcex=110;
					m_sourcey=350;
					m_absorb=0.0000001;
					m_dieoutenergy=0.001;
					m_indexni=1.5;
					m_receivedenergy=0;
					m_deviation=0;
					
					m_existfile=true;
				}
}

void CSimuraysView::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	OnFileSave();	
}

void CSimuraysView::OnSimSetupparam() 
{
	// TODO: Add your command handler code here
	//Erase the original light source
	CClientDC dc(this);
	CPen PenWhite;
	PenWhite.CreatePen(PS_SOLID,1,RGB(255,255,255));
	dc.SelectObject(&PenWhite);
	dc.MoveTo(m_sourcex,m_sourcey);
	dc.Ellipse(m_sourcex-5,m_sourcey-5,m_sourcex+5,m_sourcey+5);
	CSetupParamDlg Dlg;
	Dlg.m_simnumber=m_simnumber;
	Dlg.m_raydelay=m_raydelay;
	Dlg.m_reflectdelay=m_reflectdelay;
	Dlg.m_sourcex=m_sourcex;
	Dlg.m_sourcey=m_sourcey;
	Dlg.m_absorb=m_absorb;
	Dlg.m_dieoutenergy=m_dieoutenergy;
	Dlg.m_indexni=m_indexni;
	if(IDOK==Dlg.DoModal())
	{
		m_simnumber=Dlg.m_simnumber;
		m_raydelay=Dlg.m_raydelay;
		m_reflectdelay=Dlg.m_reflectdelay;
		m_sourcex=Dlg.m_sourcex;
		m_sourcey=Dlg.m_sourcey;
		m_absorb=Dlg.m_absorb;
		m_dieoutenergy=Dlg.m_dieoutenergy;
		m_indexni=Dlg.m_indexni;
	}
	
	CPen PenRed;
	PenRed.CreatePen(PS_SOLID,1,RGB(255,0,0));
	dc.SelectObject(&PenRed);
	dc.MoveTo(m_sourcex,m_sourcey);
	dc.Ellipse(m_sourcex-5,m_sourcey-5,m_sourcex+5,m_sourcey+5);
}

void CSimuraysView::OnSimAnalasis() 
{
	// TODO: Add your command handler code here
	CString strtemp;
	CString strreport;
	strreport="                ";
	strreport+="Simurays仿真结果\r\n光源共发射出";
	strtemp.Format("%d",m_simnumber);
	strreport+=strtemp;
	strreport+="单位能量的光线。\r\n光屏共接收到";
	strtemp.Format("%.2f",m_receivedenergy);
	strreport+=strtemp;
	strreport+="单位能量的光线。\r\n能量利用率为";
	strtemp.Format("%.2f",m_receivedenergy*100/m_simnumber);
	strreport+=strtemp;
	strreport+="%。\r\n损失率为";
	strtemp.Format("%.2f",100-m_receivedenergy*100/m_simnumber);
	strreport+=strtemp;
	
	strreport+="%。\r\n光屏共1000个像素点,\r\n每个像素点接收到的能量\r\n均值为";
	strtemp.Format("%.6f",m_receivedenergy/1000);
	strreport+=strtemp;
	strreport+="。\r\n方差为";
	strtemp.Format("%.6f",m_deviation);
	strreport+=strtemp;
	strreport+="。";
	CAnalasisDlg Dlg;
	Dlg.m_report=strreport;
	Dlg.DoModal();
}

void CSimuraysView::drawscreen(CDC* pDC)
{
	CPen PenBlack;
	PenBlack.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(&PenBlack);
	CPoint startpoint;
	
	
	CPoint endpoint;
	startpoint.x=100;
	startpoint.y=screenpos;
	endpoint.x=1099;
	endpoint.y=screenpos;
	pDC->Rectangle(startpoint.x-5,startpoint.y-5,startpoint.x+5,startpoint.y+5);
	pDC->Rectangle(endpoint.x-5,endpoint.y-5,endpoint.x+5,endpoint.y+5);
	pDC->MoveTo(startpoint);
	pDC->LineTo(endpoint);
	
	
	CPen PenRed;
	PenRed.CreatePen(PS_SOLID,1,RGB(255,0,0));
	pDC->SelectObject(&PenRed);
	pDC->MoveTo(m_sourcex,m_sourcey);
	pDC->Ellipse(m_sourcex-5,m_sourcey-5,m_sourcex+5,m_sourcey+5);
}
