#include "cpDampedSpring.h"
#include "cpVect.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	static cpFloat cpDampedSpringForceFunc_wrapper(OGcpConstraint* spring_handle, cpFloat dist)
	{
		cpDampedSpring^ spring = (cpDampedSpring^)cpConstraint::FromHandle(spring_handle);
		return spring->ForceFunc(spring, dist);
	}

	cpDampedSpring::cpDampedSpring() :
		_forceFunc((DelegateHandlerSetter)cpDampedSpringSetSpringForceFunc, (DelegateHandlerGetter)cpDampedSpringGetSpringForceFunc, cpDampedSpringForceFunc_wrapper)
	{
	}

	/*virtual*/ void cpDampedSpring::SetUserData() /*override sealed*/
	{
		cpConstraint::SetUserData();
		_forceFunc.Init(_handle);
	}

	/*virtual*/ void cpDampedSpring::UnsetUserData() /*override sealed*/
	{
		cpConstraint::UnsetUserData();
		_forceFunc.Free();
	}

	generic<typename T> where T : cpDampedSpring, gcnew()
	/*static*/ T cpDampedSpring::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpDampedSpringAlloc();
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpDampedSpring^ cpDampedSpring::Alloc()
	{
		return Alloc<cpDampedSpring^>();
	}

	generic<typename T> where T : cpDampedSpring, gcnew()
	/*static*/ T cpDampedSpring::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpDampedSpringNew(a->_handle, b->_handle, anchorA, anchorB, restLength, stiffness, damping);
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpDampedSpring^ cpDampedSpring::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping)
	{
		return New<cpDampedSpring^>(a, b, anchorA, anchorB, restLength, stiffness, damping);
	}

	cpDampedSpring^ cpDampedSpring::Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping)
	{
		cpDampedSpringInit((::cpDampedSpring*)_handle, a->_handle, b->_handle, anchorA, anchorB, restLength, stiffness, damping);
		SetUserData();
		return this;
	}

	cpVect cpDampedSpring::AnchorA::get()
	{
		return cpDampedSpringGetAnchorA(_handle);
	}

	void cpDampedSpring::AnchorA::set(cpVect value)
	{
		cpDampedSpringSetAnchorA(_handle, value);
	}

	cpVect cpDampedSpring::AnchorB::get()
	{
		return cpDampedSpringGetAnchorB(_handle);
	}

	void cpDampedSpring::AnchorB::set(cpVect value)
	{
		cpDampedSpringSetAnchorB(_handle, value);
	}

	cpFloat cpDampedSpring::RestLength::get()
	{
		return cpDampedSpringGetRestLength(_handle);
	}

	void cpDampedSpring::RestLength::set(cpFloat value)
	{
		cpDampedSpringSetRestLength(_handle, value);
	}

	cpFloat cpDampedSpring::Stiffness::get()
	{
		return cpDampedSpringGetStiffness(_handle);
	}

	void cpDampedSpring::Stiffness::set(cpFloat value)
	{
		cpDampedSpringSetStiffness(_handle, value);
	}

	cpFloat cpDampedSpring::Damping::get()
	{
		return cpDampedSpringGetDamping(_handle);
	}

	void cpDampedSpring::Damping::set(cpFloat value)
	{
		cpDampedSpringSetDamping(_handle, value);
	}

	cpDampedSpringForceFunc^ cpDampedSpring::ForceFunc::get()
	{
		return _forceFunc.Delegate;
	}

	void cpDampedSpring::ForceFunc::set(cpDampedSpringForceFunc^ value)
	{
		_forceFunc.Delegate = value;
	}
}