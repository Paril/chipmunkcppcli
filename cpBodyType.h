#pragma once

#include "common.h"

namespace ChipmunkCppCli
{
	using OGcpBodyType = ::cpBodyType;

	public enum class cpBodyType
	{
		Dynamic = CP_BODY_TYPE_DYNAMIC,
		Kinematic = CP_BODY_TYPE_KINEMATIC,
		Static = CP_BODY_TYPE_STATIC
	};
}