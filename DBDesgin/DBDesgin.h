
// DBDesgin.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDBDesginApp:
// �йش����ʵ�֣������ DBDesgin.cpp
//

class CDBDesginApp : public CWinApp
{
public:
	CDBDesginApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDBDesginApp theApp;