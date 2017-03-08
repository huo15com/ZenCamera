// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "JHCap.h"
#include<process.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef WIN64
#pragma comment(lib,"JHCap2.lib")
#else
#pragma comment(lib,"JHCap2.lib")

#endif

 
 
 


int m_totalFrame=0;
int __stdcall SnapThreadCallbackEx(unsigned char *pImageBuffer, int width, int height, int format, void *a)  //回调函数
{
	
	m_totalFrame++;
	//if((format & CAMERA_IMAGE_GRAY8) || (format & CAMERA_IMAGE_RAW8))  //8bit
	//{
	//	for (int i= 0.5*height; i<=0.5*height+10; i++)
	//	{
	//		for (int j=0; j<width; j++)
	//		{
	//			*(pImageBuffer+i*width+j) = 0x00;
	//		}
	//	}
	//}
	//else if(format == CAMERA_IMAGE_BMP)  //24bit
	//{
	//	for (int i= 100; i<=120; i++)
	//	{
	//		for (int j=0; j<width; j++)
	//		{
	//			*(pImageBuffer+(i*width+j)*3+0) = 0x00;
	//			*(pImageBuffer+(i*width+j)*3+1) = 0x00;
	//			*(pImageBuffer+(i*width+j)*3+2) = 0xff;
	//		}
	//	}
	//}

	return 0;
}

int __stdcall SnapThreadCallback(unsigned char *pImageBuffer, int width, int height, int format)  //回调函数
{
	
	m_totalFrame++;
	//if((format & CAMERA_IMAGE_GRAY8) || (format & CAMERA_IMAGE_RAW8))  //8bit
	//{
	//	for (int i= 0.5*height; i<=0.5*height+10; i++)
	//	{
	//		for (int j=0; j<width; j++)
	//		{
	//			*(pImageBuffer+i*width+j) = 0x00;
	//		}
	//	}
	//}
	//else if(format == CAMERA_IMAGE_BMP)  //24bit
	//{
	//	for (int i= 100; i<=120; i++)
	//	{
	//		for (int j=0; j<width; j++)
	//		{
	//			*(pImageBuffer+(i*width+j)*3+0) = 0x00;
	//			*(pImageBuffer+(i*width+j)*3+1) = 0x00;
	//			*(pImageBuffer+(i*width+j)*3+2) = 0xff;
	//		}
	//	}
	//}

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg)
	m_RowStart = 0;
	m_ColumnStart = 0;
	m_ROIWidth = 0;
	m_ROIHeight = 0;
	m_Gain = 0;
	m_Exposure = 0;
	m_Gamma = 0;
	m_Contrast = 0;
	m_fps=0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	DDX_Text(pDX, IDC_ROIOFFSETX, m_RowStart);
	DDV_MinMaxLong(pDX, m_RowStart, 0, 5000);
	DDX_Text(pDX, IDC_ROIOFFSETY, m_ColumnStart);
	DDV_MinMaxLong(pDX, m_ColumnStart, 0, 5000);
	DDX_Text(pDX, IDC_ROIWIDTH, m_ROIWidth);
	DDV_MinMaxLong(pDX, m_ROIWidth, 0, 5000);
	DDX_Text(pDX, IDC_ROIHEIGHT, m_ROIHeight);
	DDV_MinMaxLong(pDX, m_ROIHeight, 0, 5000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_CBN_SELCHANGE(IDC_MULTICAM, OnSelchangeMulticam)
	ON_CBN_SELCHANGE(IDC_RESOLUTION, OnSelchangeResolution)
	ON_BN_CLICKED(IDC_ROIAPPLY, OnROIApply)
	ON_BN_CLICKED(IDC_FLIPX, OnFlipx)
	ON_BN_CLICKED(IDC_FLIPY, OnFlipy)
	ON_BN_CLICKED(IDC_GROUP0, OnGroup0)
	ON_BN_CLICKED(IDC_GROUP1, OnGroup1)
	ON_BN_CLICKED(IDC_ONEPUSHWB, OnOnepushwb)
	ON_BN_CLICKED(IDC_SAVEBMP, OnSavebmp)
	ON_BN_CLICKED(IDC_SAVEJPG, OnSavejpg)
	ON_BN_CLICKED(IDC_REFRESH, OnRefresh)
	ON_BN_CLICKED(IDC_OUT, OnOut)
	ON_BN_CLICKED(IDC_STROBE, OnStrobe)
	ON_BN_CLICKED(IDC_STROBEPOLARITY, OnStrobepolarity)
	ON_BN_CLICKED(IDC_TRIGGERPOLARITY, OnTriggerpolarity)
	ON_BN_CLICKED(IDC_SNAPSHOT, OnSnapshot)
	ON_BN_CLICKED(IDC_SETTRIGGERMODE, OnSettriggermode)
	ON_BN_CLICKED(IDC_TRIGGER, OnBnClickedTrigger)
	ON_BN_CLICKED(IDC_SHOW, OnBnClickedShow)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

BOOL CDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//get camera count
	int CamAllNum=0;
	CameraGetCount(&CamAllNum);

	// add camera name
	char *name=new char[255];
	char *model=new char[255];
	NameComBox=(CComboBox*)GetDlgItem(IDC_MULTICAM);
	if(CamAllNum>0)
	{
		for(int i=0; i<CamAllNum; i++)
		{
		   CameraGetName(i, name, model);
		   CString temp;
		   temp.Format("%s #%d",model,i);
		   NameComBox->InsertString(i,_T(temp));

		}
	NameComBox->SetCurSel(0);
	}
	else
		return false;
	delete  [] name;
	name=NULL;
	delete  [] model;
    m_index=0;
	CButton *pGroup0=(CButton *)GetDlgItem(IDC_GROUP0);
	pGroup0->SetCheck(1);
	
	//Init Camera
	OnSelchangeMulticam(); 
	return TRUE;  
}

void CDemoDlg::OnClose() 
{
	OnExit();
}

void CDemoDlg::OnExit() 
{
	CameraStop(m_index);
	CameraFree(m_index);
	CDialog::OnOK();
	
}
void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDemoDlg::OnPlay()  //播放
{

	SetTimer(TIMER1,1000,NULL);
	CWnd *p=GetDlgItem(IDC_IMAGE);
	HWND hWnd=p->GetSafeHwnd();  
	//CameraSetOption(m_index,CAMERA_IMAGE_GRAY8);  //set option to gray8
	//CameraPlayEx(m_index,hWnd,SnapThreadCallbackEx, 0);
	CameraPlay(m_index,hWnd,SnapThreadCallback);
}

void CDemoDlg::OnStop()  //停止
{
	CameraStop(m_index);
	CString t_fps;
	m_fps=0;
	m_totalFrame=0;
	t_fps.Format("%2.2f",m_fps);

	GetDlgItem(IDC_Fps)->SetWindowText(t_fps);
	KillTimer(TIMER1);
}

void CDemoDlg::OnSelchangeMulticam()    //选择相机
{
	CameraStop(m_index);
	m_index = NameComBox->GetCurSel();
	CameraInit(m_index);

	////////////////make up resolution/////////////
	ResoComBox=(CComboBox*)GetDlgItem(IDC_RESOLUTION);
    ResoComBox->ResetContent();   

	int index=0,width=0,height=0,depth=0, count=0;
	CameraGetResolutionCount(m_index,&count);
	for(int j=0;j<count;j++)
	{
		CameraGetResolution( m_index,j,&width, &height);
		CString temp;
		temp.Format("%d*%d",width,height);
		ResoComBox->InsertString(j, _T(temp)); 
	}
	ResoComBox->SetCurSel(0); //设置选中的项

	int width1=0,height1=0;
    CameraSetResolution(m_index,0,&width1, &height1);
	
}

void CDemoDlg::OnSelchangeResolution()    //选择分辨率
{
	int width=0,height=0,depth=0;
	int nIndex = ResoComBox->GetCurSel();
	CameraGetResolution(m_index,nIndex,&width,&height);
	CameraSetResolution(m_index,nIndex,&width,&height);  
}

void CDemoDlg::OnROIApply()              //感兴趣区域
{
	UpdateData(true);
	long rowOffset=m_RowStart;
	long columnOffset=m_ColumnStart;
	long width=m_ROIWidth;
	long height=m_ROIHeight;
	if((width>=1) &&  (height>=1)&&(rowOffset>=0)&&(columnOffset>=0))
    	CameraSetROI(m_index,rowOffset,columnOffset,width,height);
	else
		AfxMessageBox("please enter a valid number!");
}

void CDemoDlg::OnFlipx()        //水平翻转
{
	bool flag;
	CameraGetMirrorX(m_index,&flag);
	CameraSetMirrorX(m_index,!flag);
}


void CDemoDlg::OnFlipy()        //垂直翻转
{
	bool flag;
	CameraGetMirrorY(m_index,&flag);
	CameraSetMirrorY(m_index,!flag);
}

void CDemoDlg::OnGroup0()     //载入第0组参数
{
	CameraLoadParameter(m_index,0);
}

void CDemoDlg::OnGroup1()     //载入第0组参数    
{
	CameraLoadParameter(m_index,1);	
}

void CDemoDlg::OnOnepushwb()   //一键白平衡
{
	CameraOnePushWB(m_index);
}

void CDemoDlg::OnSavebmp()     //保存BMP图片
{
	CString FilePathName; 
	CFileDialog dlg(false,_T("bmp"), NULL,   /*OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT*/0, _T("bmp Files (*.bmp)|*.bmp||"));     ///TRUE为OPEN对话框，FALSE为SAVE AS对话框 	　　
   	int ret=dlg.DoModal();
	if(IDOK==ret)		
	{
	   FilePathName=dlg.GetPathName();   
    }
    CameraSaveBMPB(m_index,(LPSTR)(LPCTSTR)FilePathName);	
}

void CDemoDlg::OnSavejpg()   //保存JPG图片
{
	int format;
	CameraGetOption(m_index,&format);
	if((format & CAMERA_IMAGE_RAW8) || (format & CAMERA_IMAGE_GRAY8))
	{
		AfxMessageBox("Cann't save 8bits jpg file.");
		return ;
	}
	CString FilePathName; 
	CFileDialog dlg(false,_T("jpg"), NULL,   /*OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT*/0, _T("jpg Files (*.jpg)|*.jpg||"));     ///TRUE为OPEN对话框，FALSE为SAVE AS对话框 	　　
    int ret=dlg.DoModal();
	if(IDOK==ret)		
	{
	   FilePathName=dlg.GetPathName();  
    }
	CameraSaveJpegB(m_index,(LPSTR)(LPCTSTR)FilePathName, true);	   
	
}

void CDemoDlg::OnRefresh() 
{
    int io=0;
	CameraGetGPIO(m_index,&io);
	((CButton *)GetDlgItem(IDC_IN))->SetCheck(io & CAMERA_IO_IN);	
}

void CDemoDlg::OnOut() 
{
	int checked=((CButton *)GetDlgItem(IDC_OUT))->GetCheck();
	CameraSetGPIO(m_index,CAMERA_IO_OUT,checked?CAMERA_IO_OUT:0);
}

void CDemoDlg::OnStrobe() 
{
	int checked=((CButton *)GetDlgItem(IDC_STROBE))->GetCheck();
	if(checked==0)
		CameraEnableStrobe(m_index,false);
	else
		CameraEnableStrobe(m_index,true);
}

void CDemoDlg::OnStrobepolarity() 
{
	int checked=((CButton *)GetDlgItem(IDC_STROBEPOLARITY))->GetCheck();
	if(checked==0)
		CameraSetStrobePolarity(m_index,false);
	else
		CameraSetStrobePolarity(m_index,true);	
}

void CDemoDlg::OnTriggerpolarity() 
{
	int checked=((CButton *)GetDlgItem(IDC_TRIGGERPOLARITY))->GetCheck();
	if(checked==0)
		CameraSetTriggerPolarity(m_index,false);
	else
		CameraSetTriggerPolarity(m_index,true);	
}

void CDemoDlg::OnSnapshot() 
{
	// TODO: Add your control notification handler code here
}

void CDemoDlg::OnSettriggermode() 
{
	int checked=((CButton *)GetDlgItem(IDC_SETTRIGGERMODE))->GetCheck();
	if(checked==0)
		CameraSetSnapMode(m_index,CAMERA_SNAP_CONTINUATION);
	else
		CameraSetSnapMode(m_index,CAMERA_SNAP_TRIGGER);		
}


void CDemoDlg::OnBnClickedTrigger()
{
	CameraTriggerShot(m_index);
}


void CDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
   if(m_fps==0)
		m_fps=m_totalFrame;
	else
    m_fps = 0.4*m_fps + 0.6*m_totalFrame;
	CString t_fps;
	t_fps.Format("%2.2f",m_fps);

	TRACE(t_fps);
	GetDlgItem(IDC_Fps)->SetWindowText(t_fps);
	m_totalFrame=0;
	CDialog::OnTimer(nIDEvent);
}


void CDemoDlg::OnBnClickedShow()
{
	// TODO: 在此添加控件通知处理程序代码
	CameraClearHostBuffer(m_index);

	CWnd *p=GetDlgItem(IDC_IMAGE);
	HWND hWnd=p->GetSafeHwnd();  

	RECT rect;
	::GetClientRect(hWnd, &rect);
	HDC hdc = ::GetDC(hWnd);
	CameraShowImage(m_index,hdc,rect.left,rect.top,rect.right-rect.left, rect.bottom-rect.top,SnapThreadCallback);
}
