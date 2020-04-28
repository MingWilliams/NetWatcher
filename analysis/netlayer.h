#pragma once

#include "uni.h"


typedef struct IPv4Header
{
	byte Vesion : 4;
	byte HeaderLength : 4;
	byte DS : 6;
	byte ECN : 2;
	u_short TotalLength;
	u_short Identification;
	byte ReservedBit : 1;
	byte DontFragment : 1;
	byte MoreFragments : 1;
	byte FragmentOffset : 13;
	byte TimeToLive;
	byte ProtocolType;
	u_short CheckSum;
	byte SourceIP[4];
	byte DestIP[4];
}IP4Hdr,* pIP4Hdr;

typedef struct IPv6Header
{
	byte Version : 4;
	byte DS : 6;
	byte ECN : 2;
	byte StreamTag : 20;
	u_short TotalLength;
	u_short NextHeader;
	byte JumpLimit;
	byte SrcIP[16];
	byte DEstIP[16];

}IP6Hdr, * pIP6Hdr;