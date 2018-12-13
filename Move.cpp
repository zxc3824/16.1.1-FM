#include "StdAfx.h"
#include "Move.h"
#include "Finder.h"


CMove::CMove(void)
{
}


CMove::~CMove(void)
{
}


void CMove::FileMove(CString m_oroot, CString m_mroot, CString m_name, CString m_extension, CString m_addfname)
{
	CFinder finder; // CFinder ����
	int fcount;

	fcount = finder.search(m_oroot, m_mroot, m_name, m_extension, m_addfname);

	if (fcount == -1) return; // ���� �˻� �� ���� �߻� �� �ߴ�(Finder.cpp)

	for (int i = 0; i < fcount; i++) {
		MoveFile(finder.ofList[i], finder.mfnList[i]); // ���� �̵�
	}

	CString text;
	text.Format("�̵��� ���� �� : %d��", fcount);
	MessageBoxA(NULL, text, "���� �̵�", NULL); // �̵��� ���� ���� ���
}
