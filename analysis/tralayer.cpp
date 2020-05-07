#include "tralayer.h"

TCPHdr* AnalyzeTCP(const u_char* data, int nPrevProto, int nProto)
{
	if (nPrevProto == PROTO_IPv4) {

		TCPHdr* h = (TCPHdr*)malloc(sizeof(TCPHdr));
		const u_char * temp = data + sizeof(IP4Hdr) + sizeof(Eth2Hdr);
		h->SrcPort = DoubleBytesConbination(*(temp), *(temp + 1));
		h->DestPort = DoubleBytesConbination(*(temp + 2),*(temp + 3));
		h->SequenceNumber = QuadBytesCombination(*(temp + 4),
			* (temp + 5),
			* (temp + 6),
			* (temp + 7));
		h->AckNumber= QuadBytesCombination(*(temp + 8),
			*(temp + 9),
			*(temp + 10),
			*(temp + 11));
		h->Flags = DoubleBytesConbination(*(temp + 12),
			*(temp + 13));
		h->WindowSize = DoubleBytesConbination(*(temp + 14),
			*(temp + 15));
		h->CheckSum = DoubleBytesConbination(*(temp + 16),
			*(temp + 17));
		h->Urgent = DoubleBytesConbination(*(temp + 18),
			*(temp + 19));
		nProto = PROTO_TCP;
		return h;
	}
	else if (nPrevProto == PROTO_IPv6) {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}
	else {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}

}

UDPHdr* AnalyzeUDP(const u_char* data, int nPrevProto, int nProto)
{
	if (nPrevProto == PROTO_IPv4) {
		UDPHdr* hdr = (UDPHdr*)malloc(sizeof(UDPHdr));
		const u_char* temp = data + sizeof(IP4Hdr) + sizeof(Eth2Hdr);
		hdr->SrcPort = DoubleBytesConbination(*(temp), *(temp + 1));
		hdr->DestPort = DoubleBytesConbination(*(temp + 2), *(temp + 3));
		hdr->Length = DoubleBytesConbination(*(temp + 4), *(temp + 5));
		hdr->CheckSum = DoubleBytesConbination(*(temp + 6), *(temp + 7));

		nProto = PROTO_UDP;
		return hdr;
	}
	else if (nPrevProto == PROTO_IPv6) {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}
	else {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}

}

ICMPHdr* AnalyzeICMP(const u_char* data, int nPrevProto, int nProto)
{
	if (nPrevProto == PROTO_IPv4) {
		ICMPHdr* hdr = (ICMPHdr*)malloc(sizeof(ICMPHdr));
		const u_char* temp = data + sizeof(IP4Hdr) + sizeof(Eth2Hdr);
		hdr->Type = (byte)*(temp);
		hdr->Code = (byte)*(temp + 1);
		hdr->CheckSum = DoubleBytesConbination(*(temp + 2), *(temp + 3));
		hdr->Identifier = DoubleBytesConbination(*(temp + 4), *(temp + 5));
		hdr->SquenceNumber = DoubleBytesConbination(*(temp + 6), *(temp + 7));
		if (hdr->Type == icmpReq) {
			nProto = PROTO_ICMPREQ;
		}
		else if (hdr->Type == icmpRes) {
			nProto = PROTO_ICMPRES;
		}
		return hdr;
	}
	else if (nPrevProto == PROTO_IPv6) {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}
	else
	{
		nProto = PROTO_UNKNOWN;
		return NULL;
	}
	
}

