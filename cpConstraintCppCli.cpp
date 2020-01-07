#include "cpConstraint.h"
#include "cpSpace.h"
#include "cpBody.h"
#include "cpVect.h"

namespace ChipmunkCppCli
{
	/*static*/ cpConstraint^ cpConstraint::FromHandle(OGcpConstraint* constraint)
	{
		return (cpConstraint^)GCHandle::FromIntPtr((IntPtr)cpConstraintGetUserData(constraint)).Target;
	}

	/*virtual*/ void cpConstraint::SetUserData()
	{
		_gc = GCHandle::Alloc(this);
		cpConstraintSetUserData(_handle, GCHandle::ToIntPtr(_gc).ToPointer());
		_preSolve.Init(_handle);
		_postSolve.Init(_handle);
	}

	/*virtual*/ void cpConstraint::UnsetUserData()
	{
		cpConstraintSetUserData(_handle, nullptr);
		if (_gc.IsAllocated)
			_gc.Free();
		_preSolve.Free();
		_postSolve.Free();
	}

	static void cpConstraintPreSolveFunc_wrapper(OGcpConstraint* constraint, OGcpSpace* space)
	{
		cpConstraint^ constraint_ptr = cpConstraint::FromHandle(constraint);
		constraint_ptr->PreSolveFunc(constraint_ptr, cpSpace::FromHandle(space));
	}

	static void cpConstraintPostSolveFunc_wrapper(OGcpConstraint* constraint, OGcpSpace* space)
	{
		cpConstraint^ constraint_ptr = cpConstraint::FromHandle(constraint);
		constraint_ptr->PostSolveFunc(constraint_ptr, cpSpace::FromHandle(space));
	}

	cpConstraint::cpConstraint() :
		_preSolve((DelegateHandlerSetter)cpConstraintSetPreSolveFunc, (DelegateHandlerGetter)cpConstraintGetPreSolveFunc, cpConstraintPreSolveFunc_wrapper),
		_postSolve((DelegateHandlerSetter)cpConstraintSetPostSolveFunc, (DelegateHandlerGetter)cpConstraintGetPostSolveFunc, cpConstraintPostSolveFunc_wrapper)
	{
	}
	
	void cpConstraint::Destroy()
	{
		UnsetUserData();
		cpConstraintDestroy(_handle);
	}

	void cpConstraint::Free()
	{
		UnsetUserData();
		cpConstraintFree(_handle);
		_handle = nullptr;
	}

	cpSpace^ cpConstraint::Space::get()
	{
		return cpSpace::FromHandle(cpConstraintGetSpace(_handle));
	}

	cpBody^ cpConstraint::BodyA::get()
	{
		return cpBody::FromHandle(cpConstraintGetBodyA(_handle));
	}

	cpBody^ cpConstraint::BodyB::get()
	{
		return cpBody::FromHandle(cpConstraintGetBodyB(_handle));
	}

	cpFloat cpConstraint::MaxForce::get()
	{
		return cpConstraintGetMaxForce(_handle);
	}

	void cpConstraint::MaxForce::set(cpFloat value)
	{
		cpConstraintSetMaxForce(_handle, value);
	}

	cpFloat cpConstraint::ErrorBias::get()
	{
		return cpConstraintGetErrorBias(_handle);
	}

	void cpConstraint::ErrorBias::set(cpFloat value)
	{
		cpConstraintSetErrorBias(_handle, value);
	}

	cpFloat cpConstraint::MaxBias::get()
	{
		return cpConstraintGetMaxBias(_handle);
	}

	void cpConstraint::MaxBias::set(cpFloat value)
	{
		cpConstraintSetMaxBias(_handle, value);
	}

	bool cpConstraint::CollideBodies::get()
	{
		return cpConstraintGetCollideBodies(_handle);
	}

	void cpConstraint::CollideBodies::set(bool value)
	{
		cpConstraintSetCollideBodies(_handle, value);
	}

	cpConstraintPreSolveFunc^ cpConstraint::PreSolveFunc::get()
	{
		return _preSolve.Delegate;
	}

	void cpConstraint::PreSolveFunc::set(cpConstraintPreSolveFunc^ value)
	{
		_preSolve.Delegate = value;
	} 

	cpConstraintPostSolveFunc^ cpConstraint::PostSolveFunc::get()
	{
		return _postSolve.Delegate;
	}

	void cpConstraint::PostSolveFunc::set(cpConstraintPostSolveFunc^ value)
	{ 
		_postSolve.Delegate = value;
	}

	cpFloat cpConstraint::Impulse::get()
	{
		return cpConstraintGetImpulse(_handle);
	}
}