
// Lab1HomeWorkDlg.h : header file
//

#pragma once


// CLab1HomeWorkDlg dialog
class CLab1HomeWorkDlg : public CDialogEx
{
// Construction
public:
	CLab1HomeWorkDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB1HOMEWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int NrForDivSum;
	int NrSmallPrim;
	int NrBigPrim;
	afx_msg void OnBnClickedResetare();
	afx_msg void OnBnClickedSumDivButton();
	afx_msg void OnBnClickedSmallPrimButton();
	afx_msg void OnBnClickedBigPrimButton();
};
