#pragma once
#include "afx.h"
class CMove :
	public CObject
{
public:
	CMove(void);
	~CMove(void);
	void FileMove(CString, CString, CString, CString, CString);
};

