#pragma once
#include "afx.h"
class CFinder :
	public CObject
{
private:
	int fileCnt1, fileCnt2;

public:
	CStringArray ofList, mfnList, mfList; // 원래 파일 이름, 이동/복사될 파일 이름, 이동위치 파일 이름 리스트
	CFinder();
	~CFinder();
	int search(CString,CString,CString,CString,CString);
};

