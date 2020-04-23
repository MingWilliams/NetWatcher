#include "proc.h"



DWORD GetProcessIdByPort(int type, DWORD dwPort,HMODULE hModule)
{
    
    if (hModule == NULL)
    {
        return 0;
    }

    if (type == 1)
    {
        // ������ѯ���� TCP ��Ϣ
        PFNAllocateAndGetTcpExTableFromStack pAllocateAndGetTcpExTableFromStack;
        pAllocateAndGetTcpExTableFromStack =
            (PFNAllocateAndGetTcpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetTcpExTableFromStack");
        if (pAllocateAndGetTcpExTableFromStack != NULL)
        {
            // ����Ϊ XP ���� Server 2003 ����ϵͳ
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
                // ���˵����ݣ�ֻ��ѯ������Ҫ�Ľ�������
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
            // ����Ϊ Vista ���� 7 ����ϵͳ
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
                // ���˵����ݣ�ֻ��ѯ������Ҫ�Ľ�������
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
        // ������ѯ���� UDP ��Ϣ
        PMIB_UDPEXTABLE pUdpExTable = NULL;
        PFNAllocateAndGetUdpExTableFromStack pAllocateAndGetUdpExTableFromStack;
        pAllocateAndGetUdpExTableFromStack =
            (PFNAllocateAndGetUdpExTableFromStack)GetProcAddress(hModule, "AllocateAndGetUdpExTableFromStack");
        if (pAllocateAndGetUdpExTableFromStack != NULL)
        {
            // ����Ϊ XP ���� Server 2003 ����ϵͳ
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
                // ���˵����ݣ�ֻ��ѯ������Ҫ�Ľ�������
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
            // ����Ϊ Vista ���� 7 ����ϵͳ
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
                    // ���˵����ݣ�ֻ��ѯ������Ҫ�Ľ�������
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