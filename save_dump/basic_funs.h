#pragma once

#include "uni.h"

#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED

//�������ļ�������Ϊ�ļ����ַ���
EXPORT pcap_t* __stdcall OpenOffline(LPSTR lpFileName, char* errbuf);

//�������ļ�������ΪFILEָ��
EXPORT pcap_t* __stdcall OpenFileOffline(FILE* fp, char* errbuf);

//�ر��ļ�
EXPORT void __stdcall CloseFile(pcap_t * fp);
