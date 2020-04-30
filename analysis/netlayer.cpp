#include "netlayer.h"

IP4Hdr* AnalyzeIPv4(const u_char* data, int nProto)
{
	int i = 0;
	IP4Hdr* ip4 = (IP4Hdr*)malloc(sizeof(IP4Hdr));
	int nEth2Size = sizeof(Eth2Hdr);
	ip4->Version_Length = (u_short)(data + nEth2Size);
	ip4->DS_ECN = (u_short)(data + nEth2Size + 1);
	ip4->TotalLength = (u_short)(data + nEth2Size + 2);
	ip4->Identification = (u_short)(data + nEth2Size + 4);
	ip4->Fragment_Offsets = (u_short)(data + nEth2Size + 6);
	ip4->TimeToLive = (u_short)(data + nEth2Size + 8);
	ip4->ProtocolType = (u_short)(data + nEth2Size + 9);
	ip4->CheckSum = (u_short)(data + nEth2Size + 10);

	for (i = 0; i < 4; i++) {
		ip4->SourceIP[i] = (byte)(data + nEth2Size + 12 + i);
	}
	for (i = 0; i < 4; i++) {
		ip4->DestIP[i] = (byte)(data + nEth2Size + 16 + i);
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
