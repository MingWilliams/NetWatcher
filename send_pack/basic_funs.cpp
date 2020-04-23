#include "basic_funs.h"

int BasicSendPacket(pcap_t* ptAdapter, u_char lpPacket[], int nSize)
{

	return pcap_sendpacket(ptAdapter,lpPacket,nSize);
}
