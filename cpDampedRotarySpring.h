#pragma once
#include "cpConstraint.h"

namespace ChipmunkCppCli
{
	ref struct cpDampedRotarySpring;

	public delegate cpFloat cpDampedRotarySpringTorqueFunc(cpDampedRotarySpring^ spring, cpFloat relativeAngle);

	public ref struct cpDampedRotarySpring : cpConstraint
	{
	private:
		DelegateHandler<cpDampedRotarySpringTorqueFunc^> _torqueFunc;

	internal:
		virtual void SetUserData() override sealed;
		virtual void UnsetUserData() override sealed;

	public:
		cpDampedRotarySpring();

		generic<typename T> where T : cpDampedRotarySpring, gcnew()
		static T Alloc();

		static cpDampedRotarySpring^ Alloc();

		generic<typename T> where T : cpDampedRotarySpring, gcnew()
		static T New(cpBody^ a, cpBody^ b, cpFloat restAngle, cpFloat stiffness, cpFloat damping);

		static cpDampedRotarySpring^ New(cpBody^ a, cpBody^ b, cpFloat restAngle, cpFloat stiffness, cpFloat damping);
		cpDampedRotarySpring^ Init(cpBody^ a, cpBody^ b, cpFloat restAngle, cpFloat stiffness, cpFloat damping);

		property cpFloat RestAngle { cpFloat get(); void set(cpFloat value); }
		property cpFloat Stiffness { cpFloat get(); void set(cpFloat value); }
		property cpFloat Damping { cpFloat get(); void set(cpFloat value); }
		property cpDampedRotarySpringTorqueFunc^ TorqueFunc { cpDampedRotarySpringTorqueFunc^ get(); void set(cpDampedRotarySpringTorqueFunc^ value); }
	};
}