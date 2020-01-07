#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpPinJoint : cpConstraint
	{
		generic<typename T> where T : cpPinJoint, gcnew()
		static T Alloc();

		static cpPinJoint^ Alloc();

		generic<typename T> where T : cpPinJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB);

		static cpPinJoint^ New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB);
		cpPinJoint^ Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB);

		property cpVect AnchorA { cpVect get(); void set(cpVect value); }
		property cpVect AnchorB { cpVect get(); void set(cpVect value); }
		property cpFloat Dist { cpFloat get(); void set(cpFloat value); }
	};
}