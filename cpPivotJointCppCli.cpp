#include "cpPivotJoint.h"
#include "cpVect.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpPivotJoint, gcnew()
	/*static*/ T cpPivotJoint::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpPivotJointAlloc();
		return ret;
	}

	/*static*/ cpPivotJoint^ cpPivotJoint::Alloc() { return Alloc<cpPivotJoint^>(); }

	generic<typename T> where T : cpPivotJoint, gcnew()
	/*static*/ T cpPivotJoint::New(cpBody^ a, cpBody^ b, cpVect pivot)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpPivotJointNew(a->_handle, b->_handle, pivot);
		ret->SetUserData();
		return ret;
	}

	generic<typename T> where T : cpPivotJoint, gcnew()
	/*static*/ T cpPivotJoint::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpPivotJointNew2(a->_handle, b->_handle, anchorA, anchorB);
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpPivotJoint^ cpPivotJoint::New(cpBody^ a, cpBody^ b, cpVect pivot)
	{
		return New<cpPivotJoint^>(a, b, pivot);
	}

	/*static*/ cpPivotJoint^ cpPivotJoint::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB)
	{
		return New<cpPivotJoint^>(a, b, anchorA, anchorB);
	}

	cpPivotJoint^ cpPivotJoint::Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB)
	{
		cpPivotJointInit((::cpPivotJoint*)_handle, a->_handle, b->_handle, anchorA, anchorB);
		SetUserData();
		return this;
	}

	cpVect cpPivotJoint::AnchorA::get()
	{
		return cpPivotJointGetAnchorA(_handle);
	}

	void cpPivotJoint::AnchorA::set(cpVect value)
	{
		cpPivotJointSetAnchorA(_handle, value);
	}

	cpVect cpPivotJoint::AnchorB::get()
	{
		return cpPivotJointGetAnchorB(_handle);
	}

	void cpPivotJoint::AnchorB::set(cpVect value)
	{
		cpPivotJointSetAnchorB(_handle, value);
	}
}