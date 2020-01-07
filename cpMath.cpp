#include "cpMath.h"
#include "Chipmunk2D.h"

namespace ChipmunkCppCli
{
	/*static*/ cpFloat cpMath::cpfmax(cpFloat a, cpFloat b)
	{
		return ::cpfmax(a, b);
	}

	/*static*/ cpFloat cpMath::cpfmin(cpFloat a, cpFloat b)
	{
		return ::cpfmin(a, b);
	}

	/*static*/ cpFloat cpMath::cpfabs(cpFloat f)
	{
		return ::cpfabs(f);
	}

	/*static*/ cpFloat cpMath::cpfclamp(cpFloat f, cpFloat min, cpFloat max)
	{
		return ::cpfclamp(f, min, max);
	}

	/*static*/ cpFloat cpMath::cpfclamp01(cpFloat f)
	{
		return ::cpfclamp01(f);
	}

	/*static*/ cpFloat cpMath::cpflerp(cpFloat f1, cpFloat f2, cpFloat t)
	{
		return ::cpflerp(f1, f2, t);
	}

	/*static*/ cpFloat cpMath::cpflerpconst(cpFloat f1, cpFloat f2, cpFloat d)
	{
		return ::cpflerpconst(f1, f2, d);
	}

	/*static*/ cpFloat cpMath::cpMomentForCircle(cpFloat m, cpFloat r1, cpFloat r2, cpVect offset)
	{
		return ::cpMomentForCircle(m, r1, r2, offset);
	}

	/*static*/ cpFloat cpMath::cpAreaForCircle(cpFloat r1, cpFloat r2)
	{
		return ::cpAreaForCircle(r1, r2);
	}

	/*static*/ cpFloat cpMath::cpMomentForSegment(cpFloat m, cpVect a, cpVect b, cpFloat radius)
	{
		return ::cpMomentForSegment(m, a, b, radius);
	}

	/*static*/ cpFloat cpMath::cpAreaForSegment(cpVect a, cpVect b, cpFloat radius)
	{
		return ::cpAreaForSegment(a, b, radius);
	}

	/*static*/ cpFloat cpMath::cpMomentForPoly(cpFloat m, ReadOnlySpan<cpVect> verts, cpVect offset, cpFloat radius)
	{
		SPAN_GET_PTR(cpVect, const ::cpVect, verts);
		return ::cpMomentForPoly(m, verts.Length, verts_ptr, offset, radius);
	}

	/*static*/ cpFloat cpMath::cpAreaForPoly(ReadOnlySpan<cpVect> verts, cpFloat radius)
	{
		SPAN_GET_PTR(cpVect, const ::cpVect, verts);
		return ::cpAreaForPoly(verts.Length, verts_ptr, radius);
	}

	/*static*/ cpVect cpMath::cpCentroidForPoly(ReadOnlySpan<cpVect> verts)
	{
		SPAN_GET_PTR(cpVect, const ::cpVect, verts);
		return ::cpCentroidForPoly(verts.Length, verts_ptr);
	}

	/*static*/ cpFloat cpMath::cpMomentForBox(cpFloat m, cpFloat width, cpFloat height)
	{
		return ::cpMomentForBox(m, width, height);
	}

	/*static*/ cpFloat cpMath::cpMomentForBox2(cpFloat m, cpBB box)
	{
		return ::cpMomentForBox2(m, box);
	}

	/*static*/ int cpMath::cpConvexHull(ReadOnlySpan<cpVect> verts, Span<cpVect> result, [Out] int% first, cpFloat tol)
	{
		SPAN_GET_PTR(cpVect, const ::cpVect, verts);
		SPAN_GET_PTR(cpVect, ::cpVect, result);
		REF_PIN(int, int, first);

		return ::cpConvexHull(verts.Length, verts_ptr, result_ptr, first_ptr, tol);
	}

	/*static*/ int cpMath::cpConvexHull(ReadOnlySpan<cpVect> verts, Span<cpVect> result)
	{
		SPAN_GET_PTR(cpVect, const ::cpVect, verts);
		SPAN_GET_PTR(cpVect, ::cpVect, result);

		return ::cpConvexHull(verts.Length, verts_ptr, result_ptr, nullptr, 0);
	}

	/*static*/ int cpMath::cpConvexHull(Span<cpVect> verts, [Out] int% first, cpFloat tol)
	{
		SPAN_GET_PTR(cpVect, ::cpVect, verts);
		REF_PIN(int, int, first);

		return ::cpConvexHull(verts.Length, verts_ptr, verts_ptr, first_ptr, tol);
	}

	/*static*/ int cpMath::cpConvexHull(Span<cpVect> verts)
	{
		SPAN_GET_PTR(cpVect, ::cpVect, verts);
		return ::cpConvexHull(verts.Length, verts_ptr, verts_ptr, nullptr, 0);
	}

	/*static*/ cpVect cpMath::cpClosetPointOnSegment(cpVect p, cpVect a, cpVect b)
	{
		return ::cpClosetPointOnSegment(p, a, b);
	}
}