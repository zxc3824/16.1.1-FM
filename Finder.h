#pragma once
#include "afx.h"
class CFinder :
	public CObject
{
private:
	int fileCnt1, fileCnt2;

public:
	CStringArray ofList, mfnList, mfList; // ���� ���� �̸�, �̵�/����� ���� �̸�, �̵���ġ ���� �̸� ����Ʈ
	CFinder();
	~CFinder();
	int search(CString,CString,CString,CString,CString);
};

