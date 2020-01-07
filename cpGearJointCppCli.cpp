#include "cpGearJoint.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpGearJoint, gcnew()
	/*static*/ T cpGearJoint::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpGearJointAlloc();
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpGearJoint^ cpGearJoint::Alloc()
	{
		return Alloc<cpGearJoint^>();
	}

	generic<typename T> where T : cpGearJoint, gcnew()
	/*static*/ T cpGearJoint::New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratio)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpGearJointNew(a->_handle, b->_handle, phase, ratio);
		return ret;
	}

	/*static*/ cpGearJoint^ cpGearJoint::New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratio)
	{
		return New<cpGearJoint^>(a, b, phase, ratio);
	}

	cpGearJoint^ cpGearJoint::Init(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratio)
	{
		cpGearJointInit((::cpGearJoint*)_handle, a->_handle, b->_handle, phase, ratio);
		SetUserData();
		return this;
	}

	cpFloat cpGearJoint::Phase::get()
	{
		return cpGearJointGetPhase(_handle);
	}
		
	void cpGearJoint::Phase::set(cpFloat value)
	{
		cpGearJointSetPhase(_handle, value);
	}

	cpFloat cpGearJoint::Ratio::get()
	{
		return cpGearJointGetRatio(_handle);
	}

	void cpGearJoint::Ratio::set(cpFloat value)
	{
		cpGearJointSetRatio(_handle, value);
	}
}