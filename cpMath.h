#pragma once

#include "common.h"
#include "cpVect.h"
#include "cpBB.h"

const cpFloat _CP_PI = CP_PI;
#undef CP_PI

namespace ChipmunkCppCli
{
	value struct cpVect;
	value struct cpBB;

	public ref class cpMath abstract sealed
	{
	public:
		static initonly cpFloat CP_PI = _CP_PI;

		static cpFloat cpfmax(cpFloat a, cpFloat b);
		static cpFloat cpfmin(cpFloat a, cpFloat b);
		static cpFloat cpfabs(cpFloat f);
		static cpFloat cpfclamp(cpFloat f, cpFloat min, cpFloat max);
		static cpFloat cpfclamp01(cpFloat f);
		static cpFloat cpflerp(cpFloat f1, cpFloat f2, cpFloat t);
		static cpFloat cpflerpconst(cpFloat f1, cpFloat f2, cpFloat d);
		static cpFloat cpMomentForCircle(cpFloat m, cpFloat r1, cpFloat r2, cpVect offset);
		static cpFloat cpAreaForCircle(cpFloat r1, cpFloat r2);
		static cpFloat cpMomentForSegment(cpFloat m, cpVect a, cpVect b, cpFloat radius);
		static cpFloat cpAreaForSegment(cpVect a, cpVect b, cpFloat radius);
		static cpFloat cpMomentForPoly(cpFloat m, ReadOnlySpan<cpVect> verts, cpVect offset, cpFloat radius);
		static cpFloat cpAreaForPoly(ReadOnlySpan<cpVect> verts, cpFloat radius);
		static cpVect cpCentroidForPoly(ReadOnlySpan<cpVect> verts);
		static cpFloat cpMomentForBox(cpFloat m, cpFloat width, cpFloat height);
		static cpFloat cpMomentForBox2(cpFloat m, cpBB box);
		static int cpConvexHull(ReadOnlySpan<cpVect> verts, Span<cpVect> result, [Out] int% first, cpFloat tol);
		static int cpConvexHull(ReadOnlySpan<cpVect> verts, Span<cpVect> result);
		static int cpConvexHull(Span<cpVect> verts, [Out] int% first, cpFloat tol);
		static int cpConvexHull(Span<cpVect> verts);
		static cpVect cpClosetPointOnSegment(cpVect p, cpVect a, cpVect b);
	};
}