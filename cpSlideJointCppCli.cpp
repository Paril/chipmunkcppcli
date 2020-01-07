#include "cpSlideJoint.h"
#include "cpVect.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpSlideJoint, gcnew()
	/*static*/ T cpSlideJoint::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpSlideJointAlloc();
		return ret;
	}

	/*static*/ cpSlideJoint^ cpSlideJoint::Alloc() { return Alloc<cpSlideJoint^>(); }

	generic<typename T> where T : cpSlideJoint, gcnew()
	/*static*/ T cpSlideJoint::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpSlideJointNew(a->_handle, b->_handle, anchorA, anchorB, min, max);
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpSlideJoint^ cpSlideJoint::New(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max)
	{
		return New<cpSlideJoint^>(a, b, anchorA, anchorB, min, max);
	}

	cpSlideJoint^ cpSlideJoint::Init(cpBody^ a, cpBody^ b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max)
	{
		cpSlideJointInit((::cpSlideJoint*)_handle, a->_handle, b->_handle, anchorA, anchorB, min, max);
		SetUserData();
		return this;
	}

	cpVect cpSlideJoint::AnchorA::get()
	{
		return cpSlideJointGetAnchorA(_handle);
	}

	void cpSlideJoint::AnchorA::set(cpVect value)
	{
		cpSlideJointSetAnchorA(_handle, value);
	}

	cpVect cpSlideJoint::AnchorB::get()
	{
		return cpSlideJointGetAnchorB(_handle);
	}

	void cpSlideJoint::AnchorB::set(cpVect value)
	{
		cpSlideJointSetAnchorB(_handle, value);
	}

	cpFloat cpSlideJoint::Min::get()
	{
		return cpSlideJointGetMin(_handle);
	}

	void cpSlideJoint::Min::set(cpFloat value)
	{
		cpSlideJointSetMin(_handle, value);
	}

	cpFloat cpSlideJoint::Max::get()
	{
		return cpSlideJointGetMax(_handle);
	}

	void cpSlideJoint::Max::set(cpFloat value)
	{
		cpSlideJointSetMax(_handle, value);
	}
}