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
	CFinder finder; // CFinder 선언
	int fcount;
	
	CStringArray a;
	a.Copy(finder.ofList);
	fcount = finder.search(m_oroot, m_mroot, m_name, m_extension, m_addfname);

	if (fcount == -1) return; // 파일 검색 후 에러 발생 시 중단(Finder.cpp)

	for (int i = 0; i < fcount; i++) {
		CopyFile((LPCSTR)&finder.ofList[i], (LPCSTR)&finder.mfnList[i], true); // 파일 복사(파일이 겹칠시 에러가 나게 했기 때문에 true, false 관계 없음)
	}

	CString text;
	text.Format(_T("복사한 파일 수 : %d개"), fcount);
	MessageBoxA(NULL, text, "파일 복사", NULL); // 복사한 파일 갯수 출력
}