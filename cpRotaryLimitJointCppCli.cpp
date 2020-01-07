#include "cpRotaryLimitJoint.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpRotaryLimitJoint, gcnew()
	/*static*/ T cpRotaryLimitJoint::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpRotaryLimitJointAlloc();
		return ret;
	}

	/*static*/ cpRotaryLimitJoint^ cpRotaryLimitJoint::Alloc()
	{
		return Alloc<cpRotaryLimitJoint^>();
	}

	generic<typename T> where T : cpRotaryLimitJoint, gcnew()
	/*static*/ T cpRotaryLimitJoint::New(cpBody^ a, cpBody^ b, cpFloat min, cpFloat max)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpRotaryLimitJointNew(a->_handle, b->_handle, min, max);
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpRotaryLimitJoint^ cpRotaryLimitJoint::New(cpBody^ a, cpBody^ b, cpFloat min, cpFloat max)
	{
		return New<cpRotaryLimitJoint^>(a, b, min, max);
	}

	cpRotaryLimitJoint^ cpRotaryLimitJoint::Init(cpBody^ a, cpBody^ b, cpFloat min, cpFloat max)
	{
		cpRotaryLimitJointInit((::cpRotaryLimitJoint*)_handle, a->_handle, b->_handle, min, max);
		SetUserData();
		return this;
	}

	cpFloat cpRotaryLimitJoint::Min::get()
	{
		return cpRotaryLimitJointGetMin(_handle);
	}
		
	void cpRotaryLimitJoint::Min::set(cpFloat value)
	{
		cpRotaryLimitJointSetMin(_handle, value);
	}

	cpFloat cpRotaryLimitJoint::Max::get()
	{
		return cpRotaryLimitJointGetMax(_handle);
	}
		
	void cpRotaryLimitJoint::Max::set(cpFloat value)
	{
		cpRotaryLimitJointSetMax(_handle, value);
	}
}