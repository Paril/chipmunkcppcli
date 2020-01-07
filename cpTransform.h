#pragma once

#include "common.h"

using OGcpTransform = ::cpTransform;

namespace ChipmunkCppCli
{
	value struct cpVect;
	value struct cpBB;

	[StructLayout(LayoutKind::Sequential)]
	public value struct cpTransform
	{
		static initonly cpTransform cpTransformIdentity = ::cpTransformIdentity;
		static initonly cpTransform Identity = ::cpTransformIdentity;

		cpFloat a, b, c, d, tx, ty;

	internal:
		static operator OGcpTransform(cpTransform vect);
		static operator cpTransform(OGcpTransform vect);

	public:
		cpTransform(cpFloat a, cpFloat b, cpFloat c, cpFloat d, cpFloat tx, cpFloat ty);

		static cpTransform cpTransformNew(cpFloat a, cpFloat b, cpFloat c, cpFloat d, cpFloat tx, cpFloat ty);
		static cpTransform cpTransformNewTranspose(cpFloat a, cpFloat c, cpFloat tx, cpFloat b, cpFloat d, cpFloat ty);
		static cpTransform cpTransformInverse(cpTransform t);
		static cpTransform cpTransformMult(cpTransform t1, cpTransform t2);
		static cpVect cpTransformPoint(cpTransform t, cpVect p);
		static cpVect cpTransformVect(cpTransform t, cpVect p);
		static cpBB cpTransformbBB(cpTransform t, cpBB bb);
		static cpTransform cpTransformTranslate(cpVect translate);
		static cpTransform cpTransformScale(cpFloat scaleX, cpFloat scaleY);
		static cpTransform cpTransformRotate(cpFloat radians);
		static cpTransform cpTransformRigid(cpVect translate, cpFloat radians);
		static cpTransform cpTransformRigidInverse(cpTransform t);
		static cpTransform cpTransformWrap(cpTransform outer, cpTransform inner);
		static cpTransform cpTransformWrapInverse(cpTransform outer, cpTransform inner);
		static cpTransform cpTransformOrtho(cpBB bb);
		static cpTransform cpTransformBoneScale(cpVect v0, cpVect v1);
		static cpTransform cpTransformAxialScale(cpVect axis, cpVect pivot, cpFloat scale);
	};
}