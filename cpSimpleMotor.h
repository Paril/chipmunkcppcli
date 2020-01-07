#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	public ref struct cpSimpleMotor : cpConstraint
	{
		generic<typename T> where T : cpSimpleMotor, gcnew()
		static T Alloc();

		static cpSimpleMotor^ Alloc();

		generic<typename T> where T : cpSimpleMotor, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpFloat rate);

		static cpSimpleMotor^ New(cpBody^ a, cpBody^ b, cpFloat rate);
		cpSimpleMotor^ Init(cpBody^ a, cpBody^ b, cpFloat rate);

		property cpFloat Rate { cpFloat get(); void set(cpFloat value); }
	};
}