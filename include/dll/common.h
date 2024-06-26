#pragma once

#ifndef DBG_PTR
#define DBG_PTR 0
#endif

#include "util/logging.h"
#include "stellaris/CApplication.h"


enum enumPlatforms {
	NULL_ERR,
	STEAM,
	GOG,
};

enum enumVersions {
	VERSION_NULL,
	VERSION_UNKNOWN,
	VERSION_3_4_5,
	VERSION_3_5_1,
	VERSION_3_5_2,
	VERSION_3_6_0,
	VERSION_3_6_1,
	VERSION_3_7_2,
	VERSION_3_7_3,
	VERSION_3_7_4
};

enum enumOperatingSystems {
	OS_NULL,
	OS_UNKNOWN,
	OS_WINDOWS,
	OS_MACOS,
	OS_LINUX,
};

extern CLog logger;
