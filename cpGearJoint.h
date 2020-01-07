#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpGearJoint : cpConstraint
	{
		generic<typename T> where T : cpGearJoint, gcnew()
		static T Alloc();

		static cpGearJoint^ Alloc();
		
		generic<typename T> where T : cpGearJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratio);

		static cpGearJoint^ New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratio);
		cpGearJoint^ Init(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratio);

		property cpFloat Phase { cpFloat get(); void set(cpFloat value); }
		property cpFloat Ratio { cpFloat get(); void set(cpFloat value); }
	};
}