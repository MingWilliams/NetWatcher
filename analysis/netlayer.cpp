#include "netlayer.h"

IP4Hdr* AnalyzeIPv4(const u_char* data, int nProto)
{
	int i = 0;
	IP4Hdr* ip4 = (IP4Hdr*)malloc(sizeof(IP4Hdr));
	int nEth2Size = sizeof(Eth2Hdr);
	ip4->Version_Length = (byte)*(data + nEth2Size);
	ip4->DS_ECN = (byte)*(data + nEth2Size + 1);
	ip4->TotalLength = DoubleBytesConbination(*(data + nEth2Size + 2),
		*(data + nEth2Size + 3));
	ip4->Identification = DoubleBytesConbination(*(data + nEth2Size + 4),
		*(data + nEth2Size + 5));
	ip4->Fragment_Offsets = DoubleBytesConbination(*(data + nEth2Size + 6),
		*(data + nEth2Size + 7));
	ip4->TimeToLive = (byte)*(data + nEth2Size + 8);
	ip4->ProtocolType = (byte)*(data + nEth2Size + 9);
	ip4->CheckSum = DoubleBytesConbination(*(data + nEth2Size + 10),
		*(data + nEth2Size + 11));

	for (i = 0; i < 4; i++) {
		ip4->SourceIP[i] = (byte)*(data + nEth2Size + 12 + i);
	}
	for (i = 0; i < 4; i++) {
		ip4->DestIP[i] = (byte)*(data + nEth2Size + 16 + i);
	}

	if (ip4->ProtocolType == netTCP) {
		nProto = PROTO_TCP;
	}
	else if (ip4->ProtocolType == netUDP) {
		nProto = PROTO_UDP;
	}
	else if (ip4->ProtocolType == netICMP) {
		nProto = PROTO_ICMP;
	}
	else {
		nProto = PROTO_UNKNOWN;
	}

	return ip4;
}

IP6Hdr* AnalyzeIPv6(const u_char* data, int nProto)
{


	return NULL;
}
