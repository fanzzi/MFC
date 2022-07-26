
#include "pch.h"
#include "MFCtest.h"
#include "afxdialogex.h"
#include "CMyNewDlg.h"
#include "MFCtestDlg.h"
#include <string>

#include <iostream>

// CMyNewDlg 对话框

IMPLEMENT_DYNAMIC(CMyNewDlg, CDialogEx)

CMyNewDlg::CMyNewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_send(_T(""))
{
	

}

CMyNewDlg::~CMyNewDlg()
{
}


void CMyNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_send);

}


BEGIN_MESSAGE_MAP(CMyNewDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &CMyNewDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyNewDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyNewDlg 消息处理程序


void CMyNewDlg::OnEnChangeEdit2()
{
	
	
}
unsigned char* catChar2Hex(unsigned char *s, unsigned char bits[])
{
	//unsigned char bits = 0x00;
	int i, n = 0;
	for (i = 0; s[i]; i += 3) {
		if (s[i] >= 'A' && s[i] <= 'F')
		{bits[n] = s[i] - 'A' + 10;

		}
		else if (s[i] >= 'a' && s[i] <= 'f')
		
			{bits[n] = s[i] - 'a' + 10;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			bits[n] = s[i] - '0';
		}
		else
		{
			bits[n] = 0xff;
		}
		if (s[i + 1] >= 'A' && s[i + 1] <= 'F')
		{
			bits[n] = (bits[n] << 4) | (s[i + 1] - 'A' + 10);
		}
		else if (s[i + 1] >= 'a' && s[i + 1] <= 'f')
		{
			bits[n] = (bits[n] << 4) | (s[i + 1] - 'a' + 10);
		}
		else if (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			bits[n] = (bits[n] << 4) | (s[i + 1] - '0');
		}
		else
		{
			bits[n] = 0xff;
		}
		
	}//高位左移4位，低位不移动，组成一个8位十六进制字符
	return bits;
}



void CMyNewDlg::OnBnClickedButton1()
{
	DWORD readsize, dwError;
	COMSTAT cs;
	char buffer[1024];
	CString m_Recv;
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	//str.Find(_T("30 21 "));

	unsigned char* ptr = new unsigned char[48];
	std::string strr = CT2A(str.GetString());
	ptr = (unsigned char*)strr.c_str();
	/*unsigned char* str1 = new unsigned char[20];
	unsigned char* str2 = new unsigned char[20];
//    unsigned char temp2[10];
	str2 = catChar2Hex(ptr, str1);

	//////////////////////////////////////////////////
	/*    char stream[10];
		char text[256 * 3 + 1] = {0};
		int nbytes = hex2bytes(ptr, stream, 10);
		if (nbytes != -1)
		{
			int i = 0;
			for (; i < nbytes; ++i)
			{
				char hextext[4];
			   sprintf(hextext,"%02c",stream[i]);
			   strcat(text, hextext);
			}
		}
		unsigned char* str1 = (unsigned char*)text;
		*/
	mySerialPort.WriteData(m_hComm, ptr, 24);
	readsize = 0;

	ClearCommError(m_hComm, &dwError, &cs);//取得状态

	//数据是否大于所准备缓冲区

	if (cs.cbInQue > sizeof(buffer))

	{

		PurgeComm(m_hComm, PURGE_RXCLEAR);//清除通信端口数据



	}

	memset(buffer, 0, sizeof(buffer));

	ReadFile(m_hComm, buffer, cs.cbInQue, &readsize, 0);

	if (readsize > 0)

	{

		

		buffer[cs.cbInQue] = '\0';
		//返回字符串的长度
		int T_sizey = MultiByteToWideChar(CP_ACP, 0, buffer, -1, NULL, 0);
		TCHAR* stry = new TCHAR[sizeof(wchar_t) * T_sizey];
		MultiByteToWideChar(CP_ACP, 0, buffer, -1, stry, T_sizey);
		CString s;
		s = stry;
		int n = s.Find(L"EB 21");
		CString strResult = s.Mid(n, 32);
		SetDlgItemText(IDC_EDIT1, strResult);


		Sleep(1000);



	}
}
