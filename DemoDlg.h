// DemoDlg.h : header file
//

#if !defined(AFX_DEMODLG_H__3B652C3C_F5A9_4E5C_830F_923344C11CEA__INCLUDED_)
#define AFX_DEMODLG_H__3B652C3C_F5A9_4E5C_830F_923344C11CEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define TIMER1 1
/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	CDemoDlg(CWnd* pParent = NULL);	// standard constructor
	void OnExit();

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	enum { IDD = IDD_DEMO_DIALOG };
	CSliderCtrl	m_ContrastCtrl;
	CSliderCtrl	m_GammaCtrl;
	CSliderCtrl	m_ExposureCtrl;
	CSliderCtrl	m_GainCtrl;
	long	m_RowStart;
	long	m_ColumnStart;
	long	m_ROIWidth;
	long	m_ROIHeight;
	int		m_Gain;
	int		m_Exposure;
	int		m_Gamma;
	int		m_Contrast;
	double  m_fps;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CComboBox *ResoComBox;
	CComboBox *NameComBox;
	int m_index;

	// Generated message map functions
	//{{AFX_MSG(CDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlay();
	afx_msg void OnEditchangeMulticam();
	afx_msg void OnStop();
	afx_msg void OnSelchangeMulticam();
	afx_msg void OnSelchangeResolution();
	afx_msg void OnROIApply();
	afx_msg void OnFlipx();
	afx_msg void OnFlipy();
	afx_msg void OnGroup0();
	afx_msg void OnGroup1();
	afx_msg void OnOnepushwb();
	afx_msg void OnSavebmp();
	afx_msg void OnSavejpg();
	afx_msg void OnRefresh();
	afx_msg void OnOut();
	afx_msg void OnStrobe();
	afx_msg void OnStrobepolarity();
	afx_msg void OnTriggerpolarity();
	afx_msg void OnSnapshot();
	afx_msg void OnSettriggermode();
	afx_msg void OnBnClickedTrigger();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBnClickedShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__3B652C3C_F5A9_4E5C_830F_923344C11CEA__INCLUDED_)
