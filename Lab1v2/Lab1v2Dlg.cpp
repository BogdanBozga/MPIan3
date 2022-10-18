
// Lab1v2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab1v2.h"
#include "Lab1v2Dlg.h"
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


// CLab1v2Dlg dialog



CLab1v2Dlg::CLab1v2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB1V2_DIALOG, pParent)
	, Nr(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab1v2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUMAR, Nr);
}

BEGIN_MESSAGE_MAP(CLab1v2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLab1v2Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_NUMAR, &CLab1v2Dlg::OnEnChangeNumar)
	ON_BN_CLICKED(IDC_RESETARE, &CLab1v2Dlg::OnBnClickedResetare)
	ON_BN_CLICKED(IDC_VERIFICARE, &CLab1v2Dlg::OnBnClickedVerificare)
END_MESSAGE_MAP()


// CLab1v2Dlg message handlers

BOOL CLab1v2Dlg::OnInitDialog()
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

void CLab1v2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLab1v2Dlg::OnPaint()
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
HCURSOR CLab1v2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab1v2Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CLab1v2Dlg::OnEnChangeNumar()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLab1v2Dlg::OnBnClickedResetare()
{
	// TODO: Add your control notification handler code here
	Nr = 0;
	UpdateData(FALSE);
}


void CLab1v2Dlg::OnBnClickedVerificare()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString text;
	int n;
	n = Nr;
	if (n == 0 || n == 1)
	{
		MessageBox((LPCWSTR)L"Numerele 0 si 1 nu sunt prime!");
		return;
	}

	if (n == 2)
	{
		MessageBox((LPCWSTR)L"Numarul 2 este singurul numar prim care este par!");
		return;
	}
	for (int i = 2; i <= sqrt((float)n); i++)
		if (n % i == 0)
		{
			text.Format((LPCWSTR)L"Numarul %d nu este prim (se divide prin %d)", n, i);
			AfxMessageBox(text);
			return;
		}
	text.Format((LPCWSTR)L"Numarul %d este prim", n);
	AfxMessageBox(text);
	UpdateData(FALSE);
}
