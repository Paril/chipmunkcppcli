#include "cpPinJoint.h"
#include "cpVect.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpPinJoint, gcnew()
	/*static*/ T cpPinJoint::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpPinJointAlloc();
		return ret;
	}

	/*static*/ cpPinJoint^ cpPinJoint::Alloc()
	{
		return Alloc<cpPinJoint^>();
	}

	generic<typename T> where T : cpPinJoint, gcnew()
	/*static*/ T cpPinJoint::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpPinJointNew(a->_handle, b->_handle, anchorA, anchorB);
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpPinJoint^ cpPinJoint::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB)
	{
		return New<cpPinJoint^>(a, b, anchorA, anchorB);
	}

	cpPinJoint^ cpPinJoint::Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB)
	{
		cpPinJointInit((::cpPinJoint*)_handle, a->_handle, b->_handle, anchorA, anchorB);
		SetUserData();
		return this;
	}

	cpVect cpPinJoint::AnchorA::get()
	{
		return cpPinJointGetAnchorA(_handle);
	}

	void cpPinJoint::AnchorA::set(cpVect value)
	{
		cpPinJointSetAnchorA(_handle, value);
	}

	cpVect cpPinJoint::AnchorB::get()
	{
		return cpPinJointGetAnchorB(_handle);
	}

	void cpPinJoint::AnchorB::set(cpVect value)
	{
		cpPinJointSetAnchorB(_handle, value);
	}

	cpFloat cpPinJoint::Dist::get()
	{
		return cpPinJointGetDist(_handle);
	}

	void cpPinJoint::Dist::set(cpFloat value)
	{
		cpPinJointSetDist(_handle, value);
	}
}