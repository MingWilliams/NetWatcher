#pragma once
#include "uni.h"

//链路层
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

//网络层
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
}IP4Hdr, * pIP4Hdr;

typedef struct IPv6Header
{
	//不应该用比特
	//	byte Version : 4;
	//	byte DS : 6;
	//	byte ECN : 2;
	//	byte StreamTag : 20;
	u_int VerDETag;
	u_short TotalLength;
	byte NextHeader;
	byte JumpLimit;
	byte SrcIP[16];
	byte DEstIP[16];

}IP6Hdr, * pIP6Hdr;

//传输层
typedef struct TCPHeader
{
	u_short SrcPort;
	u_short DestPort;
	u_long SequenceNumber;
	u_long AckNumber;
	/*
		byte HeaderLength : 4;
		byte DataShift : 4;
		byte Reserved : 3;
		byte Nonce : 1;
		byte CWR : 1;
		byte ECNEcho : 1;
		byte Urgent : 1;
		byte Acknowledgement : 1;
		byte Push : 1;
		byte Push : 1;
		byte Reset : 1;
		byte Syn : 1;
		byte Fin : 1;
	*/
	u_short Flags;
	u_short WindowSize;
	u_short CheckSum;
	u_short Urgent;

}TCPHdr, * pTCPHdr;

typedef struct UDPHeader
{
	u_short SrcPort;
	u_short DestPort;
	u_short Length;
	u_short CheckSum;

}UDPHdr, * pUDPHdr;

typedef struct ICMPHeader
{
	byte Type;
	byte Code;
	u_short CheckSum;
	u_short Identifier;
	u_short SquenceNumber;

}ICMPHdr, * pICMPHdr;

typedef struct IGMPv2Header
{
	byte Type;
	byte MaxResponseTime;
	u_short CheckSum;
	byte MultiCastAddr[4];

}IGMP2Hdr, * pIGMP2Hdr;

//应用层
typedef struct DNSHeaderQuery
{
	u_short TransactionID;
	u_short Flag;
	u_short Questions;
	u_short AnswerRRs;
	u_short AuthorityRRs;
	u_short AdditionalRRs;
}DNSHdrQ, * pDNSHdrQ;

typedef struct DNSHeaderResponse
{
	u_short TransactionID;
	u_short Flag;
	u_short Questions;
	u_short AnswerRRs;
	u_short AuthorityRRs;
	u_short AdditionalRRs;
}DNSHdrR, * pDNSHdrR;
