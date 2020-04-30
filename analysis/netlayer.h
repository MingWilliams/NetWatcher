#pragma once

#include "uni.h"
#include "datlayer.h"

/*
byte=1
u_short=2
u_int=4
u_int64=8
u_long=4
*/

typedef struct IPv4Header
{
//不应该用比特，以后再处理
//	byte Vesion : 4;
//	byte HeaderLength : 4;  
	byte Version_Length;
//	byte DS : 6;
//	byte ECN : 2;
	byte DS_ECN;
	u_short TotalLength;
	u_short Identification;
//	byte ReservedBit : 1;
//	byte DontFragment : 1;
//	byte MoreFragments : 1;
//	byte FragmentOffset : 13;
	u_short Fragment_Offsets;
	byte TimeToLive;
	byte ProtocolType;
	u_short CheckSum;
	byte SourceIP[4];
	byte DestIP[4];
}IP4Hdr,* pIP4Hdr;

typedef struct IPv6Header
{
//不应该用比特
//	byte Version : 4;
//	byte DS : 6;
//	byte ECN : 2;
//	byte StreamTag : 20;
	u_int VerDETag;
	u_short TotalLength;
	u_short NextHeader;
	byte JumpLimit;
	byte SrcIP[16];
	byte DEstIP[16];

}IP6Hdr, * pIP6Hdr;

//需要手动释放内存
IP4Hdr* AnalyzeIPv4(_In_ const u_char* data, _Out_ int nProto);
