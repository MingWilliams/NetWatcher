#include "main.h"


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

	//开始抓包并分析

	//将结果发送至UI模块
}