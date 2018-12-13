#include "StdAfx.h"
#include "Finder.h"


CFinder::CFinder(void)
{
}


CFinder::~CFinder(void)
{
}

int CFinder::search(CString oRoot, CString mRoot, CString Name, CString Extension, CString Addfname) {
	CFileFind find; // CFileFind 선언
	CString fname; // 파일 이름
	CString pname; // 경로 이름
	CString path1; // 검색할 파일 경로 및 이름
	int res1 = 1; // 파일 검색용
	fileCnt1 = 0; // 파일 갯수

	if (oRoot == "" || mRoot == "") { // 폴더 경로가 없을 시 중단
		MessageBoxA(NULL, "파일을 검색할 경로와 이동할 경로를 반드시 선택해야 합니다.", "파일 검색", NULL);
		return -1;
	}
	if (Name == "" && Extension == "") { // 이름과 확장자 모두 없을 시 중단
		MessageBoxA(NULL, "파일 이름이나 확장자 중 하나를 반드시 적어야 합니다.", "파일 검색", NULL);
		return -1;
	}

	path1.Format("%s\\*%s*.*%s*", oRoot, Name, Extension); // 검색할 파일 이름

	res1 = find.FindFile(path1); // 파일 검색(0 또는 1)

	if (res1 == 0) { // 검색된 파일이 없을 경우 중단
		MessageBoxA(NULL, "없는 파일명입니다.", "파일 검색", NULL);
		return -1;
	}

	while (res1){
		res1 = find.FindNextFileA(); // 다음 파일 검색
		fname = find.GetFileName(); // "파일 이름.확장자" 대입
		if (fname.MakeUpper().Find(Name.MakeUpper()) == -1) continue; // 검색어를 단문자로 입력시 발생하는 문제 예방(파일 이름 비교)
		fname = find.GetFileName();
		pname = find.GetFilePath(); // "파일 경로\파일 이름.확장자" 대입
		ofList.Add(pname); // ofList 배열(Finder.h)에 pname 추가
		mfnList.Add(mRoot + '\\' + Addfname + fname); // mfList(Finder.h) 배열에 이동될 파일 경로 추가
		if (res1) {
			if (find.IsDirectory()) { // 상위 또는 그 상위의 폴더일 경우 while 처음으로
				if (fname == "." || fname == "..") continue;
			}
			else {
				fileCnt1++; // 파일 갯수 추가
			}
		}
	}

	/* 이동 또는 복사할 폴더의 파일 검색(파일 중복 방지용) */
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
		if (fileCnt2 == 0) break; // 복사할 경로에 검색된 파일이 없을시 빠져나옴
		for (int j = 0; j < fileCnt2; j++) {
			if (mfnList[i] == mfList[j]) { // 기존 파일과 복사할 위치에 있는 파일이 같은 경우 중단
				MessageBoxA(NULL, "같은 이름의 파일이 있습니다.", "파일 복사", NULL);
				return -1;
			}
		}
	}

	return fileCnt1;
}