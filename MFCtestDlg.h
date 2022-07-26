#include "CMyNewDlg.h"
#include "SerialPort.h"  
// MFCtestDlg.h: 头文件
//

#pragma once
#define WM_MY_MESSAGE     WM_USER+100  //给消息一个ID


// CMFCtestDlg 对话框
class CMFCtestDlg : public CDialogEx
{
// 构造
public:
	
		LRESULT CMFCtestDlg::OnMyMessage1(WPARAM wParam, LPARAM lParam);   //消息1
		LRESULT CMFCtestDlg::OnMyMessage2(WPARAM wParam, LPARAM lParam);   //消息2
		LRESULT CMFCtestDlg::OnMyMessage3(WPARAM wParam, LPARAM lParam);   //消息3
	

	CMFCtestDlg(CWnd* pParent = nullptr);	// 标准构造函数
	CComboBox m_commospd;
	CSerialPort mySerialPort;
	HANDLE hCom1;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST_DIALOG };
#endif
     private:CMyNewDlg* m_pdlg1;
			
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo1();
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit5();
	
};
