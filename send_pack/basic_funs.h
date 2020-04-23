#pragma once

#include "uni.h"


#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCDECL EXPORT NAKED


EXPORT int BasicSendPacket(pcap_t * ptAdapter,u_char lpPacket[],int nSize);
