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
	CFinder finder; // CFinder 선언
	int fcount;

	fcount = finder.search(m_oroot, m_mroot, m_name, m_extension, m_addfname);

	if (fcount == -1) return; // 파일 검색 후 에러 발생 시 중단(Finder.cpp)

	for (int i = 0; i < fcount; i++) {
		MoveFile(finder.ofList[i], finder.mfnList[i]); // 파일 이동
	}

	CString text;
	text.Format("이동한 파일 수 : %d개", fcount);
	MessageBoxA(NULL, text, "파일 이동", NULL); // 이동한 파일 갯수 출력
}
