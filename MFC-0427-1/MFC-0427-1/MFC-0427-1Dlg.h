
// MFC-0427-1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC04271Dlg �Ի���
class CMFC04271Dlg : public CDialogEx
{
// ����
public:
	CMFC04271Dlg(CWnd* pParent = NULL);	// ��׼���캯��

public:~CMFC04271Dlg(); //��������

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC04271_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	CString Name;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSelchangeList1();
	afx_msg void OnBnClickedOk();
};
