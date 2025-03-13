
// CalciTestDlg.h : header file
//

#pragma once


// CCalciTestDlg dialog
class CCalciTestDlg : public CDialogEx
{
// Construction
public:
	CCalciTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCITEST_DIALOG };
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
	
	
	
/*	CString firstNumber;
	CString secondNumber*/;
	
	afx_msg void OnClickedButtonCalci();
	CEdit m_inputFirst;
	CEdit m_inputSecond;
	CButton calculateAns;
	CEdit ansDisplay;
	CComboBox m_comboBox;
	
private:
	CListBox m_listAll;

public:
	afx_msg void OnBnClickedButtonClear();
	CString FInalAnswer;
	CStatic m_answer;
	afx_msg void OnStnClickedStaticAnswer();
};
