#include "StdAfx.h"
#include "Finder.h"


CFinder::CFinder(void)
{
}


CFinder::~CFinder(void)
{
}

int CFinder::search(CString oRoot, CString mRoot, CString Name, CString Extension, CString Addfname) {
	CFileFind find; // CFileFind ����
	CString fname; // ���� �̸�
	CString pname; // ��� �̸�
	CString path1; // �˻��� ���� ��� �� �̸�
	int res1 = 1; // ���� �˻���
	fileCnt1 = 0; // ���� ����

	if (oRoot == "" || mRoot == "") { // ���� ��ΰ� ���� �� �ߴ�
		MessageBoxA(NULL, "������ �˻��� ��ο� �̵��� ��θ� �ݵ�� �����ؾ� �մϴ�.", "���� �˻�", NULL);
		return -1;
	}
	if (Name == "" && Extension == "") { // �̸��� Ȯ���� ��� ���� �� �ߴ�
		MessageBoxA(NULL, "���� �̸��̳� Ȯ���� �� �ϳ��� �ݵ�� ����� �մϴ�.", "���� �˻�", NULL);
		return -1;
	}

	path1.Format("%s\\*%s*.*%s*", oRoot, Name, Extension); // �˻��� ���� �̸�

	res1 = find.FindFile(path1); // ���� �˻�(0 �Ǵ� 1)

	if (res1 == 0) { // �˻��� ������ ���� ��� �ߴ�
		MessageBoxA(NULL, "���� ���ϸ��Դϴ�.", "���� �˻�", NULL);
		return -1;
	}

	while (res1){
		res1 = find.FindNextFileA(); // ���� ���� �˻�
		fname = find.GetFileName(); // "���� �̸�.Ȯ����" ����
		if (fname.MakeUpper().Find(Name.MakeUpper()) == -1) continue; // �˻�� �ܹ��ڷ� �Է½� �߻��ϴ� ���� ����(���� �̸� ��)
		fname = find.GetFileName();
		pname = find.GetFilePath(); // "���� ���\���� �̸�.Ȯ����" ����
		ofList.Add(pname); // ofList �迭(Finder.h)�� pname �߰�
		mfnList.Add(mRoot + '\\' + Addfname + fname); // mfList(Finder.h) �迭�� �̵��� ���� ��� �߰�
		if (res1) {
			if (find.IsDirectory()) { // ���� �Ǵ� �� ������ ������ ��� while ó������
				if (fname == "." || fname == "..") continue;
			}
			else {
				fileCnt1++; // ���� ���� �߰�
			}
		}
	}

	/* �̵� �Ǵ� ������ ������ ���� �˻�(���� �ߺ� ������) */
	CString path2;
	int res2 = 1;
	fileCnt2 = 0;
	
	path2.Format("%s\\*%s*.*%s*", mRoot, Name, Extension);

	res2 = find.FindFile(path2);

	while (res2) {
		res2 = find.FindNextFileA();
		fname = find.GetFileName();
		if (fname.MakeUpper().Find(Name.MakeUpper()) == -1) continue;
		fname = find.GetFileName();
		pname = find.GetFilePath();
		mfList.Add(pname);
		if (res2) {
			if (find.IsDirectory()) {
				if (fname == "." || fname == "..") continue;
			}
			else {
				fileCnt2++;
			}
		}
	}

	for (int i = 0; i < fileCnt1; i++) {
		if (fileCnt2 == 0) break; // ������ ��ο� �˻��� ������ ������ ��������
		for (int j = 0; j < fileCnt2; j++) {
			if (mfnList[i] == mfList[j]) { // ���� ���ϰ� ������ ��ġ�� �ִ� ������ ���� ��� �ߴ�
				MessageBoxA(NULL, "���� �̸��� ������ �ֽ��ϴ�.", "���� ����", NULL);
				return -1;
			}
		}
	}

	return fileCnt1;
}