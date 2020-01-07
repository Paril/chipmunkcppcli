#include "cpVect.h"

namespace ChipmunkCppCli
{
	/*static*/ cpVect::operator OGcpVect(cpVect vect)
	{
		return *(OGcpVect*)&vect;
	}

	/*static*/ cpVect::operator cpVect(OGcpVect vect)
	{
		return *(cpVect*)&vect;
	}

	cpVect::cpVect(cpFloat x, cpFloat y) :
		x(x),
		y(y)
	{
	}

	/*static*/ cpVect cpVect::cpv(cpFloat x, cpFloat y)
	{
		return ::cpv(x, y);
	}

	/*static*/ bool cpVect::cpveql(cpVect v1, cpVect v2)
	{
		return ::cpveql(v1, v2);
	}

	/*static*/ cpVect cpVect::cpvadd(cpVect v1, cpVect v2)
	{
		return ::cpvadd(v1, v2);
	}

	/*static*/ cpVect cpVect::cpvsub(cpVect v1, cpVect v2)
	{
		return ::cpvsub(v1, v2);
	}

	/*static*/ cpVect cpVect::cpvneg(cpVect v)
	{
		return ::cpvneg(v);
	}

	/*static*/ cpVect cpVect::cpvmult(cpVect v, cpFloat s)
	{
		return ::cpvmult(v, s);
	}

	/*static*/ cpFloat cpVect::cpvdot(cpVect v1, cpVect v2)
	{
		return ::cpvdot(v1, v2);
	}

	/*static*/ cpFloat cpVect::cpvcross(cpVect v1, cpVect v2)
	{
		return ::cpvcross(v1, v2);
	}

	/*static*/ cpVect cpVect::cpvperp(cpVect v)
	{
		return ::cpvperp(v);
	}

	/*static*/ cpVect cpVect::cpvrperp(cpVect v)
	{
		return ::cpvrperp(v);
	}

	/*static*/ cpVect cpVect::cpvproject(cpVect v1, cpVect v2)
	{
		return ::cpvproject(v1, v2);
	}

	/*static*/ cpVect cpVect::cpvforangle(cpFloat v)
	{
		return ::cpvforangle(v);
	}

	/*static*/ cpFloat cpVect::cpvtoangle(cpVect v)
	{
		return ::cpvtoangle(v);
	}

	/*static*/ cpVect cpVect::cpvrotate(cpVect v1, cpVect v2)
	{
		return ::cpvrotate(v1, v2);
	}

	/*static*/ cpVect cpVect::cpvunrotate(cpVect v1, cpVect v2)
	{
		return ::cpvunrotate(v1, v2);
	}

	/*static*/ cpFloat cpVect::cpvlengthsq(cpVect v)
	{
		return ::cpvlengthsq(v);
	}

	/*static*/ cpFloat cpVect::cpvlength(cpVect v)
	{
		return ::cpvlength(v);
	}

	/*static*/ cpVect cpVect::cpvlerp(cpVect v1, cpVect v2, cpFloat t)
	{
		return ::cpvlerp(v1, v2, t);
	}

	/*static*/ cpVect cpVect::cpvnormalize(cpVect v)
	{
		return ::cpvnormalize(v);
	}

	/*static*/ cpVect cpVect::cpvslerp(cpVect v1, cpVect v2, cpFloat t)
	{
		return ::cpvslerp(v1, v2, t);
	}

	/*static*/ cpVect cpVect::cpvslerpconst(cpVect v1, cpVect v2, cpFloat a)
	{
		return ::cpvslerpconst(v1, v2, a);
	}

	/*static*/ cpVect cpVect::cpvclamp(cpVect v, cpFloat len)
	{
		return ::cpvclamp(v, len);
	}

	/*static*/ cpVect cpVect::cpvlerpconst(cpVect v1, cpVect v2, cpFloat t)
	{
		return ::cpvlerpconst(v1, v2, t);
	}

	/*static*/ cpFloat cpVect::cpvdist(cpVect v1, cpVect v2)
	{
		return ::cpvdist(v1, v2);
	}

	/*static*/ cpFloat cpVect::cpvdistsq(cpVect v1, cpVect v2)
	{
		return ::cpvdistsq(v1, v2);
	}

	/*static*/ bool cpVect::cpvnear(cpVect v1, cpVect v2, cpFloat dist)
	{
		return ::cpvnear(v1, v2, dist);
	}
}