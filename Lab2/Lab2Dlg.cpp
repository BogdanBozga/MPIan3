
// Lab2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab2.h"
#include "Lab2Dlg.h"
#include "afxdialogex.h"

#include <vector>
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLab2Dlg dialog



CLab2Dlg::CLab2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB2_DIALOG, pParent)
	, NrA(0)
	, NrB(0)
	, NrCmmdc(0)
	, NrCmmmc(0)
	, NrARed(0)
	, NrBRed(0)
	, ListaA(_T(""))
	, ListaB(_T(""))
	, CmmdList(0)
	, CmmmLista(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A, NrA);
	DDX_Text(pDX, IDC_B, NrB);
	DDX_Text(pDX, IDC_CMMDC, NrCmmdc);
	DDX_Text(pDX, IDC_CMMMC, NrCmmmc);
	DDX_Text(pDX, IDC_ARED, NrARed);
	DDX_Text(pDX, IDC_BRED, NrBRed);
	DDX_Text(pDX, IDC_LISTAA, ListaA);
	DDX_Text(pDX, IDC_LISTAB, ListaB);
	DDX_Text(pDX, IDC_CMMDCLIST, CmmdList);
	DDX_Text(pDX, IDC_CMMMCLISTA, CmmmLista);
}

BEGIN_MESSAGE_MAP(CLab2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RESET, &CLab2Dlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_CALC, &CLab2Dlg::OnBnClickedCalc)
	ON_BN_CLICKED(IDC_REDUCERE, &CLab2Dlg::OnBnClickedReducere)
	ON_BN_CLICKED(IDC_CALCLISTA, &CLab2Dlg::OnBnClickedCalclista)
END_MESSAGE_MAP()


// CLab2Dlg message handlers

BOOL CLab2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab2Dlg::OnBnClickedReset()
{
	// TODO: Add your control notification handler code here
	NrA = NrB = NrCmmdc = NrCmmmc = 0;
	NrARed = 0;
	NrBRed = 0;
	UpdateData(FALSE);
}

int CalcCmmdc(int x, int y) {


	if (x == y && y == 0)
	{

		AfxMessageBox((LPCWSTR)L"A si B nu pot fi simultan nule!");
		return x;

	}
	int r;
	if (y != 0)
		do
		{
			r = x % y;
			x = y;
			y = r;
		} while (r != 0);
	return x;
}

int CalcCmmmc(int x, int y) {
	int cmmdc = CalcCmmdc(x, y);
	return x * y / cmmdc;
}

void CLab2Dlg::OnBnClickedCalc()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int x = CalcCmmdc(NrA, NrB);
	NrCmmdc = x;
	NrCmmmc = NrA * NrB / NrCmmdc;
	UpdateData(FALSE);


}


void CLab2Dlg::OnBnClickedReducere()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int x;
	x = CalcCmmdc(NrA, NrB);
		NrARed = NrA / x;
		NrBRed = NrB / x;

	UpdateData(FALSE);
}


void CLab2Dlg::OnBnClickedCalclista()
{
	UpdateData();
	CString listA = ListaA;
	CString listB = ListaB;

	
	CString field;


	std::vector<CString> vectorB;
	int index = 0;
	// last argument is the delimitter
	while (AfxExtractSubString(field, ListaB, index, _T(', ')))
	{
		vectorB.push_back(field);
		++index;
	}

	std::vector<int> numbers;
	for (auto& b : vectorB) {
		numbers.push_back(_tstoi(b));
	}
	int cmmdc = numbers.front();
	int cmmmc = numbers.front();
	for (int b : numbers) {
		cmmdc = CalcCmmdc(cmmdc, b);
		cmmmc = CalcCmmmc(cmmmc, b);
	}

	CmmdList = cmmdc;
	CmmmLista = cmmmc;
	UpdateData(false);

	// TODO: Add your control notification handler code here
}
