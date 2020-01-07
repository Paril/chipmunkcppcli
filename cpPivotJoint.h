#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpPivotJoint : cpConstraint
	{
		generic<typename T> where T : cpPivotJoint, gcnew()
		static T Alloc();

		static cpPivotJoint^ Alloc();

		generic<typename T> where T : cpPivotJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpVect pivot);

		generic<typename T> where T : cpPivotJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB);

		static cpPivotJoint^ New(cpBody^ a, cpBody^ b, cpVect pivot);
		static cpPivotJoint^ New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB);

		cpPivotJoint^ Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB);

		property cpVect AnchorA { cpVect get(); void set(cpVect value); }
		property cpVect AnchorB { cpVect get(); void set(cpVect value); }
	};
}