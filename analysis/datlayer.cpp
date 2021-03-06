#include "datlayer.h"



Eth2Hdr * AnalyzeProtoEth(const u_char* data, int nProto,int nThisProto)
{
	Eth2Hdr* hdr = (Eth2Hdr*)malloc(sizeof(Eth2Hdr));
	
	int nMacSize = sizeof(hdr->destMAC);
	int i = 0;
	for (i = 0; i < nMacSize; i++) {
		hdr->destMAC[i] = (byte)*(data + i);
	}
	for (i = 0; i < nMacSize; i++) {
		hdr->srcMAC[i] = (byte)*(data + i + nMacSize);
	}
	
	hdr->ProtocolType = DoubleBytesConbination(*(data + nMacSize + nMacSize),
		*(data + nMacSize + nMacSize + 1));
	if (hdr->ProtocolType == datARPv4) {
		nProto = PROTO_ARPv4;
		nThisProto = PROTO_ETH2;
		return hdr;
	}
	else {
		nProto = PROTO_UNKNOWN;
		nThisProto = PROTO_UNKNOWN;
		return NULL;
	}
	
}

ARPHdr4 * AnalyzeProtoARP4(const u_char* data,int nThisProto)
{
	if (nThisProto == PROTO_ETH2) {
		int i = 0;
		int nSizeEth2 = sizeof(Eth2Hdr);
		ARPHdr4* hdr = (ARPHdr4*)malloc(sizeof(ARPHdr4));
		hdr->HardwareType = DoubleBytesConbination(*(data + nSizeEth2),
			*(data + nSizeEth2) + 1);
		hdr->ProtocolType = DoubleBytesConbination(*(data + nSizeEth2 + 2),
			*(data + nSizeEth2 + 3));
		hdr->HardwareSize = (byte)*(data + nSizeEth2 + 4);
		hdr->ProtocolSize = (byte)*(data + nSizeEth2 + 5);
		hdr->Opcode = DoubleBytesConbination(*(data + nSizeEth2 + 6),
			*(data + nSizeEth2 + 7));
		for (i = 0; i < 6; i++) {
			hdr->SenderMAC[i] = (byte)*(data + nSizeEth2 + 8 + i);
		}
		for (i = 0; i < 4; i++) {
			hdr->SenderIP[i] = (byte)*(data + nSizeEth2 + 14 + i);
		}
		for (i = 0; i < 6; i++) {
			hdr->SenderMAC[i] = (byte)*(data + nSizeEth2 + 18 + i);
		}
		for (i = 0; i < 4; i++) {
			hdr->SenderIP[i] = (byte)*(data + nSizeEth2 + 24 + i);
		}

		return hdr;
	}
	else
	{
		return NULL;
	}
	
}
