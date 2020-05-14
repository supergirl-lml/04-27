
// MFC-0427-1Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFC04271Dlg �Ի���



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


// CMFC04271Dlg ��Ϣ�������

BOOL CMFC04271Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC04271Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC04271Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC04271Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFC04271Dlg::OnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString  t;
	int num = Lbox.GetCurSel();                // ȡ�õ�ǰ��ѡ��¼��
	Lbox.GetText(num, t);  // ��ȡ�б��A��ѡ�е��ַ����������뻺��t�� 
	SetDlgItemText(IDC_EDIT1, t); // ��ѡ���б�����ַ�����ʾ���༭���� 
}


void CMFC04271Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString  str;
	this->UpdateData(true); 
	str=Name;	
	UpdateData(false);
	int num = Lbox.GetCurSel(); // ȡ�õ�ǰ��ѡ��¼��
	Lbox.DeleteString(num);// ɾ���б��A�ĵ�num���ַ��� 
	Lbox.InsertString(num, str);    // �ѻ���str�е��ַ������뵽�б��A��

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
