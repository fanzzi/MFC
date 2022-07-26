#pragma once
#include "afxdialogex.h"
#include "SerialPort.h"  


// CMyNewDlg 对话框

class CMyNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyNewDlg)

public:
	CMyNewDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyNewDlg();
	CString m_send;
	CSerialPort mySerialPort;
	HANDLE  m_hComm;
	unsigned char* temp1 = new unsigned char[8];
		CString str;


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
};
