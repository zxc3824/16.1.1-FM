
// FileManager.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFileManagerApp:
// �� Ŭ������ ������ ���ؼ��� FileManager.cpp�� �����Ͻʽÿ�.
//

class CFileManagerApp : public CWinApp
{
public:
	CFileManagerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFileManagerApp theApp;