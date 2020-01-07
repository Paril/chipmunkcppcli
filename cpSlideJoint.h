#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpSlideJoint : cpConstraint
	{
		generic<typename T> where T : cpSlideJoint, gcnew()
		static T Alloc();

		static cpSlideJoint^ Alloc();

		generic<typename T> where T : cpSlideJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max);

		static cpSlideJoint^ New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max);
		cpSlideJoint^ Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max);

		property cpVect AnchorA { cpVect get(); void set(cpVect value); }
		property cpVect AnchorB { cpVect get(); void set(cpVect value); }
		property cpFloat Min { cpFloat get(); void set(cpFloat value); }
		property cpFloat Max { cpFloat get(); void set(cpFloat value); }
	};
}