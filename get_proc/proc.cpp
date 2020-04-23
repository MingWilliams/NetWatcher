#include "proc.h"



DWORD GetProcessIdByPort(int type, DWORD dwPort,HMODULE hModule)
{
    
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

                    return dwProcessId;
                }
            }

            if (pTcpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pTcpExTable);
            }

           
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

               
                return 0;
            }

            if (pInternalGetTcpTable2(&pTcpExTable, GetProcessHeap(), 1))
            {
                if (pTcpExTable)
                {
                    HeapFree(GetProcessHeap(), 0, pTcpExTable);
                }

               
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

                 
                    return dwProcessId;
                }
            }

            if (pTcpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pTcpExTable);
            }

            
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


                    return dwProcessId;
                }
            }

            if (pUdpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pUdpExTable);
            }

            
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

                        return dwProcessId;
                    }
                }
            }

            if (pUdpExTable)
            {
                HeapFree(GetProcessHeap(), 0, pUdpExTable);
            }

            
            return 0;
        }
    }
    else
    {
        
        return -1;
    }
}