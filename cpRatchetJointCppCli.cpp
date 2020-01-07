#include "cpRatchetJoint.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpRatchetJoint, gcnew()
	/*static*/ T cpRatchetJoint::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpRatchetJointAlloc();
		return ret;
	}

	/*static*/ cpRatchetJoint^ cpRatchetJoint::Alloc()
	{
		return Alloc<cpRatchetJoint^>();
	}

	generic<typename T> where T : cpRatchetJoint, gcnew()
	/*static*/ T cpRatchetJoint::New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratchet)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpRatchetJointNew(a->_handle, b->_handle, phase, ratchet);
		ret->SetUserData();
		return ret;
	}
	
	/*static*/ cpRatchetJoint^ cpRatchetJoint::New(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratchet)
	{
		return New<cpRatchetJoint^>(a, b, phase, ratchet);
	}

	cpRatchetJoint^ cpRatchetJoint::Init(cpBody^ a, cpBody^ b, cpFloat phase, cpFloat ratchet)
	{
		cpRatchetJointInit((::cpRatchetJoint*)_handle, a->_handle, b->_handle, phase, ratchet);
		SetUserData();
		return this;
	}

	cpFloat cpRatchetJoint::Angle::get()
	{
		return cpRatchetJointGetAngle(_handle);
	}
	
	void cpRatchetJoint::Angle::set(cpFloat value)
	{
		cpRatchetJointSetAngle(_handle, value);
	}

	cpFloat cpRatchetJoint::Ratchet::get()
	{
		return cpRatchetJointGetPhase(_handle);
	}
	
	void cpRatchetJoint::Ratchet::set(cpFloat value)
	{
		cpRatchetJointSetPhase(_handle, value);
	}

	cpFloat cpRatchetJoint::Phase::get()
	{
		return cpRatchetJointGetRatchet(_handle);
	}
	
	void cpRatchetJoint::Phase::set(cpFloat value)
	{
		cpRatchetJointSetRatchet(_handle, value);
	}
}