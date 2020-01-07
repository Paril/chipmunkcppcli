#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	ref struct cpDampedSpring;

	public delegate cpFloat cpDampedSpringForceFunc(cpDampedSpring^ spring, cpFloat dist);

	public ref struct cpDampedSpring : cpConstraint
	{
	private:
		DelegateHandler<cpDampedSpringForceFunc^> _forceFunc;

	internal:
		virtual void SetUserData() override sealed;
		virtual void UnsetUserData() override sealed;

	public:
		cpDampedSpring();

		generic<typename T> where T : cpDampedSpring, gcnew()
		static T Alloc();

		static cpDampedSpring^ Alloc();

		generic<typename T> where T : cpDampedSpring, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping);

		static cpDampedSpring^ New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping);

		cpDampedSpring^ Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping);

		property cpVect AnchorA { cpVect get(); void set(cpVect value); }
		property cpVect AnchorB { cpVect get(); void set(cpVect value); }
		property cpFloat RestLength { cpFloat get(); void set(cpFloat value); }
		property cpFloat Stiffness { cpFloat get(); void set(cpFloat value); }
		property cpFloat Damping { cpFloat get(); void set(cpFloat value); }
		property cpDampedSpringForceFunc^ ForceFunc { cpDampedSpringForceFunc^ get(); void set(cpDampedSpringForceFunc^ value); }
	};
}