#include "basic_funs.h"

/*
#pragma comment(linker,"/EXPORT:_TestPcapDlls=TestPcapDlls,@1")
#pragma comment(linker,"/EXPORT:_GetDeviceList=GetDeviceList,@2")
#pragma comment(linker,"/EXPORT:_OpenAdapterLive=OpenAdapterLive,@3")
#pragma comment(linker,"/EXPORT:_FreeAllDevs=FreeAllDevs,@4")
#pragma comment(linker,"/EXPORT:_RetrivePacket=RetrivePacket,@5")
#pragma comment(linker,"/EXPORT:_CheckDataLink=CheckDataLink,@6")
#pragma comment(linker,"/EXPORT:_CloseAdapter=CloseAdapter,@7")
*/



BOOL TestPcapDlls()
{
	_TCHAR npcap_dir[512];
	UINT len;
	len = GetSystemDirectory(npcap_dir, 480);
	if (!len) {
		MessageBox(NULL, TEXT("����"), TEXT("�޷���ȡϵͳ·��"), MB_ICONERROR);
		return FALSE;
	}
	_tcscat_s(npcap_dir, 512, _T("\\Npcap"));
	if (SetDllDirectory(npcap_dir) == 0) {
		MessageBox(NULL, TEXT("����"), TEXT("�޷�����DLL·��"), MB_ICONERROR);
		return FALSE;
	}
	
	return TRUE;
}

BOOL  GetDeviceList(pcap_rmtauth *auth, pcap_if_t *pitDeviceList,char lpErrBuf[])
{
	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, auth, &pitDeviceList, lpErrBuf)==-1) {
		MessageBox(NULL, TEXT("����"), TEXT("�޷���ȡ�豸��Ϣ"), MB_ICONERROR);
		return FALSE;
	}
	return TRUE;
}

BOOL  OpenAdapterLive(pcap_if_t* pitDevice, int nFlag, int nTimeOut, char lpErrBuf[], pcap_t *ptAdHandle)
{
	pcap_t* adhandle;
	if ((adhandle = pcap_open_live(pitDevice->name, 65536, nFlag, nTimeOut, lpErrBuf)) == NULL) {
		MessageBox(NULL, TEXT("����"), TEXT("�޷���Live�豸���豸���ܲ�֧��Npcap"), MB_ICONERROR);
		return FALSE;
	}
	ptAdHandle = adhandle;

	return TRUE;
}

BOOL  FreeAllDevs(pcap_if_t* pitDeviceList)
{
	pcap_freealldevs(pitDeviceList);
	return TRUE;
}

BOOL  CheckDataLink(pcap_t* ptAdHandle)
{
	if (pcap_datalink_ext(ptAdHandle) != DLT_EN10MB)
	{
		MessageBox(NULL, TEXT("����"), TEXT("��֧����·��"), MB_ICONERROR);
		return FALSE;
	}

	return TRUE;
}

BOOL  CloseAdapter(pcap_t* ptAdHandle)
{
	pcap_close(ptAdHandle);
	return TRUE;
}

int RetrivePacket(pcap_t *ptAdHandle,struct pcap_pkthdr *Header,const u_char *pktData)
{
	int res = pcap_next_ex(ptAdHandle, &Header, &pktData);
	return res;
}

