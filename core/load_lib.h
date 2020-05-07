#pragma once
#include "uni.h"
#include "basic_structs.h"


typedef struct AllLibs
{
	HMODULE analysis;
	HMODULE basic_cap;
	HMODULE get_proc;
	HMODULE read_dump;
	HMODULE send_pack;
	HMODULE write_file;

}AL, * pAL;

typedef struct AnalysisProc
{
	FARPROC GetEthiiProto;
	FARPROC GetIPv4Proto;
	FARPROC IsHTTP;
	FARPROC IsDNS;
	FARPROC AnalyzeDNSQ;
	FARPROC AnalyzeDNSR;
	FARPROC SimpleAnalyzeHTTP;
	FARPROC GetPacketLocalTime;
	FARPROC GetPacketSize;
	FARPROC DoubleBytesConbination;
	FARPROC QuadBytesCombination;
	FARPROC  AnalyzeProtoEth;
	FARPROC AnalyzeProtoARP4;
	FARPROC AnalyzeIPv4;
	FARPROC AnalyzeIPv6;
	FARPROC AnalyzeTCP;
	FARPROC AnalyzeUDP;
	FARPROC AnalyzeICMP;

}Ana, * pAna;

typedef struct Basic_CapProc
{
	FARPROC TestPcapDlls;
	FARPROC GetDeviceList;
	FARPROC OpenAdapterLive;
	FARPROC FreeAllDevs;
	FARPROC RetrivePacket;
	FARPROC CheckDataLink;
	FARPROC CloseAdapter;

}BC, * pBC;

typedef struct GetProcProc
{
	FARPROC GetProcessIdByPort;
}GP, * pGP;

typedef struct Read_DumpProc
{
	FARPROC OpenOffline;
	FARPROC OpenFileOffline;
	FARPROC CloseFile;
}RD, * pRD;

typedef struct Send_PackProc
{
	FARPROC BasicSendPacket;
}SP, * pSP;

typedef struct Write_FileProc
{
	FARPROC OpenDumpFile;
	FARPROC WriteDump;
	FARPROC FlushDump;
	FARPROC CloseDump;
}WF, * pWF;


AL* LoadAllLibs();

Ana* GetAnalysisProc(HMODULE h);

BC* GetBasicCapProc(HMODULE h);

GP* GetGetProcProc(HMODULE h);

RD* GetReadDumpProc(HMODULE h);

SP* GetSendPackProc(HMODULE h);

WF* GetWriteFileProc(HMODULE h);