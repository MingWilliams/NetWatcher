//�ṩ����pcap�����Ļ�������
#pragma once

#include "uni.h"


#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED


//��Dump�ļ�
EXPORT pcap_dumper_t * __stdcall OpenDumpFile(pcap_t* ptAdHandle, LPSTR lpFilePath);


//��Dump�ļ�д����
EXPORT void __stdcall WriteDump(pcap_dumper_t* pdtDumpFile, const struct pcap_pkthdr* Header, const u_char* pktData);


//ˢ����
EXPORT BOOL __stdcall FlushDump(pcap_dumper_t* pdtDumpFile);



//�ر�Dump�ļ�
EXPORT void __stdcall CloseDump(pcap_dumper_t* pdtDumpFile);
