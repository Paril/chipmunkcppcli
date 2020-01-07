#include "cpTransform.h"
#include "cpVect.h"
#include "cpBB.h"

namespace ChipmunkCppCli
{
	/*static*/ cpTransform::operator OGcpTransform(cpTransform vect)
	{
		return *(OGcpTransform*)&vect;
	}

	/*static*/ cpTransform::operator cpTransform(OGcpTransform vect)
	{
		return *(cpTransform*)&vect;
	}

	cpTransform::cpTransform(cpFloat a, cpFloat b, cpFloat c, cpFloat d, cpFloat tx, cpFloat ty) :
		a(a),
		b(b),
		c(c),
		d(d),
		tx(tx),
		ty(ty)
	{
	}

	/*static*/ cpTransform cpTransform::cpTransformNew(cpFloat a, cpFloat b, cpFloat c, cpFloat d, cpFloat tx, cpFloat ty)
	{
		return ::cpTransformNew(a, b, c, d, tx, ty);
	}
	
	/*static*/ cpTransform cpTransform::cpTransformNewTranspose(cpFloat a, cpFloat c, cpFloat tx, cpFloat b, cpFloat d, cpFloat ty)
	{
		return ::cpTransformNew(a, c, tx, b, d, ty);
	}

	/*static*/ cpTransform cpTransform::cpTransformInverse(cpTransform t)
	{
		return ::cpTransformInverse(t);
	}

	/*static*/ cpTransform cpTransform::cpTransformMult(cpTransform t1, cpTransform t2)
	{
		return ::cpTransformMult(t1, t2);
	}

	/*static*/ cpVect cpTransform::cpTransformPoint(cpTransform t, cpVect p)
	{
		return ::cpTransformPoint(t, p);
	}

	/*static*/ cpVect cpTransform::cpTransformVect(cpTransform t, cpVect p)
	{
		return ::cpTransformVect(t, p);
	}

	/*static*/ cpBB cpTransform::cpTransformbBB(cpTransform t, cpBB bb)
	{
		return ::cpTransformbBB(t, bb);
	}

	/*static*/ cpTransform cpTransform::cpTransformTranslate(cpVect translate)
	{
		return ::cpTransformTranslate(translate);
	}

	/*static*/ cpTransform cpTransform::cpTransformScale(cpFloat scaleX, cpFloat scaleY)
	{
		return ::cpTransformScale(scaleX, scaleY);
	}

	/*static*/ cpTransform cpTransform::cpTransformRotate(cpFloat radians)
	{
		return ::cpTransformRotate(radians);
	}

	/*static*/ cpTransform cpTransform::cpTransformRigid(cpVect translate, cpFloat radians)
	{
		return ::cpTransformRigid(translate, radians);
	}

	/*static*/ cpTransform cpTransform::cpTransformRigidInverse(cpTransform t)
	{
		return ::cpTransformRigidInverse(t);
	}

	/*static*/ cpTransform cpTransform::cpTransformWrap(cpTransform outer, cpTransform inner)
	{
		return ::cpTransformWrap(outer, inner);
	}

	/*static*/ cpTransform cpTransform::cpTransformWrapInverse(cpTransform outer, cpTransform inner)
	{
		return ::cpTransformWrapInverse(outer, inner);
	}

	/*static*/ cpTransform cpTransform::cpTransformOrtho(cpBB bb)
	{
		return ::cpTransformOrtho(bb);
	}

	/*static*/ cpTransform cpTransform::cpTransformBoneScale(cpVect v0, cpVect v1)
	{
		return ::cpTransformBoneScale(v0, v1);
	}

	/*static*/ cpTransform cpTransform::cpTransformAxialScale(cpVect axis, cpVect pivot, cpFloat scale)
	{
		return ::cpTransformAxialScale(axis, pivot, scale);
	}
}