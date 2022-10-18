
// Lab1v2Dlg.h : header file
//

#pragma once


// CLab1v2Dlg dialog
class CLab1v2Dlg : public CDialogEx
{
// Construction
public:
	CLab1v2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB1V2_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeNumar();
	afx_msg void OnBnClickedResetare();
	afx_msg void OnBnClickedVerificare();
	int Nr;
};
