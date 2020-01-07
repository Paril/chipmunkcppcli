#pragma once

#include "common.h"
#include "cpVect.h"

using OGcpContactPointSet = cpContactPointSet;

namespace ChipmunkCppCli
{
	[StructLayout(LayoutKind::Sequential)]
	public value struct cpContactPoint
	{
		cpVect pointA, pointB;
		cpFloat distance;
	};

	public value struct cpContactPointSet
	{
		array<cpContactPoint>^ points;
		cpVect normal;

	internal:
		static operator OGcpContactPointSet(cpContactPointSet set);
		static operator cpContactPointSet(const OGcpContactPointSet &set);
	};
}