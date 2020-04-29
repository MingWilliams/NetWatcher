#pragma once
#include "uni.h"

#include "datlayer.h"
#include "netlayer.h"
#include "datlayer.h"
#include "applayer.h"

struct tm GetPacketLocalTime(const struct pcap_pkthdr* header);

u_int GetPacketSize(const struct pcap_pkthdr* header);