
// Lab1HomeWorkDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab1HomeWork.h"
#include "Lab1HomeWorkDlg.h"
#include "afxdialogex.h"

#include <vector>

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


// CLab1HomeWorkDlg dialog



CLab1HomeWorkDlg::CLab1HomeWorkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB1HOMEWORK_DIALOG, pParent)
	, NrForDivSum(0)
	, NrSmallPrim(0)
	, NrBigPrim(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab1HomeWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUM_DIV, NrForDivSum);
	DDX_Text(pDX, IDC_SMALL_PRIM, NrSmallPrim);
	DDX_Text(pDX, IDC_BIG_PRIM, NrBigPrim);
}

BEGIN_MESSAGE_MAP(CLab1HomeWorkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RESETARE, &CLab1HomeWorkDlg::OnBnClickedResetare)
	ON_BN_CLICKED(IDC_SUM_DIV_BUTTON, &CLab1HomeWorkDlg::OnBnClickedSumDivButton)
	ON_BN_CLICKED(IDC_SMALL_PRIM_BUTTON, &CLab1HomeWorkDlg::OnBnClickedSmallPrimButton)
	ON_BN_CLICKED(IDC_BIG_PRIM_BUTTON, &CLab1HomeWorkDlg::OnBnClickedBigPrimButton)
END_MESSAGE_MAP()


// CLab1HomeWorkDlg message handlers

BOOL CLab1HomeWorkDlg::OnInitDialog()
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

void CLab1HomeWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLab1HomeWorkDlg::OnPaint()
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
HCURSOR CLab1HomeWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool VerifyPrim(int n){


	if (n == 0 || n == 1)
	{
		return false;
	}
	if (n == 2)
	{
		return true;
	}
	for (int i = 2; i <= sqrt((float)n); i++)
		if (n % i == 0)
		{
			return false;
		}
	return true;
}

void CLab1HomeWorkDlg::OnBnClickedResetare()
{
	// TODO: Add your control notification handler code here
	NrForDivSum = 0;
	NrSmallPrim = 0;
	NrBigPrim = 0;
	UpdateData(FALSE);
}


void CLab1HomeWorkDlg::OnBnClickedSumDivButton()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int n;
	CString text;
	n = NrForDivSum;
	std::vector<int> divNumbers;
	if (VerifyPrim(n)) {
		text.Format((LPCWSTR)L"Numarul este prim, suma este %d",0);
		AfxMessageBox(text);
		return;
	}
	int d = 2;
	while (d <= int(n / 2)) {
		if (n % d == 0) {
			divNumbers.push_back(d);
		}
		d++;
	}
	int suma = 0;
	CString numbers;
	for (auto& div : divNumbers) {
		suma += div;
		numbers.Format((LPCWSTR)L"%s+%d",numbers,div);
	}
	
	
	text.Format((LPCWSTR)L"Suma divizorilor este %d, divizori sunt %s", suma,numbers);
	AfxMessageBox(text);
	return;
}


void CLab1HomeWorkDlg::OnBnClickedSmallPrimButton()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int n;
	CString text;
	n = NrSmallPrim;
	if (VerifyPrim(n)) {
		text.Format((LPCWSTR)L"Cel mai apropiat numarul prim este %d", n);
		AfxMessageBox(text);
		return;
	}
	while (n > 1) {
		n = n - 1;
		if (VerifyPrim(n)) {
			text.Format((LPCWSTR)L"Cel mai apropiat numarul prim mai mic este %d", n);
			AfxMessageBox(text);
			return;
		}
	}
	UpdateData(FALSE);
}


void CLab1HomeWorkDlg::OnBnClickedBigPrimButton()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int n;
	CString text;
	n = NrBigPrim;
	if (VerifyPrim(n)) {
		text.Format((LPCWSTR)L"Cel mai apropiat numarul prim este %d", n);
		AfxMessageBox(text);
		return;
	}
	while (true) {
		n = n + 1;
		if (VerifyPrim(n)) {
			text.Format((LPCWSTR)L"Cel mai apropiat numarul prim mai mare este %d", n);
			AfxMessageBox(text);
			return;
		}
	}
	UpdateData(FALSE);

}
