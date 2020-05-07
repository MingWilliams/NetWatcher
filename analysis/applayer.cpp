#include "applayer.h"

DNSHdrQ* AnalyzeDNSQ(const u_char* data, int nPrevProto,int nProto)
{
	if (nPrevProto == PROTO_IPv4) {
		DNSHdrQ* hdr = (DNSHdrQ*)malloc(sizeof(DNSHdrQ));
		const u_char* temp = data + sizeof(IP4Hdr) + sizeof(Eth2Hdr) + sizeof(UDPHdr);
		hdr->TransactionID = DoubleBytesConbination(*(temp), *(temp + 1));
		hdr->Flag = DoubleBytesConbination(*(temp + 2), *(temp + 3));
		hdr->Questions = DoubleBytesConbination(*(temp + 4), *(temp + 5));
		hdr->AnswerRRs = DoubleBytesConbination(*(temp + 6), *(temp + 7));
		hdr->AuthorityRRs = DoubleBytesConbination(*(temp + 8), *(temp + 9));
		hdr->AdditionalRRs = DoubleBytesConbination(*(temp + 10), *(temp + 11));

		nProto = PROTO_DNSQ;
		return hdr;
	}
	else if (nPrevProto == PROTO_IPv6) {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}
	else {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}

}

DNSHdrR* AnalyzeDNSR(const u_char* data, int nPrevProto, int nProto)
{
	if (nPrevProto == PROTO_IPv4) {
		DNSHdrR* hdr = (DNSHdrR*)malloc(sizeof(DNSHdrR));
		const u_char* temp = data + sizeof(IP4Hdr) + sizeof(Eth2Hdr) + sizeof(UDPHdr);
		hdr->TransactionID = DoubleBytesConbination(*(temp), *(temp + 1));
		hdr->Flag = DoubleBytesConbination(*(temp + 2), *(temp + 3));
		hdr->Questions = DoubleBytesConbination(*(temp + 4), *(temp + 5));
		hdr->AnswerRRs = DoubleBytesConbination(*(temp + 6), *(temp + 7));
		hdr->AuthorityRRs = DoubleBytesConbination(*(temp + 8), *(temp + 9));
		hdr->AdditionalRRs = DoubleBytesConbination(*(temp + 10), *(temp + 11));

		nProto = PROTO_DNSR;
		return hdr;
	}

	else if (nPrevProto == PROTO_IPv6) {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}
	else {
		nProto = PROTO_UNKNOWN;
		return NULL;
	}
}

int SimpleAnalyzeHTTP(const u_char* data, int nPrevProto)
{
	if (nPrevProto == PROTO_IPv4) {
		const u_char* t = data + sizeof(Eth2Hdr) + sizeof(IP4Hdr) + sizeof(TCPHdr);

		byte s = 0;
		byte s1 = *t;
		byte s2 = *(t + 1);
		byte s3 = *(t + 2);
		int i = 0;

		if (s1 == *HTTP_GET) {
			if (s2 == *(HTTP_GET + 1)) {
				if (s3 == *(HTTP_GET + 2)) {
					return PROTO_HTTP;
				}
				return PROTO_UNKNOWN;
			}
			return PROTO_UNKNOWN;
			
		}
		else if (s1 == *HTTP_RES) {
			for (i = 1; i < 4; i++) {
				s = *(t + i);
				if (s == *(HTTP_RES + i)) {
					continue;
				}
				else {
					return PROTO_UNKNOWN;
				}
			}
			return PROTO_HTTP;
		}
		else if (s1 == *HTTP_POST) {
			return PROTO_HTTP;
		}
		else if (s1 == *HTTP_DELETE) {
			return PROTO_HTTP;
		}
		else if (s1 == *HTTP_HEAD) {
			return PROTO_HTTP;
		}
		else if (s1 == *HTTP_OPTIONS) {
			return PROTO_HTTP;
		}
		else {
			return PROTO_UNKNOWN;
		}
	}

	else if (nPrevProto == PROTO_IPv6) {
		
		return PROTO_UNKNOWN;
	}
	else {
		
		return PROTO_UNKNOWN;
	}
}
