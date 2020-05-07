#pragma once

#include "uni.h"
#include "netlayer.h"


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
	
}TCPHdr,* pTCPHdr;

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
//需要手动释放内存
EXPORT TCPHdr* AnalyzeTCP(_In_ const u_char* data, _In_ int nPrevProto, _Out_ int nProto);
//需要手动释放内存
EXPORT UDPHdr* AnalyzeUDP(_In_ const u_char* data, _In_ int nPrevProto, _Out_ int nProto);
//需要手动释放内存
EXPORT ICMPHdr* AnalyzeICMP(_In_ const u_char* data,_In_ int nPrevProto, _Out_ int nProto);
