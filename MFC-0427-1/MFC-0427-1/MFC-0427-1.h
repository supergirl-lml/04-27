
// MFC-0427-1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC04271App: 
// �йش����ʵ�֣������ MFC-0427-1.cpp
//

class CMFC04271App : public CWinApp
{
public:
	CMFC04271App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC04271App theApp;