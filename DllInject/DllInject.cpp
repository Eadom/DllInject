// DllInject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "InjectDLL.h"
#include <stdlib.h>

const DWORD dwRemoteProcessID = 6304;
const std::wstring wstrRemoteDllFullPath = _T("F:\\ѧϰ\\C++\\My projects\\DllInject\\Release\\InjectDLL.dll");
const std::wstring wstrRemoteProcName = _T("notepad++.exe");
const std::wstring wstrRemoteDllName = _T("InjectDLL.dll");

int _tmain(int argc, _TCHAR* argv[])
{
	CInjectDLL InjectDll;
	//InjectDll.Inject(dwRemoteProcessID, wstrRemoteDllFullPath.c_str());
	//InjectDll.Inject((wchar_t*)wstrRemoteProcName.c_str(), wstrRemoteDllFullPath.c_str());
	printf_s("Injecting...\n");
	if (InjectDll.Inject((wchar_t*)wstrRemoteProcName.c_str(), wstrRemoteDllFullPath.c_str()))
	{
		printf_s("Success...\n");
		Sleep(5000);
		printf_s("Uninjecting...\n");
		InjectDll.Uninject((wchar_t*)wstrRemoteProcName.c_str(), wstrRemoteDllFullPath.c_str());
	}
	else
	{
		printf_s("Failed...error code:%d\n",::GetLastError());
	}
}

