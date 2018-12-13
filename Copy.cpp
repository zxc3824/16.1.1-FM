#include "StdAfx.h"
#include "Copy.h"
#include "Finder.h"


CCopy::CCopy(void)
{
}


CCopy::~CCopy(void)
{
}


void CCopy::FileCopy(CString m_oroot, CString m_mroot, CString m_name, CString m_extension, CString m_addfname)
{
	CFinder finder; // CFinder ����
	int fcount;
	
	CStringArray a;
	a.Copy(finder.ofList);
	fcount = finder.search(m_oroot, m_mroot, m_name, m_extension, m_addfname);

	if (fcount == -1) return; // ���� �˻� �� ���� �߻� �� �ߴ�(Finder.cpp)

	for (int i = 0; i < fcount; i++) {
		CopyFile((LPCSTR)&finder.ofList[i], (LPCSTR)&finder.mfnList[i], true); // ���� ����(������ ��ĥ�� ������ ���� �߱� ������ true, false ���� ����)
	}

	CString text;
	text.Format(_T("������ ���� �� : %d��"), fcount);
	MessageBoxA(NULL, text, "���� ����", NULL); // ������ ���� ���� ���
}