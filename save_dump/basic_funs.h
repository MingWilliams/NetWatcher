#pragma once

#include "uni.h"

#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED

//打开离线文件，传参为文件名字符串
EXPORT pcap_t* __stdcall OpenOffline(LPSTR lpFileName, char* errbuf);

//打开离线文件，传参为FILE指针
EXPORT pcap_t* __stdcall OpenFileOffline(FILE* fp, char* errbuf);

//关闭文件
EXPORT void __stdcall CloseFile(pcap_t * fp);
