#pragma once

#include "common.h"
#include <cstring>

namespace ChipmunkCppCli
{
	public ref class Chipmunk2D abstract sealed
	{
	public:
		static initonly String^ cpVersionString = Encoding::ASCII->GetString((unsigned char*)::cpVersionString, (int)strlen(::cpVersionString));
		static initonly int cpVersionMajor = CP_VERSION_MAJOR;
		static initonly int cpVersionMinor = CP_VERSION_MINOR;
		static initonly int cpVersionRelease = CP_VERSION_RELEASE;
	};
}