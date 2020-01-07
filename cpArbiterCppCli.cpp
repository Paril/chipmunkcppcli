#include "cpArbiter.h"
#include "cpVect.h"
#include "cpShape.h"
#include "cpSpace.h"
#include "cpBody.h"
#include "cpContactPointSet.h"

namespace ChipmunkCppCli
{
	cpArbiter::cpArbiter(OGcpArbiter* handle) :
		_handle(handle)
	{
	}

	cpFloat cpArbiter::Restitution::get()
	{
		return cpArbiterGetRestitution(_handle);
	}

	void cpArbiter::Restitution::set(cpFloat value)
	{
		cpArbiterSetRestitution(_handle, value);
	}

	cpFloat cpArbiter::Friction::get()
	{
		return cpArbiterGetFriction(_handle);
	}

	void cpArbiter::Friction::set(cpFloat value)
	{
		cpArbiterSetFriction(_handle, value);
	}

	cpVect cpArbiter::SurfaceVelocity::get()
	{
		return cpArbiterGetSurfaceVelocity(_handle);
	}

	void cpArbiter::SurfaceVelocity::set(cpVect value)
	{
		cpArbiterSetSurfaceVelocity(_handle, value);
	}

	cpVect cpArbiter::TotalImpulse::get()
	{
		return cpArbiterTotalImpulse(_handle);
	}
	
	cpFloat cpArbiter::TotalKE::get()
	{
		return cpArbiterTotalKE(_handle);
	}

	bool cpArbiter::Ignore()
	{
		return cpArbiterIgnore(_handle);
	}

	generic<typename T1, typename T2> where T1 : cpShape where T2 : cpShape
	void cpArbiter::GetShapes([Out] T1% a, [Out] T2% b)
	{
		OGcpShape* _a, * _b;
		cpArbiterGetShapes(_handle, &_a, &_b);
		a = (T1)cpShape::FromHandle(_a);
		b = (T2)cpShape::FromHandle(_b);
	}

	void cpArbiter::GetShapes([Out] cpShape^% a, [Out] cpShape^% b)
	{
		return GetShapes<cpShape^, cpShape^>(a, b);
	}

	generic<typename T1, typename T2> where T1 : cpBody where T2 : cpBody
	void cpArbiter::GetBodies([Out] T1% a, [Out] T2% b)
	{
		OGcpBody* _a, * _b;
		cpArbiterGetBodies(_handle, &_a, &_b);
		a = (T1)cpBody::FromHandle(_a);
		b = (T2)cpBody::FromHandle(_b);
	}

	void cpArbiter::GetBodies([Out] cpBody^% a, [Out] cpBody^% b)
	{
		return GetBodies<cpBody^, cpBody^>(a, b);
	}

	cpContactPointSet cpArbiter::ContactPointSet::get()
	{
		return cpArbiterGetContactPointSet(_handle);
	}

	void cpArbiter::ContactPointSet::set(cpContactPointSet value)
	{
		OGcpContactPointSet set = value;
		cpArbiterSetContactPointSet(_handle, &set);
	}

	bool cpArbiter::IsFirstContact::get()
	{
		return cpArbiterIsFirstContact(_handle);
	}

	bool cpArbiter::IsRemoval::get()
	{
		return cpArbiterIsRemoval(_handle);
	}

	int cpArbiter::Count::get()
	{
		return cpArbiterGetCount(_handle);
	}

	cpVect cpArbiter::Normal::get()
	{
		return cpArbiterGetNormal(_handle);
	}

	cpVect cpArbiter::GetPointA(int i)
	{
		return cpArbiterGetPointA(_handle, i);
	}

	cpVect cpArbiter::GetPointB(int i)
	{
		return cpArbiterGetPointB(_handle, i);
	}

	cpFloat cpArbiter::GetDepth(int i)
	{
		return cpArbiterGetDepth(_handle, i);
	}

	bool cpArbiter::CallWildcardBeginA(cpSpace^ space)
	{
		return cpArbiterCallWildcardBeginA(_handle, space->_handle);
	}

	bool cpArbiter::CallWildcardBeginB(cpSpace^ space)
	{
		return cpArbiterCallWildcardBeginB(_handle, space->_handle);
	}

	bool cpArbiter::CallWildcardPreSolveA(cpSpace^ space)
	{
		return cpArbiterCallWildcardPreSolveA(_handle, space->_handle);
	}

	bool cpArbiter::CallWildcardPreSolveB(cpSpace^ space)
	{
		return cpArbiterCallWildcardPreSolveB(_handle, space->_handle);
	}

	void cpArbiter::CallWildcardPostSolveA(cpSpace^ space)
	{
		return cpArbiterCallWildcardPostSolveA(_handle, space->_handle);
	}

	void cpArbiter::CallWildcardPostSolveB(cpSpace^ space)
	{
		return cpArbiterCallWildcardPostSolveB(_handle, space->_handle);
	}

	void cpArbiter::CallWildcardSeparateA(cpSpace^ space)
	{
		return cpArbiterCallWildcardSeparateA(_handle, space->_handle);
	}

	void cpArbiter::CallWildcardSeparateB(cpSpace^ space)
	{
		return cpArbiterCallWildcardSeparateB(_handle, space->_handle);
	}
}