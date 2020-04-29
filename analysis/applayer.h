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

#define        HTTP_GET             "GET"
#define        HTTP_RES             "HTTP"
#define        HTTP_POST            "POST"
#define        HTTP_PUT             "PUT"
#define        HTTP_DELETE			"DELETE"
#define		   HTTP_HEAD			"HEAD"
#define		   HTTP_OPTIONS			"OPTIONS"