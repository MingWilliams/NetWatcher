//�ṩ����pcap�����Ļ�������
#pragma once

#include "uni.h"

//���Npcap�Ƿ����
BOOL __stdcall TestPcapDlls();

//��ȡ�豸�б�
BOOL __stdcall GetDeviceList(_In_ pcap_rmtauth *auth,_Out_ pcap_if_t *pitDeviceList,_Out_ char lpErrbuf[]);

//��������
BOOL __stdcall OpenAdapter();

//�ͷ��豸�б�
BOOL __stdcall FreeAllDevs(_In_ pcap_if_t *pitDeviceList);

//��ȡ���ݰ�
BOOL __stdcall RetrivePacket();


