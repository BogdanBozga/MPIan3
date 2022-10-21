
// Lab2Dlg.h : header file
//

#pragma once


// CLab2Dlg dialog
class CLab2Dlg : public CDialogEx
{
// Construction
public:
	CLab2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB2_DIALOG };
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
	int NrA;
	int NrB;
	int NrCmmdc;
	int NrCmmmc;
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedCalc();
	int NrARed;
	int NrBRed;
	afx_msg void OnBnClickedReducere();
	CString ListaA;
	CString ListaB;
	int CmmdList;
	int CmmmLista;
	afx_msg void OnBnClickedCalclista();
};
