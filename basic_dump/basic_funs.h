//�ṩ����pcap�����Ļ�������
#pragma once

#include "uni.h"


#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED


//���Npcap�Ƿ����
EXPORT BOOL __stdcall TestPcapDlls();

//��ȡ�豸�б�
EXPORT BOOL __stdcall GetDeviceList(_In_ pcap_rmtauth *auth,_Out_ pcap_if_t *pitDeviceList,_Out_ char lpErrbuf[]);

//��������
EXPORT BOOL __stdcall OpenAdapterLive(_In_ pcap_if_t* pitDevice, int nFlag, int nTimeOut, char lpErrBuf[],_Out_ pcap_t *ptAdHandle);

//�ͷ��豸�б�
EXPORT BOOL __stdcall FreeAllDevs(_In_ pcap_if_t *pitDeviceList);

//��ȡ���ݰ�
EXPORT int __stdcall RetrivePacket(_In_ pcap_t* ptAdhandle, _Out_ struct pcap_pkthdr* Header, _Out_ const u_char *pktData);

//����Ƿ�Ϊ��·��
EXPORT BOOL __stdcall CheckDataLink(_In_ pcap_t* ptAdHandle);

//�رմ򿪵�������
EXPORT BOOL __stdcall CloseAdapter(_In_ pcap_t* ptAdHandle);