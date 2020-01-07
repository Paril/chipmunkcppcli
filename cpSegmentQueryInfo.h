#pragma once

#include "common.h"
#include "cpVect.h"

using OGcpSegmentQueryInfo = ::cpSegmentQueryInfo;

namespace ChipmunkCppCli
{
	ref struct cpShape;

	public value struct cpSegmentQueryInfo
	{
		cpShape^ shape;
		cpVect point;
		cpVect normal;
		cpFloat alpha;
	};
}