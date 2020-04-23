#pragma once

#include "pch.h"



#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED


//=====================================================================================//
//Name: DWORD InternalGetTcpTable2()                                                  
//                                                                                     //
//Descripion: 该函数在 Windows Vista 以及 Windows 7 下面效                                    //
//                                                                                     
//=====================================================================================//
typedef DWORD(WINAPI* PFNInternalGetTcpTable2)(
     PMIB_TCPEXTABLE_VISTA * pTcpTable_Vista,
     HANDLE heap,
     DWORD flags
     );

//=====================================================================================//
//Name: DWORD InternalGetUdpTableWithOwnerPid()                                        //
//                                                                                     //
//Descripion: 该函数在 Windows Vista 以及 Windows 7 下面效                                    //
//                                                                                     //
//=====================================================================================//
typedef DWORD(WINAPI* PFNInternalGetUdpTableWithOwnerPid)(
     PMIB_UDPEXTABLE * pUdpTable,
     HANDLE heap,
      DWORD flags
      );

EXPORT DWORD GetProcessIdByPort(int type, DWORD dwPort, HMODULE hModule);