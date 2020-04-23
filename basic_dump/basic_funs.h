//提供基于pcap函数的基本功能
#pragma once

#include "uni.h"


#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED


//检查Npcap是否可用
EXPORT BOOL __stdcall TestPcapDlls();

//获取设备列表
EXPORT BOOL __stdcall GetDeviceList(_In_ pcap_rmtauth *auth,_Out_ pcap_if_t *pitDeviceList,_Out_ char lpErrbuf[]);

//打开适配器
EXPORT BOOL __stdcall OpenAdapterLive(_In_ pcap_if_t* pitDevice, int nFlag, int nTimeOut, char lpErrBuf[],_Out_ pcap_t *ptAdHandle);

//释放设备列表
EXPORT BOOL __stdcall FreeAllDevs(_In_ pcap_if_t *pitDeviceList);

//获取数据包
EXPORT int __stdcall RetrivePacket(_In_ pcap_t* ptAdhandle, _Out_ struct pcap_pkthdr* Header, _Out_ const u_char *pktData);

//检查是否为链路层
EXPORT BOOL __stdcall CheckDataLink(_In_ pcap_t* ptAdHandle);

//关闭打开的适配器
EXPORT BOOL __stdcall CloseAdapter(_In_ pcap_t* ptAdHandle);