#include "load_lib.h"


AL* LoadAllLibs()
{
	AL* a = (AL*)malloc(sizeof(AL));
	a->analysis = LoadLibrary(L"analysis.dll");
	if ((u_int)(a->analysis) >= 0x0 && (u_int)(a->analysis) <= 0x15) {
		return NULL;
	}
	a->basic_cap = LoadLibrary(L"basic_cap.dll");
	if ((u_int)(a->basic_cap) >= 0x0 && (u_int)(a->basic_cap) <= 0x15) {
		return NULL;
	}
	a->get_proc = LoadLibrary(L"get_proc.dll");
	if ((u_int)(a->get_proc) >= 0x0 && (u_int)(a->get_proc) <= 0x15) {
		return NULL;
	}
	a->read_dump = LoadLibrary(L"read_dump.dll");
	if ((u_int)(a->read_dump) >= 0x0 && (u_int)(a->read_dump) <= 0x15) {
		return NULL;
	}
	a->send_pack = LoadLibrary(L"send_pack.dll");
	if ((u_int)(a->send_pack) >= 0x0 && (u_int)(a->send_pack) <= 0x15) {
		return NULL;
	}
	a->write_file = LoadLibrary(L"write_file.dll");
	if ((u_int)(a->write_file) >= 0x0 && (u_int)(a->write_file) <= 0x15) {
		return NULL;
	}

	return a;
}

Ana* GetAnalysisProc(HMODULE h)
{
	Ana* a = (Ana*)malloc(sizeof(Ana));
	a->AnalyzeDNSQ = GetProcAddress(h, "AnalyzeDNSQ");
	a->AnalyzeDNSR= GetProcAddress(h, "AnalyzeDNSR");
	a->AnalyzeICMP= GetProcAddress(h, "AnalyzeICMP");
	a->AnalyzeIPv4 = GetProcAddress(h, "AnalyzeIPv4");
	a->AnalyzeIPv6 = GetProcAddress(h, "AnalyzeIPv6");
	a->AnalyzeProtoARP4 = GetProcAddress(h, "AnalyzeProtoARP4");
	a->AnalyzeProtoEth = GetProcAddress(h, "AnalyzeProtoEth");;
	a->AnalyzeTCP = GetProcAddress(h, "AnalyzeTCP");
	a->AnalyzeUDP = GetProcAddress(h, "AnalyzeUDP");
	a->DoubleBytesConbination = GetProcAddress(h, "DoubleBytesConbination");
	a->QuadBytesCombination = GetProcAddress(h, "QuadBytesCombination");
	a->GetEthiiProto = GetProcAddress(h, "GetEthiiProto");
	a->GetPacketLocalTime = GetProcAddress(h, "GetPacketLocalTime");
	a->GetPacketSize = GetProcAddress(h, "GetPacketSize");
	a->IsDNS = GetProcAddress(h, "IsDNS");
	a->IsHTTP = GetProcAddress(h, "IsHTTP");
	a->SimpleAnalyzeHTTP = GetProcAddress(h, "SimpleAnalyzeHTTP");

	return a;
}

BC* GetBasicCapProc(HMODULE h)
{
	BC* b = (BC*)malloc(sizeof(BC));
	b->CheckDataLink = GetProcAddress(h, "CheckDataLink");
	b->CloseAdapter = GetProcAddress(h, "CloseAdapter");
	b->FreeAllDevs = GetProcAddress(h, "FreeAllDevs");
	b->GetDeviceList = GetProcAddress(h, "GetDeviceList");
	b->OpenAdapterLive = GetProcAddress(h, "OpenAdapterLive");
	b->RetrivePacket = GetProcAddress(h, "RetrivePacket");
	b->TestPcapDlls = GetProcAddress(h, "TestPcapDlls");
	return b;
}

GP* GetGetProcProc(HMODULE h)
{
	GP* g = (GP*)malloc(sizeof(GP));
	g->GetProcessIdByPort = GetProcAddress(h, "GetProcessIdByPort");
	return g;
}

RD* GetReadDumpProc(HMODULE h)
{
	RD* r = (RD*)malloc(sizeof(RD));
	r->CloseFile = GetProcAddress(h, "CloseFile");
	r->OpenFileOffline = GetProcAddress(h, "OpenFileOffline");
	r->OpenOffline = GetProcAddress(h, "OpenOffline");
	return r;
}

SP* GetSendPackProc(HMODULE h)
{
	SP* s = (SP*)malloc(sizeof(SP));
	s->BasicSendPacket = GetProcAddress(h, "BasicSendPacket");
	return s;
}

WF* GetWriteFileProc(HMODULE h)
{
	WF* w = (WF*)malloc(sizeof(WF));
	w->CloseDump = GetProcAddress(h, "CloseDump");
	w->FlushDump = GetProcAddress(h, "FlushDump");
	w->OpenDumpFile = GetProcAddress(h, "OpenDumpFile");
	w->WriteDump = GetProcAddress(h, "WriteDump");
	return w;
}
