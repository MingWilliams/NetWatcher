#pragma once
#include "uni.h"

//获取抓包的本地时间
EXPORT struct tm GetPacketLocalTime(const struct pcap_pkthdr* header);

//获取包的大小
EXPORT u_int GetPacketSize(const struct pcap_pkthdr* header);

//连接字节为u_short
EXPORT u_short DoubleBytesConbination(_In_ byte b1,_In_ byte b2);

//连接字节为u_int
EXPORT u_int QuadBytesCombination(_In_ byte b1, _In_ byte b2, _In_ byte b3, _In_ byte b4);