#include "cpSpace.h"
#include "cpConstraint.h"
#include "cpShape.h"
#include "cpBody.h"
#include "cpShapeFilter.h"
#include "cpPointQueryInfo.h"
#include "cpSegmentQueryInfo.h"
#include "cpVect.h"
#include "cpBB.h"
#include "cpContactPointSet.h"
#include "cpCollisionHandler.h"
#include "cpSpaceDebugDrawOptions.h"

namespace ChipmunkCppCli
{
	void cpSpace::SetUserData()
	{
		_gc = GCHandle::Alloc(this);
		cpSpaceSetUserData(_handle, GCHandle::ToIntPtr(_gc).ToPointer());
		_initialized = true;
	}

	void cpSpace::UnsetUserData()
	{
		cpSpaceSetUserData(_handle, nullptr);
		if (_gc.IsAllocated)
			_gc.Free();
		_initialized = false;
		_staticBody = nullptr;
	}

	/*static*/ cpSpace^ cpSpace::FromHandle(OGcpSpace* handle)
	{
		return (cpSpace^)GCHandle::FromIntPtr((IntPtr)cpSpaceGetUserData(handle)).Target;
	}

	cpSpace::~cpSpace()
	{
		this->!cpSpace();
	}

	cpSpace::!cpSpace()
	{
		Free();
	}

	static void ReleaseBodyHandle(cpBody^ body)
	{
		body->UnsetUserData();
	}

	static void ReleaseConstraintHandle(cpConstraint^ constraint)
	{
		constraint->UnsetUserData();
	}

	static void ReleaseShapeHandle(cpShape^ shape)
	{
		shape->UnsetUserData();
	}

	void cpSpace::ReleaseHandles()
	{
		EachBody(gcnew cpSpaceBodyIteratorFunc(ReleaseBodyHandle));
		
		EachConstraint(gcnew cpSpaceConstraintIteratorFunc(ReleaseConstraintHandle));
		
		EachShape(gcnew cpSpaceShapeIteratorFunc(ReleaseShapeHandle));

		_collisionHandlers->Clear();
	}

	generic<class T> where T : cpSpace, gcnew()
	/*static*/ T cpSpace::Alloc()
	{
		T space = gcnew T();
		space->_handle = cpSpaceAlloc();
		return space;
	}

	/*static*/ cpSpace^ cpSpace::Alloc()
	{
		return Alloc<cpSpace^>();
	}

	generic<class T> where T : cpSpace, gcnew()
	/*static*/ T cpSpace::New()
	{
		T space = gcnew T();
		space->_handle = cpSpaceNew();
		space->SetUserData();
		return space;
	}

	/*static*/ cpSpace^ cpSpace::New()
	{
		return New<cpSpace^>();
	}

	cpSpace^ cpSpace::Init()
	{
		cpSpaceInit(_handle);
		SetUserData();
		return this;
	}

	void cpSpace::Destroy()
	{
		if (!_initialized)
			throw gcnew InvalidOperationException("A cpSpace must be initialized before it can be destroyed.");

		ReleaseHandles();
		UnsetUserData();
		cpSpaceDestroy(_handle);
	}

	void cpSpace::Free()
	{
		if (!_handle)
			throw gcnew InvalidOperationException("cpSpace::Free called with an already-freed space");
		else if (!_initialized)
			throw gcnew InvalidOperationException("A cpSpace must be initialized before it can be destroyed.");

		ReleaseHandles();
		UnsetUserData();
		cpSpaceFree(_handle);
		_handle = nullptr;
		GC::SuppressFinalize(this);
	}

	int cpSpace::Iterations::get()
	{
		return cpSpaceGetIterations(_handle);
	}

	void cpSpace::Iterations::set(int value)
	{
		cpSpaceSetIterations(_handle, value);
	}

	cpVect cpSpace::Gravity::get()
	{
		return cpSpaceGetGravity(_handle);
	}

	void cpSpace::Gravity::set(cpVect value)
	{
		cpSpaceSetGravity(_handle, value);
	}

	cpFloat cpSpace::Damping::get()
	{
		return cpSpaceGetDamping(_handle);
	}

	void cpSpace::Damping::set(cpFloat value)
	{
		cpSpaceSetDamping(_handle, value);
	}

	cpFloat cpSpace::IdleSpeedThreshold::get()
	{
		return cpSpaceGetIdleSpeedThreshold(_handle);
	}

	void cpSpace::IdleSpeedThreshold::set(cpFloat value)
	{
		cpSpaceSetIdleSpeedThreshold(_handle, value);
	}

	cpFloat cpSpace::SleepTimeThreshold::get()
	{
		return cpSpaceGetSleepTimeThreshold(_handle);
	}

	void cpSpace::SleepTimeThreshold::set(cpFloat value)
	{
		cpSpaceSetSleepTimeThreshold(_handle, value);
	}

	cpFloat cpSpace::CollisionSlop::get()
	{
		return cpSpaceGetCollisionSlop(_handle);
	}

	void cpSpace::CollisionSlop::set(cpFloat value)
	{
		cpSpaceSetCollisionSlop(_handle, value);
	}

	cpFloat cpSpace::CollisionBias::get()
	{
		return cpSpaceGetCollisionBias(_handle);
	}

	void cpSpace::CollisionBias::set(cpFloat value)
	{
		cpSpaceSetCollisionBias(_handle, value);
	}

	cpTimestamp cpSpace::CollisionPersistence::get()
	{
		return cpSpaceGetCollisionPersistence(_handle);
	}

	void cpSpace::CollisionPersistence::set(cpTimestamp value)
	{
		cpSpaceSetCollisionPersistence(_handle, value);
	}

	cpBody^ cpSpace::StaticBody::get()
	{
		if (_staticBody)
			return _staticBody;

		auto body_ptr = cpSpaceGetStaticBody(_handle);
		_staticBody = gcnew cpBody();
		_staticBody->_handle = body_ptr;
		return _staticBody;
	}

	cpFloat cpSpace::CurrentTimeStep::get()
	{
		return cpSpaceGetCurrentTimeStep(_handle);
	}

	bool cpSpace::IsLocked::get()
	{
		return cpSpaceIsLocked(_handle);
	}

	cpCollisionHandler^ cpSpace::GetOrAdd(::cpCollisionHandler* handle)
	{
		cpCollisionHandler^ handler;

		if (_collisionHandlers->TryGetValue((IntPtr)handle, handler))
			return handler;

		handler = gcnew cpCollisionHandler(handle);
		_collisionHandlers->Add((IntPtr)handle, handler);
		return handler;
	}

	cpCollisionHandler^ cpSpace::AddDefaultCollisionHandler()
	{
		return GetOrAdd(cpSpaceAddDefaultCollisionHandler(_handle));
	}

	cpCollisionHandler^ cpSpace::AddCollisionHandler(cpCollisionType a, cpCollisionType b)
	{
		return GetOrAdd(cpSpaceAddCollisionHandler(_handle, a, b));
	}

	cpCollisionHandler^ cpSpace::AddWildcardHandler(cpCollisionType type)
	{
		return GetOrAdd(cpSpaceAddWildcardHandler(_handle, type));
	}

	cpShape^ cpSpace::AddShape(cpShape^ shape)
	{
		cpSpaceAddShape(_handle, shape->_handle);
		return shape;
	}

	cpBody^ cpSpace::AddBody(cpBody^ body)
	{
		cpSpaceAddBody(_handle, body->_handle);
		return body;
	}

	cpConstraint^ cpSpace::AddConstraint(cpConstraint^ constraint)
	{
		cpSpaceAddConstraint(_handle, constraint->_handle);
		return constraint;
	}

	void cpSpace::RemoveShape(cpShape^ shape)
	{
		cpSpaceRemoveShape(_handle, shape->_handle);
	}

	void cpSpace::RemoveBody(cpBody^ body)
	{
		cpSpaceRemoveBody(_handle, body->_handle);
	}

	void cpSpace::RemoveConstraint(cpConstraint^ constraint)
	{
		cpSpaceRemoveConstraint(_handle, constraint->_handle);
	}

	bool cpSpace::ContainsShape(cpShape^ shape)
	{
		return cpSpaceContainsShape(_handle, shape->_handle);
	}

	bool cpSpace::ContainsBody(cpBody^ body)
	{
		return cpSpaceContainsBody(_handle, body->_handle);
	}

	bool cpSpace::ContainsConstraint(cpConstraint^ constraint)
	{
		return cpSpaceContainsConstraint(_handle, constraint->_handle);
	}

	static void cpPostStepFunc_wrap(OGcpSpace* space, void* key, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpPostStepFunc^)handle.Target;
		func_ptr(cpSpace::FromHandle(space), IntPtr(key));
		handle.Free();
	}

	bool cpSpace::AddPostStepCallback(cpPostStepFunc^ func, IntPtr key)
	{
		IntPtr data = IntPtr::Zero;
		::cpPostStepFunc cb = nullptr;

		if (func)
		{
			data = GCHandle::ToIntPtr(GCHandle::Alloc(func));
			cb = cpPostStepFunc_wrap;
		}

		return cpSpaceAddPostStepCallback(_handle, cb, key.ToPointer(), data.ToPointer());
	}

	static void PointQueryFunc_wrap(::cpShape* shape, ::cpVect point, cpFloat distance, ::cpVect gradient, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpSpacePointQueryFunc^)handle.Target;
		func_ptr(cpShape::FromHandle(shape), point, distance, gradient);
	}

	void cpSpace::PointQuery(cpVect point, cpFloat maxDistance, cpShapeFilter filter, cpSpacePointQueryFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpSpacePointQuery(_handle, point, maxDistance, filter, PointQueryFunc_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	cpShape^ cpSpace::PointQueryNearest(cpVect point, cpFloat maxDistance, cpShapeFilter filter, [Out] cpPointQueryInfo% out)
	{
		OGcpPointQueryInfo info;
		auto shape = cpShape::FromHandle(cpSpacePointQueryNearest(_handle, point, maxDistance, filter, &info));
		out.shape = cpShape::FromHandle((OGcpShape*)info.shape);
		out.point = info.point;
		out.gradient = info.gradient;
		out.distance = info.distance;
		return shape;
	}

	cpShape^ cpSpace::PointQueryNearest(cpVect point, cpFloat maxDistance, cpShapeFilter filter)
	{
		return cpShape::FromHandle(cpSpacePointQueryNearest(_handle, point, maxDistance, filter, nullptr));
	}

	static void SegmentQueryFunc_wrap(::cpShape* shape, ::cpVect point, ::cpVect normal, cpFloat alpha, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpSpaceSegmentQueryFunc^)handle.Target;
		func_ptr(cpShape::FromHandle(shape), point, normal, alpha);
	}

	void cpSpace::SegmentQuery(cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter, cpSpaceSegmentQueryFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpSpaceSegmentQuery(_handle, start, end, radius, filter, SegmentQueryFunc_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	cpShape^ cpSpace::SegmentQueryFirst(cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter, [Out] cpSegmentQueryInfo% out)
	{
		OGcpSegmentQueryInfo info;
		auto shape = cpShape::FromHandle(cpSpaceSegmentQueryFirst(_handle, start, end, radius, filter, &info));
		out.shape = cpShape::FromHandle((OGcpShape*)info.shape);
		out.point = info.point;
		out.normal = info.normal;
		out.alpha = info.alpha;
		return shape;
	}

	cpShape^ cpSpace::SegmentQueryFirst(cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter)
	{
		return cpShape::FromHandle(cpSpaceSegmentQueryFirst(_handle, start, end, radius, filter, nullptr));
	}

	static void BBQuery_wrap(::cpShape* shape, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpSpaceBBQueryFunc^)handle.Target;
		func_ptr(cpShape::FromHandle(shape));
	}

	void cpSpace::BBQuery(cpBB bb, cpShapeFilter filter, cpSpaceBBQueryFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpSpaceBBQuery(_handle, bb, filter, BBQuery_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	static void ShapeQuery_wrap(::cpShape* shape, ::cpContactPointSet* points, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpSpaceShapeQueryFunc^)handle.Target;
		func_ptr(cpShape::FromHandle(shape), *points);
	}

	bool cpSpace::ShapeQuery(cpShape^ shape, cpSpaceShapeQueryFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		auto ret = cpSpaceShapeQuery(_handle, shape->_handle, ShapeQuery_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
		return ret;
	}

	static void EachBody_wrap(OGcpBody* body, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpSpaceBodyIteratorFunc^)handle.Target;
		func_ptr(cpBody::FromHandle(body));
	}

	void cpSpace::EachBody(cpSpaceBodyIteratorFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpSpaceEachBody(_handle, EachBody_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	static void EachShape_wrap(::cpShape* shape, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpSpaceShapeIteratorFunc^)handle.Target;
		func_ptr(cpShape::FromHandle(shape));
	}

	void cpSpace::EachShape(cpSpaceShapeIteratorFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpSpaceEachShape(_handle, EachShape_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	static void EachConstraint_wrap(::cpConstraint* constraint, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpSpaceConstraintIteratorFunc^)handle.Target;
		func_ptr(cpConstraint::FromHandle(constraint));
	}

	void cpSpace::EachConstraint(cpSpaceConstraintIteratorFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpSpaceEachConstraint(_handle, EachConstraint_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	void cpSpace::ReindexStatic()
	{
		cpSpaceReindexStatic(_handle);
	}

	void cpSpace::ReindexShape(cpShape^ shape)
	{
		cpSpaceReindexShape(_handle, shape->_handle);
	}

	void cpSpace::ReindexShapesForBody(cpBody^ body)
	{
		cpSpaceReindexShapesForBody(_handle, body->_handle);
	}

	void cpSpace::UseSpatialHash(cpFloat dim, int count)
	{
		cpSpaceUseSpatialHash(_handle, dim, count);
	}

	void cpSpace::Step(cpFloat dt)
	{
		cpSpaceStep(_handle, dt);
	}

	static void cpSpaceDebugDrawCircle_wrapper(OGcpVect pos, cpFloat angle, cpFloat radius, OGcpSpaceDebugColor outlineColor, ::cpSpaceDebugColor fillColor, cpDataPointer data)
	{
		auto options = (cpSpaceDebugDrawOptions^)GCHandle::FromIntPtr((IntPtr)data).Target;
		options->DrawCircle(pos, angle, radius, outlineColor, fillColor);
	}

	static void cpSpaceDebugDrawSegment_wrapper(OGcpVect a, OGcpVect b, OGcpSpaceDebugColor color, cpDataPointer data)
	{
		auto options = (cpSpaceDebugDrawOptions^)GCHandle::FromIntPtr((IntPtr)data).Target;
		options->DrawSegment(a, b, color);
	}

	static void cpSpaceDebugDrawFatSegment_wrapper(OGcpVect a, OGcpVect b, cpFloat radius, OGcpSpaceDebugColor outlineColor, OGcpSpaceDebugColor fillColor, cpDataPointer data)
	{
		auto options = (cpSpaceDebugDrawOptions^)GCHandle::FromIntPtr((IntPtr)data).Target;
		options->DrawFatSegment(a, b, radius, outlineColor, fillColor);
	}

	static void cpSpaceDebugDrawPolygon_wrapper(int count, const OGcpVect* verts, cpFloat radius, OGcpSpaceDebugColor outlineColor, OGcpSpaceDebugColor fillColor, cpDataPointer data)
	{
		auto options = (cpSpaceDebugDrawOptions^)GCHandle::FromIntPtr((IntPtr)data).Target;
		options->DrawPolygon(ReadOnlySpan<cpVect>((void*)verts, count), radius, outlineColor, fillColor);
	}

	static void cpSpaceDebugDrawDot_wrapper(cpFloat size, OGcpVect pos, OGcpSpaceDebugColor color, cpDataPointer data)
	{
		auto options = (cpSpaceDebugDrawOptions^)GCHandle::FromIntPtr((IntPtr)data).Target;
		options->DrawDot(size, pos, color);
	}

	static ::cpSpaceDebugColor cpSpaceDebugColorForShape_wrapper(OGcpShape* shape, cpDataPointer data)
	{
		auto options = (cpSpaceDebugDrawOptions^)GCHandle::FromIntPtr((IntPtr)data).Target;
		return options->ColorForShape(cpShape::FromHandle(shape));
	}

	void cpSpace::DebugDraw(cpSpaceDebugDrawOptions^ options)
	{
		OGcpSpaceDebugDrawOptions opts;
		opts.flags = (::cpSpaceDebugDrawFlags)options->Flags;
		opts.shapeOutlineColor = *(::cpSpaceDebugColor*)&options->ShapeOutlineColor;
		opts.constraintColor = *(::cpSpaceDebugColor*)&options->ConstraintColor;
		opts.collisionPointColor = *(::cpSpaceDebugColor*)&options->CollisionPointColor;
		opts.drawCircle = cpSpaceDebugDrawCircle_wrapper;
		opts.drawSegment = cpSpaceDebugDrawSegment_wrapper;
		opts.drawFatSegment = cpSpaceDebugDrawFatSegment_wrapper;
		opts.drawPolygon = cpSpaceDebugDrawPolygon_wrapper;
		opts.drawDot = cpSpaceDebugDrawDot_wrapper;
		opts.colorForShape = cpSpaceDebugColorForShape_wrapper;

		auto options_handle = GCHandle::Alloc(options);
		opts.data = GCHandle::ToIntPtr(options_handle).ToPointer();
		cpSpaceDebugDraw(_handle, &opts);
		options_handle.Free();
	}
}