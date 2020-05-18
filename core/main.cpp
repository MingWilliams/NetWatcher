#include "main.h"

/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//初始化所有库函数
	AL* a = LoadAllLibs();
	if (a == NULL) {
		MessageBox(NULL, L"ERROR Loading Dlls!", L"ERROR", MB_ICONERROR);
		return 1;
	}
	
	Ana* ana = GetAnalysisProc(a->analysis);
	BC* bc = GetBasicCapProc(a->basic_cap);
	GP* gp = GetGetProcProc(a->get_proc);
	RD* rd = GetReadDumpProc(a->read_dump);
	SP* sp = GetSendPackProc(a->send_pack);
	WF* wf = GetWriteFileProc(a->write_file);

	//初始化用户扩展

	//初始化UI模块
	LPWSTR lpUI = (LPWSTR)L"UI.exe";	
	PROCESS_INFORMATION pi ;
	STARTUPINFO si = { sizeof(si) };
	CreateProcess(lpUI, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &si, &pi);
	int n = GetLastError();
	if(n!=0){
		LPWSTR lpE = new wchar_t[MAX_PATH];
		wsprintf(lpE, L"Error is %d", n);
		MessageBox(NULL, lpE, L"INFO", MB_OK);

	}

	//开始抓包并分析

	//将结果发送至UI模块


	return 0;
}
*/