#pragma once

#include "common.h"

using OGcpBB = ::cpBB;

namespace ChipmunkCppCli
{
	value struct cpVect;

	[StructLayout(LayoutKind::Sequential)]
	public value struct cpBB
	{
		cpFloat l, b, r, t;

	internal:
		static operator OGcpBB(cpBB vect);
		static operator cpBB(OGcpBB vect);

	public:
		cpBB(cpFloat l, cpFloat b, cpFloat r, cpFloat t);

		static cpBB cpBBNew(cpFloat l, cpFloat b, cpFloat r, cpFloat t);
		static cpBB cpBBNewForExtents(cpVect c, cpFloat hw, cpFloat hh);
		static cpBB cpBBNewForCircle(cpVect p, cpFloat r);
		static bool cpBBIntersects(cpBB a, cpBB b);
		static bool cpBBContainsBB(cpBB bb, cpBB other);
		static bool cpBBContainsVect(cpBB bb, cpVect v);
		static cpBB cpBBMerge(cpBB a, cpBB b);
		static cpBB cpBBExpand(cpBB bb, cpVect v);
		static cpVect cpBBCenter(cpBB bb);
		static cpFloat cpBBArea(cpBB bb);
		static cpFloat cpBBMergedArea(cpBB a, cpBB b);
		static cpFloat cpBBSegmentQuery(cpBB bb, cpVect a, cpVect b);
		static bool cpBBIntersectsSegment(cpBB bb, cpVect a, cpVect b);
		static cpVect cpBBClampVect(cpBB bb, cpVect v);
		static cpVect cpBBWrapVect(cpBB bb, cpVect v);
		static cpBB cpBBOffset(cpBB bb, cpVect v);
	};
}