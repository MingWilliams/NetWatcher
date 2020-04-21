//提供基于pcap函数的基本功能
#pragma once

#include "uni.h"

//检查Npcap是否可用
BOOL __stdcall TestPcapDlls();

//获取设备列表
BOOL __stdcall GetDeviceList(_In_ pcap_rmtauth *auth,_Out_ pcap_if_t *pitDeviceList,_Out_ char lpErrbuf[]);

//打开适配器
BOOL __stdcall OpenAdapter();

//释放设备列表
BOOL __stdcall FreeAllDevs(_In_ pcap_if_t *pitDeviceList);

//获取数据包
BOOL __stdcall RetrivePacket();


