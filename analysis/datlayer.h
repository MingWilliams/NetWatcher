#pragma once

#include "uni.h"
#include "basic_funs.h"



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

//需要手动释放内存
EXPORT Eth2Hdr * AnalyzeProtoEth(_In_ const u_char* data,_Out_ int nProto,_Out_ int nThisProto);

//需要手动释放内存
EXPORT ARPHdr4 * AnalyzeProtoARP4(_In_ const u_char* data,_In_ int nThisProto);

