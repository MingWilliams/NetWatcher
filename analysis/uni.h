#pragma once

#include <WinSock2.h>
#include <pcap.h>
#include <windows.h>
#include <tchar.h>
#include <time.h>

//��·��ͷ����װ����
#define    datIPv4         0x0800
#define    datARPv4        0x0806
#define    ARPv4Req        0x0001
#define    ARPv4Res        0x0002

//�����ͷ����װ����
#define    netIPv4         0x4
#define    netIPv6         0x6
#define    netICMP         0x01   
#define    netIGMP         0x02   
#define    netTCP          0x06   
#define    netUDP          0x11   
#define    netIGRP         0x58   
#define    netOSPF         0x59   


//�����ͷ����װ����
#define    icmpRes         0x0
#define    icmpReq         0x08


//�������
#define    PROTO_UNKNOWN   -1

#define    PROTO_ETH2      2
#define    PROTO_ARPv4     3
#define    PROTO_IPv4      4
#define    PROTO_IPv6      5
#define    PROTO_ICMP      6
#define    PROTO_IGMP      7
#define    PROTO_TCP       8 
#define    PROTO_UDP       9
#define    PROTO_IGRP      10   
#define    PROTO_OSPF      11
#define    PROTO_ICMPRES   12
#define    PROTO_ICMPREQ   13
#define    PROTO_HTTP      14
#define    PROTO_FTP       15
