
// CalciTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalciTest.h"
#include "CalciTestDlg.h"
#include "afxdialogex.h"
#include "Utility.h"


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


// CCalciTestDlg dialog



CCalciTestDlg::CCalciTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCITEST_DIALOG, pParent)
	/*, firstNumber(_T(""))
	, secondNumber(_T(""))*/
	, FInalAnswer(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalciTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1_num1Input, firstNumber);
	//DDX_Text(pDX, IDC_EDIT2_num2Input, secondNumber);
	DDX_Control(pDX, IDC_EDIT1_num1Input, m_inputFirst);
	DDX_Control(pDX, IDC_EDIT2_num2Input, m_inputSecond);
	DDX_Control(pDX, IDC_BUTTON_Calci, calculateAns);
	//DDX_Control(pDX, IDC_EDIT3_ans, ansDisplay);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
	DDX_Control(pDX, IDC_LIST2, m_listAll);
	DDX_Text(pDX, IDC_STATIC_Answer, FInalAnswer);
	DDX_Control(pDX, IDC_STATIC_Answer, m_answer);
	
}

BEGIN_MESSAGE_MAP(CCalciTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Calci, &CCalciTestDlg::OnClickedButtonCalci)
	
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CCalciTestDlg::OnBnClickedButtonClear)
	ON_STN_CLICKED(IDC_STATIC_Answer, &CCalciTestDlg::OnStnClickedStaticAnswer)
END_MESSAGE_MAP()


// CCalciTestDlg message handlers

BOOL CCalciTestDlg::OnInitDialog()
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
	m_answer.SetWindowTextW(_T("0.00"));
	m_comboBox.SetCurSel(0);
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalciTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalciTestDlg::OnPaint()
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
HCURSOR CCalciTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalciTestDlg::OnClickedButtonCalci()
{
	Utility utility;
	CString first;
	m_inputFirst.GetWindowTextW(first);
	CString second;
	m_inputSecond.GetWindowTextW(second);

	float num1 = _ttof(first);
	float num2 = _ttof(second);
	if (first.IsEmpty() || second.IsEmpty() ) {
		AfxMessageBox(_T("Please enter valid numbers"));
		return;
	}

	int selectedIndex = m_comboBox.GetCurSel();
	if (selectedIndex > 3) {
		AfxMessageBox(_T("Invalid operate3ion"));
		return;
	}
	else {
		CString operationString;
		float result = 0;
		Utility::Result type = Utility::Result::Failed;
		switch (selectedIndex) {
		case(0):
			type = utility.performOperation(num1, num2, Utility::ADDITION, result);
				
				
	
			operationString = "ADDITON";
			break;
		case(1):
			type = utility.performOperation(num1, num2, Utility::SUBSTRACTION, result);
			operationString = "SUBSTRACTION";
			break;
		case(2):
			type = utility.performOperation(num1, num2, Utility::MULTIPLICATION,result);
			operationString = "MULTIPLICATION";
			break;
		case(3):
			type = utility.performOperation(num1, num2, Utility::DIVISION, result);
			operationString = "DIVISION";
			break;
		default:
			break;
		}
		CString finalAns;
		if (type == Utility::Result::Success) {
			finalAns.Format(_T("%f"), result);
			//ansDisplay.SetWindowTextW(finalAns);
			operationString.Append(_T(" "));
			operationString.Append(finalAns);
		}
		else {
			operationString.Append(L"Error");
		}
		m_listAll.AddString(operationString);
		m_answer.SetWindowTextW(finalAns);
		
	/*	m_listAll.SetItemData()*/
	}

}



void CCalciTestDlg::OnBnClickedButtonClear()
{
	m_listAll.ResetContent();
}

void CCalciTestDlg::OnStnClickedStaticAnswer()
{
	// TODO: Add your control notification handler code here
}
