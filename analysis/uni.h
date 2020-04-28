#pragma once

#include <WinSock2.h>
#include <windows.h>


//链路层头部封装类型
#define    datIPv4         0x0800
#define    datARP          0x0806


//网络层头部封装类型
#define    netIPv4         0x04
#define    netIPv6         0x06
#define    netICMP         0x01   
#define    netIGMP         0x02   
#define    netTCP          0x06   
#define    netUDP          0x11   
#define    netIGRP         0x58   
#define    netOSPF         0x59   


//传输层头部封装类型
#define    icmpRes         0x0
#define    icmpReq         0x08
