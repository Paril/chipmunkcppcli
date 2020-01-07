#include "cpShape.h"
#include "cpVect.h"
#include "cpBB.h"
#include "cpTransform.h"
#include "cpPointQueryInfo.h"
#include "cpSegmentQueryInfo.h"
#include "cpContactPointSet.h"
#include "cpSpace.h"
#include "cpBody.h"
#include "cpShapeFilter.h"

namespace ChipmunkCppCli
{
	/*static*/ cpShape^ cpShape::FromHandle(OGcpShape* shape)
	{
		return (cpShape^)GCHandle::FromIntPtr((IntPtr)cpShapeGetUserData(shape)).Target;
	}

	void cpShape::SetUserData()
	{
		_gc = GCHandle::Alloc(this);
		cpShapeSetUserData(_handle, GCHandle::ToIntPtr(_gc).ToPointer());
	}

	void cpShape::UnsetUserData()
	{
		cpShapeSetUserData(_handle, nullptr);
		if (_gc.IsAllocated)
			_gc.Free();
	}

	void cpShape::Destroy()
	{
		UnsetUserData();
		cpShapeDestroy(_handle);
	}

	void cpShape::Free()
	{
		UnsetUserData();
		cpShapeFree(_handle);
		_handle = nullptr;
	}

	cpBB cpShape::CacheBB()
	{
		return cpShapeCacheBB(_handle);
	}

	cpBB cpShape::Update(cpTransform transform)
	{
		return cpShapeUpdate(_handle, transform);
	}

	cpFloat cpShape::PointQuery(cpVect p, [Out] cpPointQueryInfo% out)
	{
		OGcpPointQueryInfo info;
		auto ret = cpShapePointQuery(_handle, p, &info);
		out.shape = cpShape::FromHandle((OGcpShape*)info.shape);
		out.point = info.point;
		out.gradient = info.gradient;
		out.distance = info.distance;
		return ret;
	}

	cpFloat cpShape::PointQuery(cpVect p)
	{
		return cpShapePointQuery(_handle, p, nullptr);
	}
	
	bool cpShape::SegmentQuery(cpVect a, cpVect b, cpFloat radius, [Out] cpSegmentQueryInfo% out)
	{
		OGcpSegmentQueryInfo info;
		auto ret = cpShapeSegmentQuery(_handle, a, b, radius, &info);
		out.shape = cpShape::FromHandle((OGcpShape*)info.shape);
		out.point = info.point;
		out.normal = info.normal;
		out.alpha = info.alpha;
		return ret;
	}

	bool cpShape::SegmentQuery(cpVect a, cpVect b, cpFloat radius)
	{
		return cpShapeSegmentQuery(_handle, a, b, radius, nullptr);
	}
	
	cpContactPointSet cpShape::Collide(cpShape^ b)
	{
		return cpShapesCollide(_handle, b->_handle);
	}
	
	cpSpace^ cpShape::Space::get()
	{
		return cpSpace::FromHandle(cpShapeGetSpace(_handle));
	}
	
	cpBody^ cpShape::Body::get()
	{
		return cpBody::FromHandle(cpShapeGetBody(_handle));
	}
	
	void cpShape::Body::set(cpBody^ value)
	{
		cpShapeSetBody(_handle, value->_handle);
	}

	cpFloat cpShape::Mass::get()
	{
		return cpShapeGetMass(_handle);
	}
	
	void cpShape::Mass::set(cpFloat value)
	{
		cpShapeSetMass(_handle, value);
	}

	cpFloat cpShape::Density::get()
	{
		return cpShapeGetDensity(_handle);
	}

	void cpShape::Density::set(cpFloat value)
	{
		cpShapeSetDensity(_handle, value);
	}

	cpFloat cpShape::Moment::get()
	{
		return cpShapeGetMoment(_handle);
	}

	cpFloat cpShape::Area::get()
	{
		return cpShapeGetArea(_handle);
	}
	
	cpVect cpShape::CenterOfGravity::get()
	{
		return cpShapeGetCenterOfGravity(_handle);
	}
	
	cpBB cpShape::BB::get()
	{
		return cpShapeGetBB(_handle);
	}

	bool cpShape::Sensor::get()
	{
		return cpShapeGetSensor(_handle);
	}

	void cpShape::Sensor::set(bool value)
	{
		cpShapeSetSensor(_handle, value);
	}

	cpFloat cpShape::Elasticity::get()
	{
		return cpShapeGetElasticity(_handle);
	}

	void cpShape::Elasticity::set(cpFloat value)
	{
		cpShapeSetElasticity(_handle, value);
	}

	cpFloat cpShape::Friction::get()
	{
		return cpShapeGetFriction(_handle);
	}

	void cpShape::Friction::set(cpFloat value)
	{
		cpShapeSetFriction(_handle, value);
	}

	cpVect cpShape::SurfaceVelocity::get()
	{
		return cpShapeGetSurfaceVelocity(_handle);
	}
	
	void cpShape::SurfaceVelocity::set(cpVect value)
	{
		cpShapeSetSurfaceVelocity(_handle, value);
	}

	cpCollisionType cpShape::CollisionType::get()
	{
		return cpShapeGetCollisionType(_handle);
	}
	
	void cpShape::CollisionType::set(cpCollisionType value)
	{
		cpShapeSetCollisionType(_handle, value);
	}
	
	cpShapeFilter cpShape::Filter::get()
	{
		return cpShapeGetFilter(_handle);
	}
	
	void cpShape::Filter::set(cpShapeFilter value)
	{
		cpShapeSetFilter(_handle, value);
	}
}