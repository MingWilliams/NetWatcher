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
