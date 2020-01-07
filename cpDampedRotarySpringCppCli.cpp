#include "cpDampedRotarySpring.h"
#include "cpVect.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	static cpFloat cpDampedRotarySpringTorqueFunc_wrapper(OGcpConstraint* spring_handle, cpFloat relativeAngle)
	{
		cpDampedRotarySpring^ spring = (cpDampedRotarySpring^)cpConstraint::FromHandle(spring_handle);
		return spring->TorqueFunc(spring, relativeAngle);
	}

	cpDampedRotarySpring::cpDampedRotarySpring() :
		_torqueFunc((DelegateHandlerSetter)cpDampedRotarySpringSetSpringTorqueFunc, (DelegateHandlerGetter)cpDampedRotarySpringGetSpringTorqueFunc, cpDampedRotarySpringTorqueFunc_wrapper)
	{
	}

	/*virtual*/ void cpDampedRotarySpring::SetUserData() /*override sealed*/
	{
		cpConstraint::SetUserData();
		_torqueFunc.Init(_handle);
	}

	/*virtual*/ void cpDampedRotarySpring::UnsetUserData() /*override sealed*/
	{
		cpConstraint::UnsetUserData();
		_torqueFunc.Free();
	}

	generic<typename T> where T : cpDampedRotarySpring, gcnew()
	/*static*/ T cpDampedRotarySpring::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpDampedRotarySpringAlloc();
		return ret;
	}

	/*static*/ cpDampedRotarySpring^ cpDampedRotarySpring::Alloc()
	{
		return Alloc<cpDampedRotarySpring^>();
	}

	generic<typename T> where T : cpDampedRotarySpring, gcnew()
	/*static*/ T cpDampedRotarySpring::New(cpBody^ a, cpBody^ b, cpFloat restAngle, cpFloat stiffness, cpFloat damping)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpDampedRotarySpringNew(a->_handle, b->_handle, restAngle, stiffness, damping);
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpDampedRotarySpring^ cpDampedRotarySpring::New(cpBody^ a, cpBody^ b, cpFloat restAngle, cpFloat stiffness, cpFloat damping)
	{
		return New<cpDampedRotarySpring^>(a, b, restAngle, stiffness, damping);
	}

	cpDampedRotarySpring^ cpDampedRotarySpring::Init(cpBody^ a, cpBody^ b, cpFloat restAngle, cpFloat stiffness, cpFloat damping)
	{
		cpDampedRotarySpringInit((::cpDampedRotarySpring*)_handle, a->_handle, b->_handle, restAngle, stiffness, damping);
		SetUserData();
		return this;
	}

	cpFloat cpDampedRotarySpring::RestAngle::get()
	{
		return cpDampedRotarySpringGetRestAngle(_handle);
	}

	void cpDampedRotarySpring::RestAngle::set(cpFloat value)
	{
		cpDampedRotarySpringSetRestAngle(_handle, value);
	}

	cpFloat cpDampedRotarySpring::Stiffness::get()
	{
		return cpDampedRotarySpringGetStiffness(_handle);
	}

	void cpDampedRotarySpring::Stiffness::set(cpFloat value)
	{
		cpDampedRotarySpringSetStiffness(_handle, value);
	}

	cpFloat cpDampedRotarySpring::Damping::get()
	{
		return cpDampedRotarySpringGetDamping(_handle);
	}

	void cpDampedRotarySpring::Damping::set(cpFloat value)
	{
		cpDampedRotarySpringSetDamping(_handle, value);
	}

	cpDampedRotarySpringTorqueFunc^ cpDampedRotarySpring::TorqueFunc::get()
	{
		return _torqueFunc.Delegate;
	}

	void cpDampedRotarySpring::TorqueFunc::set(cpDampedRotarySpringTorqueFunc^ value)
	{
		_torqueFunc.Delegate = value;
	}
}