#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpGrooveJoint : cpConstraint
	{
		generic<typename T> where T : cpGrooveJoint, gcnew()
		static T Alloc();

		static cpGrooveJoint^ Alloc();

		generic<typename T> where T : cpGrooveJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpVect groove_a, cpVect groove_b, cpVect anchorB);

		static cpGrooveJoint^ New(cpBody^ a, cpBody^ b, cpVect groove_a, cpVect groove_b, cpVect anchorB);
		cpGrooveJoint^ Init(cpBody^ a, cpBody^ b, cpVect groove_a, cpVect groove_b, cpVect anchorB);

		property cpVect GrooveA { cpVect get(); void set(cpVect value); }
		property cpVect GrooveB { cpVect get(); void set(cpVect value); }
		property cpVect AnchorB { cpVect get(); void set(cpVect value); }
	};
}