
// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
/*
#include<Windows.h>
#include<TlHelp32.h>
#include<stdio.h>

int main(int argc, char* argv[])
{
	PROCESSENTRY32 pe32;
	//在使用这个结构之前，先设置它的大小
	pe32.dwSize = sizeof(pe32);

	//给系统内所有的进程拍一个快照
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot调用失败\n");
		return -1;
	}
	//遍历进程快照，轮流显示每个进程的信息
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		printf("进程名称：%ls\n", pe32.szExeFile);
		printf("进程ID号：%u\n\n", pe32.th32ProcessID);

		bMore = ::Process32Next(hProcessSnap, &pe32);
	}

	//不要忘记清除snapshot对象
	::CloseHandle(hProcessSnap);

	
	return 0;
}
*/

#pragma once
#pragma once
#include <Windows.h>

using namespace std;




//************************************
// Method: GetProcInfo
// FullName: GetProcInfo
// Access: public
// Returns: DWORD if success,return PID;else,return -1
// Qualifier:
// Parameter: DWORD type UDP==0 TCP==1
// Parameter: DWORD port
// Parameter: LPCTSTR lpExeName
// Parameter: LPCTSTR lpExePath
//************************************
DWORD GetProcInfo(BOOL type, DWORD port, LPWSTR lpExeName, LPWSTR lpExePath)
{
	HMODULE hModule = LoadLibrary(L"iphlpapi.dll");
	if (hModule == NULL)
		return -1;
	
	if (type)
	{
		//TCP
		//声明未文档函数
		PFNAllocateAndGetTcpExTableFromStack pAllcoteAndGetTcpExTableFromStack;
		pAllcoteAndGetTcpExTableFromStack = (PFNAllocateAndGetTcpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetTcpExTableFromStack");
		if (pAllcoteAndGetTcpExTableFromStack != NULL)
		{
			//"XP";
			PMIB_TCPEXTABLE pTcpExTable;
			if (pAllcoteAndGetTcpExTableFromStack(&pTcpExTable, TRUE, GetProcessHeap(), 2, 2) != 0)
				return -1;

			for (UINT i = 0; i < pTcpExTable->dwNumEntries; i++)
			{
				int temp = ntohs(0x0000FFFF & pTcpExTable->table[i].dwLocalPort);
				if (port == temp)
				{
					HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pTcpExTable->table[i].dwProcessId);
					GetModuleBaseName(hProcess, NULL, lpExeName, MAX_PATH);
					GetModuleFileNameEx(hProcess, NULL, lpExePath, MAX_PATH);

					return pTcpExTable->table[i].dwProcessId;
				}
			}

			return -1;
		}
		else
		{
            // "VISTA 7";
			PMIB_TCPEXTABLE_VISTA pTcpTable_Vista;
			_InternalGetTcpTable2 pGetTcpTable = (_InternalGetTcpTable2)GetProcAddress(hModule, "InternalGetTcpTable2");
			if (pGetTcpTable == NULL)
				return -1;

			if (pGetTcpTable(&pTcpTable_Vista, GetProcessHeap(), 1))
				return -1;

			for (UINT i = 0; i < pTcpTable_Vista->dwNumEntries; i++)
			{
				if (port == ntohs(0x0000FFFF & pTcpTable_Vista->table[i].dwLocalPort))
				{
					HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pTcpTable_Vista->table[i].dwProcessId);
					GetModuleBaseName(hProcess, NULL, lpExeName, MAX_PATH);
					GetModuleFileNameEx(hProcess, NULL, lpExePath, MAX_PATH);

					return pTcpTable_Vista->table[i].dwProcessId;
				}
			}

			return -1;
		}

	}
	else
	{
		//声明未文档函数
		//UDP端口信息结构体
		PMIB_UDPEXTABLE pUdpExTable;
		PFNAllocateAndGetUdpExTableFromStack pAllcoteAndGetUdpExTableFromStack;
		pAllcoteAndGetUdpExTableFromStack = (PFNAllocateAndGetUdpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetUdpExTableFromStack");
		if (pAllcoteAndGetUdpExTableFromStack != NULL)
		{
			//XP
			if (pAllcoteAndGetUdpExTableFromStack(&pUdpExTable, TRUE, GetProcessHeap(), 2, 2) != 0)
				return -1;

			for (UINT i = 0; i < pUdpExTable->dwNumEntries; i++)
			{
				if (port == ntohs(0x0000FFFF & pUdpExTable->table[i].dwLocalPort))
				{
					HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pUdpExTable->table[i].dwProcessId);
					GetModuleBaseName(hProcess, NULL, lpExeName, MAX_PATH);
					GetModuleFileNameEx(hProcess, NULL, lpExePath, MAX_PATH);

					return pUdpExTable->table[i].dwProcessId;
				}
			}

			return -1;
		}
		else
		{
			//VISTA
			_InternalGetUdpTableWithOwnerPid pGetUdpTable;
			pGetUdpTable = (_InternalGetUdpTableWithOwnerPid)GetProcAddress(hModule, "InternalGetUdpTableWithOwnerPid");
			if (pGetUdpTable != NULL)
			{
				if (pGetUdpTable(&pUdpExTable, GetProcessHeap(), 1))
					return -1;

				for (UINT i = 0; i < pUdpExTable->dwNumEntries; i++)
				{
					int temp = ntohs(0x0000FFFF & pUdpExTable->table[i].dwLocalPort);
					if (temp == 8000)
					{
						printf("debuging");
					}
					if (port == temp)
					{
						HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pUdpExTable->table[i].dwProcessId);
						GetModuleBaseName(hProcess, NULL, lpExeName, MAX_PATH);
						GetModuleFileNameEx(hProcess, NULL, lpExePath, MAX_PATH);

						return pUdpExTable->table[i].dwProcessId;
					}
				}
			}

			return -1;
		}
	}
}



//=======================================================================================//
//Name: DWORD GetAllPortByProcessId()                                                    //
//                                                                                       //
//Descripion: 根据进程 ID 来求出该进程所打开的所有的端口号，并且在 dwAllPort 数组中返回所有端口号 //
//              其中 dwMaxLen 为数组的长度，函数的返回值为进程所打开的端口的数目                  //
//              (支持 XP，Server 2003，Vista，Win7)                                       //
//                                                                                       //
//=======================================================================================//
DWORD GetAllPortByProcessId(int type, DWORD dwProcessId, DWORD* dwAllPort, DWORD dwMaxLen)
{
    DWORD dwPortCount = 0;
    HMODULE hModule = LoadLibraryW(L"iphlpapi.dll");
    if (hModule == NULL)
    {
        return dwPortCount;
    }

    if (type == 1)
    {
        // 表明查询的是 TCP 信息
        PFNAllocateAndGetTcpExTableFromStack pAllocateAndGetTcpExTableFromStack;
        pAllocateAndGetTcpExTableFromStack =
            (PFNAllocateAndGetTcpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetTcpExTableFromStack");
        if (pAllocateAndGetTcpExTableFromStack != NULL)
        {
            // 表明为 XP 或者 Server 2003 操作系统
            PMIB_TCPEXTABLE pTcpExTable = NULL;
            if (pAllocateAndGetTcpExTableFromStack(&pTcpExTable, TRUE, GetProcessHeap(), 0, AF_INET) != 0)
            {
                if (pTcpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pTcpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return dwPortCount;
            }

            for (UINT i = 0; i < pTcpExTable->dwNumEntries; i++)
            {
                // 过滤掉数据，只获取我们要查询的进程的 Port 信息
                if (dwProcessId == pTcpExTable->table[i].dwProcessId)
                {
                    if (dwPortCount < dwMaxLen)
                    {
                        dwAllPort[dwPortCount] = ntohs(0x0000FFFF & pTcpExTable->table[i].dwLocalPort);
                        dwPortCount++;
                    }
                }
            }

            if (pTcpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pTcpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return dwPortCount;
        }
        else
        {
            // 表明为 Vista 或者 7 操作系统
            PMIB_TCPEXTABLE_VISTA pTcpExTable = NULL;
            PFNInternalGetTcpTable2 pInternalGetTcpTable2 =
                (PFNInternalGetTcpTable2)GetProcAddress(hModule, "InternalGetTcpTable2");
            if (pInternalGetTcpTable2 == NULL)
            {
                if (pTcpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pTcpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return dwPortCount;
            }

            if (pInternalGetTcpTable2(&pTcpExTable, GetProcessHeap(), 1))
            {
                if (pTcpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pTcpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return dwPortCount;
            }

            for (UINT i = 0; i < pTcpExTable->dwNumEntries; i++)
            {
                // 过滤掉数据，只获取我们要查询的进程的 TCP Port 信息
                if (dwProcessId == pTcpExTable->table[i].dwProcessId)
                {
                    if (dwPortCount < dwMaxLen)
                    {
                        dwAllPort[dwPortCount] = ntohs(0x0000FFFF & pTcpExTable->table[i].dwLocalPort);
                        dwPortCount++;
                    }
                }
            }

            if (pTcpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pTcpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return dwPortCount;
        }
    }
    else if (type == 0)
    {
        // 表明查询的是 UDP 信息
        PMIB_UDPEXTABLE pUdpExTable = NULL;
        PFNAllocateAndGetUdpExTableFromStack pAllocateAndGetUdpExTableFromStack;
        pAllocateAndGetUdpExTableFromStack =
            (PFNAllocateAndGetUdpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetUdpExTableFromStack");
        if (pAllocateAndGetUdpExTableFromStack != NULL)
        {
            // 表明为 XP 或者 Server 2003 操作系统
            if (pAllocateAndGetUdpExTableFromStack(&pUdpExTable, TRUE, GetProcessHeap(), 0, AF_INET) != 0)
            {
                if (pUdpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pUdpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return dwPortCount;
            }

            for (UINT i = 0; i < pUdpExTable->dwNumEntries; i++)
            {
                // 过滤掉数据，只获取我们要查询的进程的 UDP Port信息
                if (dwProcessId == pUdpExTable->table[i].dwProcessId)
                {
                    if (dwPortCount < dwMaxLen)
                    {
                        dwAllPort[dwPortCount] = ntohs(0x0000FFFF & pUdpExTable->table[i].dwLocalPort);
                        dwPortCount++;
                    }
                }
            }

            if (pUdpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pUdpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return dwPortCount;
        }
        else
        {
            // 表明为 Vista 或者 7 操作系统
            PFNInternalGetUdpTableWithOwnerPid pInternalGetUdpTableWithOwnerPid;
            pInternalGetUdpTableWithOwnerPid =
                (PFNInternalGetUdpTableWithOwnerPid)GetProcAddress(hModule, "InternalGetUdpTableWithOwnerPid");
            if (pInternalGetUdpTableWithOwnerPid != NULL)
            {
                if (pInternalGetUdpTableWithOwnerPid(&pUdpExTable, GetProcessHeap(), 1))
                {
                    if (pUdpExTable)
                    {
                        HeapFree(GetProcessHeap(), 0, pUdpExTable);
                    }

                    FreeLibrary(hModule);
                    hModule = NULL;

                    return dwPortCount;
                }

                for (UINT i = 0; i < pUdpExTable->dwNumEntries; i++)
                {
                    // 过滤掉数据，只获取我们要查询的进程的 UDP Port信息
                    if (dwProcessId == pUdpExTable->table[i].dwProcessId)
                    {
                        if (dwPortCount < dwMaxLen)
                        {
                            dwAllPort[dwPortCount] = ntohs(0x0000FFFF & pUdpExTable->table[i].dwLocalPort);
                            dwPortCount++;
                        }
                    }
                }
            }

            if (pUdpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pUdpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return dwPortCount;
        }
    }
    else
    {
        FreeLibrary(hModule);
        hModule = NULL;

        return dwPortCount;
    }
}

//=====================================================================================//
//Name: DWORD GetProcessIdByPort()                                                     //
    //                                                                                     //
    //Descripion: 根据端口号求出打开该端口号的进程 ID(支持 XP，Server 2003，Vista，Win7)        //
    //                                                                                     //
    //=====================================================================================//
DWORD GetProcessIdByPort(int type, DWORD dwPort)
{
    HMODULE hModule = LoadLibraryW(L"iphlpapi.dll");
    if (hModule == NULL)
    {
        return 0;
    }

    if (type == 1)
    {
        // 表明查询的是 TCP 信息
        PFNAllocateAndGetTcpExTableFromStack pAllocateAndGetTcpExTableFromStack;
        pAllocateAndGetTcpExTableFromStack =
            (PFNAllocateAndGetTcpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetTcpExTableFromStack");
        if (pAllocateAndGetTcpExTableFromStack != NULL)
        {
            // 表明为 XP 或者 Server 2003 操作系统
            PMIB_TCPEXTABLE pTcpExTable = NULL;
            if (pAllocateAndGetTcpExTableFromStack(&pTcpExTable, TRUE, GetProcessHeap(), 0, AF_INET) != 0)
            {
                if (pTcpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pTcpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return 0;
            }

            for (UINT i = 0; i < pTcpExTable->dwNumEntries; i++)
            {
                // 过滤掉数据，只查询我们需要的进程数据
                if (dwPort == ntohs(0x0000FFFF & pTcpExTable->table[i].dwLocalPort))
                {
                    DWORD dwProcessId = pTcpExTable->table[i].dwProcessId;
                    if (pTcpExTable)
                    {
                        HeapFree(GetProcessHeap(), 0, pTcpExTable);
                    }

                    FreeLibrary(hModule);
                    hModule = NULL;

                    return dwProcessId;
                }
            }

            if (pTcpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pTcpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return 0;
        }
        else
        {
            // 表明为 Vista 或者 7 操作系统
            PMIB_TCPEXTABLE_VISTA pTcpExTable = NULL;
            PFNInternalGetTcpTable2 pInternalGetTcpTable2 =
                (PFNInternalGetTcpTable2)GetProcAddress(hModule, "InternalGetTcpTable2");
            if (pInternalGetTcpTable2 == NULL)
            {
                if (pTcpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pTcpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return 0;
            }

            if (pInternalGetTcpTable2(&pTcpExTable, GetProcessHeap(), 1))
            {
                if (pTcpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pTcpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return 0;
            }

            for (UINT i = 0; i < pTcpExTable->dwNumEntries; i++)
            {
                // 过滤掉数据，只查询我们需要的进程数据
                if (dwPort == ntohs(0x0000FFFF & pTcpExTable->table[i].dwLocalPort))
                {
                    DWORD dwProcessId = pTcpExTable->table[i].dwProcessId;
                    if (pTcpExTable)
                    {
                        HeapFree(GetProcessHeap(), 0, pTcpExTable);
                    }

                    FreeLibrary(hModule);
                    hModule = NULL;

                    return dwProcessId;
                }
            }

            if (pTcpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pTcpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return 0;
        }
    }
    else if (type == 0)
    {
        // 表明查询的是 UDP 信息
        PMIB_UDPEXTABLE pUdpExTable = NULL;
        PFNAllocateAndGetUdpExTableFromStack pAllocateAndGetUdpExTableFromStack;
        pAllocateAndGetUdpExTableFromStack =
            (PFNAllocateAndGetUdpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetUdpExTableFromStack");
        if (pAllocateAndGetUdpExTableFromStack != NULL)
        {
            // 表明为 XP 或者 Server 2003 操作系统
            if (pAllocateAndGetUdpExTableFromStack(&pUdpExTable, TRUE, GetProcessHeap(), 0, AF_INET) != 0)
            {
                if (pUdpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pUdpExTable);
                }

                FreeLibrary(hModule);
                hModule = NULL;

                return 0;
            }

            for (UINT i = 0; i < pUdpExTable->dwNumEntries; i++)
            {
                // 过滤掉数据，只查询我们需要的进程数据
                if (dwPort == ntohs(0x0000FFFF & pUdpExTable->table[i].dwLocalPort))
                {
                    DWORD dwProcessId = pUdpExTable->table[i].dwProcessId;
                    if (pUdpExTable)
                    {
                        HeapFree(GetProcessHeap(), 0, pUdpExTable);
                    }

                    FreeLibrary(hModule);
                    hModule = NULL;

                    return dwProcessId;
                }
            }

            if (pUdpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pUdpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return 0;
        }
        else
        {
            // 表明为 Vista 或者 7 操作系统
            PFNInternalGetUdpTableWithOwnerPid pInternalGetUdpTableWithOwnerPid;
            pInternalGetUdpTableWithOwnerPid =
                (PFNInternalGetUdpTableWithOwnerPid)GetProcAddress(hModule, "InternalGetUdpTableWithOwnerPid");
            if (pInternalGetUdpTableWithOwnerPid != NULL)
            {
                if (pInternalGetUdpTableWithOwnerPid(&pUdpExTable, GetProcessHeap(), 1))
                {
                    if (pUdpExTable)
                    {
                        HeapFree(GetProcessHeap(), 0, pUdpExTable);
                    }

                    FreeLibrary(hModule);
                    hModule = NULL;

                    return 0;
                }

                for (UINT i = 0; i < pUdpExTable->dwNumEntries; i++)
                {
                    // 过滤掉数据，只查询我们需要的进程数据
                    if (dwPort == ntohs(0x0000FFFF & pUdpExTable->table[i].dwLocalPort))
                    {
                        DWORD dwProcessId = pUdpExTable->table[i].dwProcessId;
                        if (pUdpExTable)
                        {
                            HeapFree(GetProcessHeap(), 0, pUdpExTable);
                        }

                        FreeLibrary(hModule);
                        hModule = NULL;

                        return dwProcessId;
                    }
                }
            }

            if (pUdpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pUdpExTable);
            }

            FreeLibrary(hModule);
            hModule = NULL;

            return 0;
        }
    }
    else
    {
        FreeLibrary(hModule);
        hModule = NULL;

        return -1;
    }
}

int main()
{
    /*
	WCHAR szExeName[MAX_PATH] = { 0 };
	WCHAR szExePath[MAX_PATH] = { 0 };
	int type, port;
	cout << "TCP==1 UDP==0" << endl
		<< "Protocol:";
	cin >> type;
	cout << "Port:"; cin >> port;

	DWORD dwPid = GetProcInfo(type, port, szExeName, szExePath);
	if (dwPid != -1)
	{
		wcout << dwPid << "\t" << szExeName << "\t" << szExePath << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}

	return 0;
    */
    DWORD nPort = 0;
    int type = 0;
    cout << "Test GetProcessIdByPort" << endl;
    cout << "Port:" << endl;
    cin >> nPort;
    cout << "TCP == 1/UDP == 0" << endl;
    cin >> type;
    int nPid = GetProcessIdByPort(type, nPort);
    cout << "Pid is " << nPid << endl;

    return 0;
}
