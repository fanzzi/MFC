
// MFCtestDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCtest.h"
#include "MFCtestDlg.h"
#include "afxdialogex.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString head= _T("30 21 ");
#define sum sum


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};








// CMFCtestDlg 对话框



CMFCtestDlg::CMFCtestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTEST_DIALOG, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_commospd);
	
}

BEGIN_MESSAGE_MAP(CMFCtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCtestDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCtestDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCtestDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCtestDlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CMFCtestDlg 消息处理程序

BOOL CMFCtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	
	
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCtestDlg::OnBnClickedButton2()
{
	if (NULL == m_pdlg1)
	{
		// 创建非模态对话框实例   
		m_pdlg1 = new CMyNewDlg();
		m_pdlg1->Create(IDD_DIALOG1, this);
	}
	// 显示非模态对话框   
	m_pdlg1->ShowWindow(SW_SHOW);

}

unsigned char catChar2Hex(unsigned char hByte, unsigned char lByte)
{
	unsigned char ucTmp = 0x00;
	unsigned char hight;
	unsigned char low;
	if ((hByte >= 'A') && (hByte <= 'F'))
	{
		hight = hByte - 'A' + 10;
	}
	else if (hByte >= 'a' && hByte <= 'f')
	{
		hight = hByte - 'a' + 10;
	}
	else if (hByte >= '0' && hByte <= '9')
	{
		hight = hByte - '0';
	}
	else
	{
		ucTmp = 0xff;
	}
	if ((lByte >= 'A') && (lByte <= 'F'))
	{
		low = lByte - 'A' + 10;
	}
	else if (lByte >= 'a' && lByte <= 'f')
	{
		low = lByte - 'a' + 10;
	}
	else if (lByte >= '0' && lByte <= '9')
	{
		low = lByte - '0';
	}
	else
	{
		ucTmp = 0xff;
	}
	ucTmp = (hight << 4) | (low << 0);//高位左移4位，低位不移动，组成一个8位十六进制字符
	return ucTmp;
}


void CMFCtestDlg::OnCbnSelchangeCombo1()
{
	int nIndex = m_commospd.GetCurSel();
	
	CString strCBText;
	
	switch (nIndex) 
	{
	case 0:strCBText="30 21 11 02 00 00 00 00"; break;
//	case 1:strCBText = "11 02 00 00 00 00"; break;
	}
	
	
		
		
	
	if (NULL != m_pdlg1)
	{
		
		UpdateData(true);
         //m_pdlg1->str= strCBText;
		

		m_pdlg1->SetDlgItemText(IDC_EDIT2, strCBText);
		UpdateData(false);
		//CString strCBText = {};
		
	}
	;

}


void CMFCtestDlg::OnBnClickedButton1()
{
	
	
	hCom1 = mySerialPort.InitPort(2, CBR_115200, 'N', 8, 1, EV_RXCHAR);
	
	if (hCom1 == INVALID_HANDLE_VALUE)
	
	MessageBox(_T("初始化失败！"));
	else
	{
		MessageBox(_T("初始化成功！"));//是否打开串口，3就是你外设连接电脑的com口，可以在设备管理器查看，然后更改这个参数
		
		if (NULL != m_pdlg1)
		{
			this->m_pdlg1->m_hComm = hCom1;

		}
	}
	
	//string str1= CSerialPort::ListenThread;
}




CString Dec2Hex(unsigned int intDec)
{
	CString strHex;
	char charHex[255];
	sprintf(charHex, "%04x", intDec);
	strHex = charHex;
	if (strHex.GetLength() == 1)
		strHex = _T("0") + strHex;
	return strHex;
}

void CMFCtestDlg::OnEnChangeEdit5()
{
	CString strTime;
	CString strTime1;
	GetDlgItemText(IDC_EDIT5, strTime);
	int i = 0;

	i = _ttoi(strTime);
	strTime1 = Dec2Hex(i);


}
