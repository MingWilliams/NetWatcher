#include "basic_funs.h"

#include <stdio.h>
#include <pcap.h>


pcap_t* __stdcall OpenOffline(LPSTR lpFileName, char* errbuf)
{


	return pcap_open_offline(lpFileName,errbuf) ;
}

pcap_t* __stdcall OpenFileOffline(FILE* fp, char* errbuf)
{
	return pcap_fopen_offline(fp,errbuf);
}

void __stdcall CloseFile(pcap_t * fp)
{
    pcap_close(fp);
}
