; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSetupParamDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Simurays.h"
LastPage=0

ClassCount=7
Class1=CSimuraysApp
Class2=CSimuraysDoc
Class3=CSimuraysView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CSetupParamDlg
Resource3=IDD_DIALOGSetupParam
Class7=CAnalasisDlg
Resource4=IDD_DIALOGAnalasis

[CLS:CSimuraysApp]
Type=0
HeaderFile=Simurays.h
ImplementationFile=Simurays.cpp
Filter=N

[CLS:CSimuraysDoc]
Type=0
HeaderFile=SimuraysDoc.h
ImplementationFile=SimuraysDoc.cpp
Filter=N

[CLS:CSimuraysView]
Type=0
HeaderFile=SimuraysView.h
ImplementationFile=SimuraysView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDC_EDIT1


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SIM_DRAW




[CLS:CAboutDlg]
Type=0
HeaderFile=Simurays.cpp
ImplementationFile=Simurays.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_SIM_DRAW
Command17=ID_SIM_SETUPPARAM
Command18=ID_SIM_START
Command19=ID_SIM_ANALASIS
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_SIM_DRAW
Command10=ID_SIM_SETUPPARAM
Command11=ID_SIM_START
Command12=ID_SIM_ANALASIS
CommandCount=12

[CLS:CSetupParamDlg]
Type=0
HeaderFile=SetupParamDlg.h
ImplementationFile=SetupParamDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_sourcex
VirtualFilter=dWC

[DLG:IDD_DIALOGSetupParam]
Type=1
Class=CSetupParamDlg
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_simnumber,edit,1350631552
Control4=IDC_STATIC1,static,1342308352
Control5=IDC_EDIT_raydelay,edit,1350631552
Control6=IDC_EDIT_reflectdelay,edit,1350631552
Control7=IDC_STATIC2,static,1342308352
Control8=IDC_STATIC3,static,1342308352
Control9=IDC_EDIT_sourcex,edit,1350631552
Control10=IDC_STATIC4,static,1342308352
Control11=IDC_EDIT_sourcey,edit,1350631552
Control12=IDC_STATIC5,static,1342308352
Control13=IDC_EDIT_dieoutenergy,edit,1350631552
Control14=IDC_STATIC6,static,1342308352
Control15=IDC_EDIT_indexni,edit,1350631552
Control16=IDC_STATIC7,static,1342308352
Control17=IDC_EDIT_absorb,edit,1350631552
Control18=IDC_STATIC8,static,1342308352

[CLS:CAnalasisDlg]
Type=0
HeaderFile=AnalasisDlg.h
ImplementationFile=AnalasisDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOGAnalasis]
Type=1
Class=CAnalasisDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350635652

