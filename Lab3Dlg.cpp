
// Lab3Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab3.h"
#include "Lab3Dlg.h"
#include "afxdialogex.h"

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


// CLab3Dlg dialog



CLab3Dlg::CLab3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB3_DIALOG, pParent)
	, Operatie(0)
	, Rezultat(0)
	, A(0)
	, B(0)
	, Text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_OPERATIE1, Operatie);
	DDX_Text(pDX, IDC_RESULT, Rezultat);
	DDX_Text(pDX, IDC_A, A);
	DDX_Text(pDX, IDC_B, B);
	DDX_Text(pDX, IDC_STATICC, Text);
}

BEGIN_MESSAGE_MAP(CLab3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &CLab3Dlg::OnBnClickedCalculeaza)
END_MESSAGE_MAP()


// CLab3Dlg message handlers

BOOL CLab3Dlg::OnInitDialog()
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

void CLab3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLab3Dlg::OnPaint()
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
HCURSOR CLab3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab3Dlg::OnBnClickedCalculeaza()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	switch (Operatie) {
	case 0:

		Rezultat = A + B;
		Text = "A+B=";
		break;

	case 1:
		Rezultat = A - B;
		Text = "A-B=";
		break;
	case 2:
		Rezultat = A * B;
		Text = "A*B=";
		break;
	case 3:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)A / B;
		Text = "A/B=";
		break;

	case 4:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = A / B;
		Text = "[A/B]=";
		break;
	case 5:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)A / B - A / B;
		Text = "{A/B}=";
		break;

	case 6:
		Rezultat = A % B;
		Text = "A%B=";
		break;
	default: AfxMessageBox((LPCWSTR)L"Nu s-a optat pentru o operatie");
	}
	UpdateData(FALSE);
}

