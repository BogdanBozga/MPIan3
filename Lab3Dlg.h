
// Lab3Dlg.h : header file
//

#pragma once


// CLab3Dlg dialog
class CLab3Dlg : public CDialogEx
{
// Construction
public:
	CLab3Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB3_DIALOG };
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
	int Operatie;
	afx_msg void OnBnClickedOperatie3();
	double Rezultat;
	int A;
	int B;
	afx_msg void OnBnClickedCalculeaza();
	CString Text;
	afx_msg void OnBnClickedOperatie4();
};
