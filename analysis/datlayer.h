#pragma once

#include "uni.h"


typedef struct EthernetIIHeader
{
	byte destMAC[6];
	byte srcMAC[6];
	u_short ProtocolType;

}EthHdr, * pEthHdr;

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



