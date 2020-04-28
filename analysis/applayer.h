#pragma once
#include "uni.h"


typedef struct DNSHeaderQuery
{
	u_short TransactionID;
	u_short Flag;
	u_short Questions;
	u_short AnswerRRs;
	u_short AuthorityRRs;
	u_short AdditionalRRs;
}DNSHdrQ, * pDNSHdrQ;

typedef struct DNSHeaderResponse
{
	u_short TransactionID;
	u_short Flag;
	u_short Questions;
	u_short AnswerRRs;
	u_short AuthorityRRs;
	u_short AdditionalRRs;
}DNSHdrR, * pDNSHdrR;
