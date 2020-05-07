#include "analy.h"

int GetEthiiProto(Eth2Hdr* h)
{
    if (h->ProtocolType == datIPv4) {
        return PROTO_IPv4;
    }
    else if (h->ProtocolType == datARPv4) {
        return PROTO_ARPv4;
    }
    else {
        return PROTO_UNKNOWN;
    }
 
}

int GetIPv4Proto(IP4Hdr* h)
{
    switch (h->ProtocolType)
    {
    case netICMP:
        return PROTO_ICMP;
    case netTCP:
        return PROTO_TCP;
    case netUDP:
        return PROTO_UDP;
    default:
        return PROTO_UNKNOWN;
    }
}

BOOL IsHTTP(const u_char* data, int nNetProto)
{
    if (nNetProto == PROTO_IPv4) {

        if (SimpleAnalyzeHTTP(data, PROTO_IPv4) == PROTO_UNKNOWN) {
            return FALSE;
        }
        else {
            return TRUE;
        }
    }
    else {
        return FALSE;
    }
}

BOOL IsDNS(UDPHdr* h)
{
    if ((h->DestPort == 53) || (h->SrcPort == 53) ){
        return TRUE;
    }
    else {
        return FALSE;
    }
}
