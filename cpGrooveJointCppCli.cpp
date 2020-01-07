#include "cpGrooveJoint.h"
#include "cpVect.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpGrooveJoint, gcnew()
	/*static*/ T cpGrooveJoint::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpGrooveJointAlloc();
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpGrooveJoint^ cpGrooveJoint::Alloc()
	{
		return Alloc<cpGrooveJoint^>();
	}

	generic<typename T> where T : cpGrooveJoint, gcnew()
	/*static*/ T cpGrooveJoint::New(cpBody^ a, cpBody^ b, cpVect groove_a, cpVect groove_b, cpVect anchorB)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpGrooveJointNew(a->_handle, b->_handle, groove_a, groove_b, anchorB);
		return ret;
	}

	/*static*/ cpGrooveJoint^ cpGrooveJoint::New(cpBody^ a, cpBody^ b, cpVect groove_a, cpVect groove_b, cpVect anchorB)
	{
		return New<cpGrooveJoint^>(a, b, groove_a, groove_b, anchorB);
	}

	cpGrooveJoint^ cpGrooveJoint::Init(cpBody^ a, cpBody^ b, cpVect groove_a, cpVect groove_b, cpVect anchorB)
	{
		cpGrooveJointInit((::cpGrooveJoint*)_handle, a->_handle, b->_handle, groove_a, groove_b, anchorB);
		SetUserData();
		return this;
	}

	cpVect cpGrooveJoint::GrooveA::get()
	{
		return cpGrooveJointGetGrooveA(_handle);
	}

	void cpGrooveJoint::GrooveA::set(cpVect value)
	{
		cpGrooveJointSetGrooveA(_handle, value);
	}

	cpVect cpGrooveJoint::GrooveB::get()
	{
		return cpGrooveJointGetGrooveB(_handle);
	}

	void cpGrooveJoint::GrooveB::set(cpVect value)
	{
		cpGrooveJointSetGrooveB(_handle, value);
	}

	cpVect cpGrooveJoint::AnchorB::get()
	{
		return cpGrooveJointGetAnchorB(_handle);
	}

	void cpGrooveJoint::AnchorB::set(cpVect value)
	{
		cpGrooveJointSetAnchorB(_handle, value);
	}
}