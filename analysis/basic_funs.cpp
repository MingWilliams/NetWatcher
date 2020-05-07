#include "basic_funs.h"

struct tm GetPacketLocalTime(const pcap_pkthdr* header)
{
	struct tm ltime;
	memset(&ltime, 0, sizeof(struct tm));
	time_t ltvsec = header->ts.tv_sec;
	localtime_s(&ltime, &ltvsec);
	return ltime;
}

u_int GetPacketSize(const pcap_pkthdr* header)
{
	return header->len;
}

u_short DoubleBytesConbination(byte b1, byte b2)
{
	u_short u = 0;
	u = u ^ b1;
	u = u << 8;
	u = u ^ b2;

	return u;
}

u_int QuadBytesCombination(byte b1, byte b2, byte b3, byte b4)
{
	u_int u = 0;
	u = u ^ (DoubleBytesConbination(b1,b2));
	u = u << 16;
	u = u ^ (DoubleBytesConbination(b3, b4));

	return u;
}
