#include "cpBB.h"
#include "cpVect.h"

namespace ChipmunkCppCli
{
	/*static*/ cpBB::operator OGcpBB(cpBB vect)
	{
		return *(OGcpBB*)&vect;
	}

	/*static*/ cpBB::operator cpBB(OGcpBB vect)
	{
		return *(cpBB*)&vect;
	}

	cpBB::cpBB(cpFloat l, cpFloat b, cpFloat r, cpFloat t) :
		l(l),
		b(b),
		r(r),
		t(t)
	{
	}

	/*static*/ cpBB cpBB::cpBBNew(cpFloat l, cpFloat b, cpFloat r, cpFloat t)
	{
		return ::cpBBNew(l, b, r, t);
	}

	/*static*/ cpBB cpBB::cpBBNewForExtents(cpVect c, cpFloat hw, cpFloat hh)
	{
		return ::cpBBNewForExtents(c, hw, hw);
	}

	/*static*/ cpBB cpBB::cpBBNewForCircle(cpVect p, cpFloat r)
	{
		return ::cpBBNewForCircle(p, r);
	}

	/*static*/ bool cpBB::cpBBIntersects(cpBB a, cpBB b)
	{
		return ::cpBBIntersects(a, b);
	}

	/*static*/ bool cpBB::cpBBContainsBB(cpBB bb, cpBB other)
	{
		return ::cpBBContainsBB(bb, other);
	}

	/*static*/ bool cpBB::cpBBContainsVect(cpBB bb, cpVect v)
	{
		return ::cpBBContainsVect(bb, v);
	}

	/*static*/ cpBB cpBB::cpBBMerge(cpBB a, cpBB b)
	{
		return ::cpBBMerge(a, b);
	}

	/*static*/ cpBB cpBB::cpBBExpand(cpBB bb, cpVect v)
	{
		return ::cpBBExpand(bb, v);
	}

	/*static*/ cpVect cpBB::cpBBCenter(cpBB bb)
	{
		return ::cpBBCenter(bb);
	}

	/*static*/ cpFloat cpBB::cpBBArea(cpBB bb)
	{
		return ::cpBBArea(bb);
	}

	/*static*/ cpFloat cpBB::cpBBMergedArea(cpBB a, cpBB b)
	{
		return ::cpBBMergedArea(a, b);
	}

	/*static*/ cpFloat cpBB::cpBBSegmentQuery(cpBB bb, cpVect a, cpVect b)
	{
		return ::cpBBSegmentQuery(bb, a, b);
	}

	/*static*/ bool cpBB::cpBBIntersectsSegment(cpBB bb, cpVect a, cpVect b)
	{
		return ::cpBBIntersectsSegment(bb, a, b);
	}

	/*static*/ cpVect cpBB::cpBBClampVect(cpBB bb, cpVect v)
	{
		return ::cpBBClampVect(bb, v);
	}

	/*static*/ cpVect cpBB::cpBBWrapVect(cpBB bb, cpVect v)
	{
		return ::cpBBWrapVect(bb, v);
	}

	/*static*/ cpBB cpBB::cpBBOffset(cpBB bb, cpVect v)
	{
		return ::cpBBOffset(bb, v);
	}
}