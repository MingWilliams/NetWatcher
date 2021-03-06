﻿// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"

#endif //PCH_H


//=====================================================================================//
//Name: DWORD InternalGetTcpTable2()                                                  
//                                                                                     //
//Descripion: 该函数在 Windows Vista 以及 Windows 7 下面效                                    //
//                                                                                     
//=====================================================================================//
typedef DWORD(WINAPI* PFNInternalGetTcpTable2)(
    PMIB_TCPEXTABLE_VISTA* pTcpTable_Vista,
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
    PMIB_UDPEXTABLE* pUdpTable,
    HANDLE heap,
    DWORD flags
    );
