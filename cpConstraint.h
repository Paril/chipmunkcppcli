#pragma once

#include "common.h"

using OGcpConstraint = cpConstraint;

namespace ChipmunkCppCli
{
	ref struct cpConstraint;
	ref struct cpSpace;
	ref struct cpBody;
	value struct cpVect;

	public delegate void cpConstraintPreSolveFunc(cpConstraint^ constraint, cpSpace^ space);
	public delegate void cpConstraintPostSolveFunc(cpConstraint^ constraint, cpSpace^ space);

	public ref struct cpConstraint
	{
	internal:
		OGcpConstraint* _handle;
		GCHandle _gc;
		DelegateHandler<cpConstraintPreSolveFunc^> _preSolve;
		DelegateHandler<cpConstraintPostSolveFunc^> _postSolve;

		static cpConstraint^ FromHandle(OGcpConstraint* constraint);

		virtual void SetUserData();
		virtual void UnsetUserData();

	protected:
		cpConstraint();

	public:
		void Destroy();
		void Free();

		property cpSpace^ Space { cpSpace^ get(); }
		property cpBody^ BodyA { cpBody^ get(); }
		property cpBody^ BodyB { cpBody^ get(); }
		property cpFloat MaxForce { cpFloat get(); void set(cpFloat value); }
		property cpFloat ErrorBias { cpFloat get(); void set(cpFloat value); }
		property cpFloat MaxBias { cpFloat get(); void set(cpFloat value); }
		property bool CollideBodies { bool get(); void set(bool value); }
		property cpConstraintPreSolveFunc^ PreSolveFunc { cpConstraintPreSolveFunc^ get(); void set(cpConstraintPreSolveFunc^ value); }
		property cpConstraintPostSolveFunc^ PostSolveFunc { cpConstraintPostSolveFunc^ get(); void set(cpConstraintPostSolveFunc^ value); }
		property cpFloat Impulse { cpFloat get(); }

#define DEFINE_IS_CONSTRAINT_METHOD(type) \
		bool Is ## type() { return cpConstraintIs ## type(_handle); }

		DEFINE_IS_CONSTRAINT_METHOD(DampedRotarySpring);
		DEFINE_IS_CONSTRAINT_METHOD(DampedSpring);
		DEFINE_IS_CONSTRAINT_METHOD(GearJoint);
		DEFINE_IS_CONSTRAINT_METHOD(GrooveJoint);
		DEFINE_IS_CONSTRAINT_METHOD(PinJoint);
		DEFINE_IS_CONSTRAINT_METHOD(PivotJoint);
		DEFINE_IS_CONSTRAINT_METHOD(RatchetJoint);
		DEFINE_IS_CONSTRAINT_METHOD(RotaryLimitJoint);
		DEFINE_IS_CONSTRAINT_METHOD(SimpleMotor);
		DEFINE_IS_CONSTRAINT_METHOD(SlideJoint);
	};
}