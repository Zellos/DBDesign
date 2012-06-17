
// DBDesgin.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "DBDesgin.h"
#include "DBDesginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

 bool InitSystem(void);//���г�ʼ���������������̴洢�ļ��Ȳ���

// CDBDesginApp

BEGIN_MESSAGE_MAP(CDBDesginApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDBDesginApp ����

CDBDesginApp::CDBDesginApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDBDesginApp ����

CDBDesginApp theApp;


// CDBDesginApp ��ʼ��

BOOL CDBDesginApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CDBDesginDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}



bool InitSystem(void)
{
	FILE* fp;
	int id = 0;
	int userNum = 0;
	fp = fopen("DBIndex.dbf","rb");//DBIndex�洢�����Ϣ
	if(fp == NULL)
		fp = fopen("StorageFile.dbf","w");
	fclose(fp);
	
	fp = fopen("DBData.dat","rb");//DBData�������
	if(fp == NULL)
		fp = fopen("Data.dat","w");
	fclose(fp);


	//fp = fopen("Syslog.log","rb");//Syslog��¼ϵͳ��־
	//if(fp == NULL)
	//	fp = fopen("Syslog.log","w");
	//fclose(fp);



	//fp = fopen("userlist","rb");
	//if(fp == NULL)
	//{
	//	char str[100]; 
	//	strcpy(str,"userlist(id int pkey,name char(9),authority int,password char(9))");
	//	int	strNum = getString(ch,0,str);
	//	if(CreateTable(strNum) == true)
	//	{
	//		printf("��ʼ���û��б�ɹ�!\n");
	//		GetDlgItem(IDC_RESULT)->SetWindowText(s);
	//	}
	//	else
	//	{
	//		printf("��ʼ���û��б�����!\n");
	//		return false;
	//	}
	//
	//	strcpy(str,"userlist values(1,lutao,1,123)");
	//	strNum = getString(ch,0,str);
	//	if(InsertTable(strNum) == true)
	//		printf("�������Ա�ɹ�!\n");
	//	else
	//	{
	//		printf("�������Աʧ��!\n");
	//		return false;
	//	}
	//}

	return true;
}
