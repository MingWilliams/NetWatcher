#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//��ʼ�����п⺯��
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

	//��ʼ���û���չ

	//��ʼץ��������

	//�����������UIģ��
}