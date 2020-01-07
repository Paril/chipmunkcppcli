#include "cpMat2x2.h"
#include "cpVect.h"

namespace ChipmunkCppCli
{
	/*static*/ cpMat2x2::operator OGcpMat2x2(cpMat2x2 vect)
	{
		return *(OGcpMat2x2*)&vect;
	}

	/*static*/ cpMat2x2::operator cpMat2x2(OGcpMat2x2 vect)
	{
		return *(cpMat2x2*)&vect;
	}

	cpMat2x2::cpMat2x2(cpFloat a, cpFloat b, cpFloat c, cpFloat d) :
		a(a),
		b(b),
		c(c),
		d(d)
	{
	}

	/*static*/ cpMat2x2 cpMat2x2::cpMat2x2New(cpFloat a, cpFloat b, cpFloat c, cpFloat d)
	{
		return ::cpMat2x2New(a, b, c, d);
	}

	/*static*/ cpVect cpMat2x2::cpMat2x2Transform(cpMat2x2 m, cpVect v)
	{
		return ::cpMat2x2Transform(m, v);
	}
}