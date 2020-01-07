#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpRatchetJoint : cpConstraint
	{
		generic<typename T> where T : cpRatchetJoint, gcnew()
		static T Alloc();

		static cpRatchetJoint^ Alloc();

		generic<typename T> where T : cpRatchetJoint, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratchet);

		static cpRatchetJoint^ New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratchet);

		cpRatchetJoint^ Init(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratchet);

		property cpFloat Angle { cpFloat get(); void set(cpFloat value); }
		property cpFloat Ratchet { cpFloat get(); void set(cpFloat value); }
		property cpFloat Phase { cpFloat get(); void set(cpFloat value); }
	};
}