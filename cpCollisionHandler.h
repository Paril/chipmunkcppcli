#pragma once

#include "common.h"

using OGcpCollisionHandler = ::cpCollisionHandler;

namespace ChipmunkCppCli
{
	value struct cpArbiter;
	ref struct cpSpace;

	public delegate bool cpCollisionBeginFunc(cpArbiter arb, cpSpace^ space);
	public delegate bool cpCollisionPreSolveFunc(cpArbiter arb, cpSpace^ space);
	public delegate void cpCollisionPostSolveFunc(cpArbiter arb, cpSpace^ space);
	public delegate void cpCollisionSeparateFunc(cpArbiter arb, cpSpace^ space);

	public ref struct cpCollisionHandler
	{
	internal:
		OGcpCollisionHandler* _handle;

		cpCollisionBeginFunc^ _beginFunc;
		cpCollisionPreSolveFunc^ _preSolveFunc;
		cpCollisionPostSolveFunc^ _postSolveFunc;
		cpCollisionSeparateFunc^ _separateFunc;

		::cpCollisionBeginFunc _defaultBeginFunc;
		::cpCollisionPreSolveFunc _defaultPreSolveFunc;
		::cpCollisionPostSolveFunc _defaultPostSolveFunc;
		::cpCollisionSeparateFunc _defaultSeparateFunc;

		cpCollisionHandler(OGcpCollisionHandler* handle);

	public:
		property cpCollisionBeginFunc^ Begin { cpCollisionBeginFunc^ get(); void set(cpCollisionBeginFunc^ value); }
		property cpCollisionPreSolveFunc^ PreSolve { cpCollisionPreSolveFunc^ get(); void set(cpCollisionPreSolveFunc^ value); }
		property cpCollisionPostSolveFunc^ PostSolve { cpCollisionPostSolveFunc^ get(); void set(cpCollisionPostSolveFunc^ value); }
		property cpCollisionSeparateFunc^ Separate { cpCollisionSeparateFunc^ get(); void set(cpCollisionSeparateFunc^ value); }
	};
}