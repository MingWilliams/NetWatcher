#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <WinSock2.h>
#include <windows.h>
#include <iphlpapi.h>
#include <Iprtrmib.h>

#pragma comment(lib,"Iphlpapi.Lib")
#pragma comment(lib,"Psapi.lib")
#pragma comment(lib,"WS2_32.lib")

typedef struct {
	DWORD dwState; //连接状态
	DWORD dwLocalAddr; //本地地址
	DWORD dwLocalPort; //本地端口
	DWORD dwRemoteAddr; //远程地址
	DWORD dwRemotePort; //远程端口
	DWORD dwProcessId; //进程标识
}MIB_TCPEXROW, * PMIB_TCPEXROW;

typedef struct {
	DWORD dwLocalAddr; //本地地址
	DWORD dwLocalPort; //本地端口
	DWORD dwProcessId; //进程标识
}MIB_UDPEXROW, * PMIB_UDPEXROW;

typedef struct {
	DWORD dwState; //连接状态
	DWORD dwLocalAddr; //本地地址
	DWORD dwLocalPort; //本地端口
	DWORD dwRemoteAddr; //远程地址
	DWORD dwRemotePort; //远程端口
	DWORD dwProcessId; //进程标识
	DWORD Unknown; //待定标识
}MIB_TCPEXROW_VISTA, * PMIB_TCPEXROW_VISTA;

typedef struct {
	DWORD dwNumEntries;
	MIB_TCPEXROW table[ANY_SIZE];
}MIB_TCPEXTABLE, * PMIB_TCPEXTABLE;

typedef struct {
	DWORD dwNumEntries;
	MIB_TCPEXROW_VISTA table[ANY_SIZE];
}MIB_TCPEXTABLE_VISTA, * PMIB_TCPEXTABLE_VISTA;

typedef struct {
	DWORD dwNumEntries;
	MIB_UDPEXROW table[ANY_SIZE];
}MIB_UDPEXTABLE, * PMIB_UDPEXTABLE;

//enum OSVersion {XP,VISTA,OTHER};

typedef DWORD(WINAPI* PFNAllocateAndGetTcpExTableFromStack)(
	PMIB_TCPEXTABLE* pTcpTabel,
	bool bOrder,
	HANDLE heap,
	DWORD zero,
	DWORD flags
	);

typedef DWORD(WINAPI* PFNAllocateAndGetUdpExTableFromStack)(
	PMIB_UDPEXTABLE* pUdpTable,
	bool bOrder,
	HANDLE heap,
	DWORD zero,
	DWORD flags
	);


typedef DWORD(WINAPI* _InternalGetTcpTable2)(
	PMIB_TCPEXTABLE_VISTA* pTcpTable_Vista,
	HANDLE heap,
	DWORD flags
	);

typedef DWORD(WINAPI* _InternalGetUdpTableWithOwnerPid)(
	PMIB_UDPEXTABLE* pUdpTable,
	HANDLE heap,
	DWORD flags
	);
