#pragma once
#include "uni.h"

//��ȡץ���ı���ʱ��
EXPORT struct tm GetPacketLocalTime(const struct pcap_pkthdr* header);

//��ȡ���Ĵ�С
EXPORT u_int GetPacketSize(const struct pcap_pkthdr* header);

//�����ֽ�Ϊu_short
EXPORT u_short DoubleBytesConbination(_In_ byte b1,_In_ byte b2);

//�����ֽ�Ϊu_int
EXPORT u_int QuadBytesCombination(_In_ byte b1, _In_ byte b2, _In_ byte b3, _In_ byte b4);