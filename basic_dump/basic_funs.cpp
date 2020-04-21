#include "basic_funs.h"


BOOL __stdcall TestPcapDlls()
{
	_TCHAR npcap_dir[512];
	UINT len;
	len = GetSystemDirectory(npcap_dir, 480);
	if (!len) {
		fprintf(stderr, "Error in GetSystemDirectory: %x", GetLastError());
		return FALSE;
	}
	_tcscat_s(npcap_dir, 512, _T("\\Npcap"));
	if (SetDllDirectory(npcap_dir) == 0) {
		fprintf(stderr, "Error in SetDllDirectory: %x", GetLastError());
		return FALSE;
	}
	
	return TRUE;
}

BOOL __stdcall GetDeviceList(pcap_rmtauth *auth, pcap_if_t *pitDeviceList,char lpErrBuf[])
{
	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, auth, &pitDeviceList, lpErrBuf)==-1) {
		SetLastError()

	}
	return 0;
}

BOOL __stdcall OpenAdapter()
{
	return 0;
}

BOOL __stdcall FreeAllDevs(pcap_if_t* pitDeviceList)
{
	return 0;
}

BOOL __stdcall RetrivePacket()
{
	return 0;
}
