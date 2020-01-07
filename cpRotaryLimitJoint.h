#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpRotaryLimitJoint : cpConstraint
	{
		generic<typename T> where T : cpRotaryLimitJoint, gcnew()
		static T Alloc();

		static cpRotaryLimitJoint^ Alloc();

		generic<typename T> where T : cpRotaryLimitJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpFloat min, cpFloat max);

		static cpRotaryLimitJoint^ New(cpBody^ a, cpBody^ b, cpFloat min, cpFloat max);
		cpRotaryLimitJoint^ Init(cpBody^ a, cpBody^ b, cpFloat min, cpFloat max);

		property cpFloat Min { cpFloat get(); void set(cpFloat value); }
		property cpFloat Max { cpFloat get(); void set(cpFloat value); }
	};
}