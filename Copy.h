#pragma once
#include "afx.h"
class CCopy :
	public CObject
{
public:
	CCopy(void);
	~CCopy(void);
	void FileCopy(CString, CString, CString, CString, CString);
};

