
// MFC-0427-1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-0427-1.h"
#include "MFC-0427-1Dlg.h"
#include "afxdialogex.h"

#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMFC04271Dlg 对话框



CMFC04271Dlg::CMFC04271Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC04271_DIALOG, pParent)
	, Name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC04271Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_Text(pDX, IDC_EDIT1, Name);
}

BEGIN_MESSAGE_MAP(CMFC04271Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC04271Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC04271Dlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFC04271Dlg::OnSelchangeList1)
END_MESSAGE_MAP()


// CMFC04271Dlg 消息处理程序

BOOL CMFC04271Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString  filename;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
        filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		while (ifs >> s) {
			CString str= CString(s.c_str());
            Lbox.AddString(str);
		}
		
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC04271Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC04271Dlg::OnPaint()
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
HCURSOR CMFC04271Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC04271Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFC04271Dlg::OnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  t;
	int num = Lbox.GetCurSel();                // 取得当前所选记录号
	Lbox.GetText(num, t);  // 获取列表框A的选中的字符串，并存入缓存t中 
	SetDlgItemText(IDC_EDIT1, t); // 将选中列表项的字符串显示到编辑框中 
}


void CMFC04271Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  str;
	this->UpdateData(true); 
	str=Name;	
	UpdateData(false);
	int num = Lbox.GetCurSel(); // 取得当前所选记录号
	Lbox.DeleteString(num);// 删除列表框A的第num项字符串 
	Lbox.InsertString(num, str);    // 把缓存str中的字符串插入到列表框A的

	CFileDialog cfd(false);
	//int r = cfd.DoModal();
	//if (r == IDOK) {
		ofstream ofs(cfd.GetPathName());
		ofs << CT2A(str.GetString()) << endl;
	//}
	

}

CMFC04271Dlg::~CMFC04271Dlg()
{

}
