#pragma once

#include "uni.h"




typedef struct EthernetIIHeader
{
	byte destMAC[6];
	byte srcMAC[6];
	u_short ProtocolType;

}Eth2Hdr, * pEth2Hdr;

typedef struct ARPHeaderIPv4
{
	u_short HardwareType;
	u_short ProtocolType;
	byte HardwareSize;
	byte ProtocolSize;
	u_short Opcode;
	byte SenderMAC[6];
	byte SenderIP[4];
	byte TargetMAC[6];
	byte TargetIP[4];

}ARPHdr4, * pARPHdr4;

//��Ҫ�ֶ��ͷ��ڴ�
Eth2Hdr * AnalyzeProtoEth(_In_ const u_char* data,_Out_ int nProto,_Out_ int nThisProto);

//��Ҫ�ֶ��ͷ��ڴ�
ARPHdr4 * AnalyzeProtoARP4(_In_ const u_char* data,_In_ int nThisProto);