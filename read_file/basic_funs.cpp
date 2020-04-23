#include "basic_funs.h"


pcap_dumper_t* __stdcall OpenDumpFile(pcap_t* ptAdHandle, LPSTR lpFilePath)
{
    pcap_dumper_t* file = pcap_dump_open(ptAdHandle, lpFilePath);
    return file;
}

void __stdcall WriteDump(pcap_dumper_t* pdtDumpFile, const pcap_pkthdr* Header, const u_char* pktData)
{
    pcap_dump((u_char*)pdtDumpFile, Header, pktData);

}

BOOL __stdcall FlushDump(pcap_dumper_t* pdtDumpFile)
{
    if (pcap_dump_flush(pdtDumpFile) == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }

}

void __stdcall CloseDump(pcap_dumper_t* pdtDumpFile)
{
    pcap_dump_close(pdtDumpFile);
    
}
