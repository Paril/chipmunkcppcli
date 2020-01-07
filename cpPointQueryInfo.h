#pragma once

#include "common.h"
#include "cpVect.h"

using OGcpPointQueryInfo = ::cpPointQueryInfo;

namespace ChipmunkCppCli
{
	ref struct cpShape;

	public value struct cpPointQueryInfo
	{
		cpShape^ shape;
		cpVect point;
		cpFloat distance;
		cpVect gradient;
	};
}