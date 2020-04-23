//提供基于pcap函数的基本功能
#pragma once

#include "uni.h"


#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED


//打开Dump文件
EXPORT pcap_dumper_t * __stdcall OpenDumpFile(pcap_t* ptAdHandle, LPSTR lpFilePath);


//向Dump文件写数据
EXPORT void __stdcall WriteDump(pcap_dumper_t* pdtDumpFile, const struct pcap_pkthdr* Header, const u_char* pktData);


//刷新流
EXPORT BOOL __stdcall FlushDump(pcap_dumper_t* pdtDumpFile);



//关闭Dump文件
EXPORT void __stdcall CloseDump(pcap_dumper_t* pdtDumpFile);
