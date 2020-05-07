#pragma once
#include "basic_funs.h"
#include "applayer.h"

EXPORT int GetEthiiProto(_In_ Eth2Hdr* h);

EXPORT int GetIPv4Proto(_In_ IP4Hdr* h);

EXPORT BOOL IsHTTP(_In_ const u_char* data,_In_ int nNetProto);

EXPORT BOOL IsDNS(_In_ UDPHdr* h);

