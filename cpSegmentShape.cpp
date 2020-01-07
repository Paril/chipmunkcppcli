#include "cpSegmentShape.h"
#include "cpVect.h"
#include "cpBody.h"
#include "chipmunk/chipmunk_unsafe.h"

namespace ChipmunkCppCli
{
	generic<class T> where T : cpSegmentShape, gcnew()
	/*static*/ T cpSegmentShape::Alloc()
	{
		T shape = gcnew T();
		shape->_handle = (::cpShape*)cpSegmentShapeAlloc();
		return shape;
	}

	/*static*/ cpSegmentShape^ cpSegmentShape::Alloc()
	{
		return Alloc<cpSegmentShape^>();
	}

	generic<class T> where T : cpSegmentShape, gcnew()
	/*static*/ T cpSegmentShape::New(cpBody^ body, cpVect a, cpVect b, cpFloat radius)
	{
		T shape = gcnew T();
		shape->_handle = (OGcpShape*)cpSegmentShapeNew(body->_handle, a, b, radius);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpSegmentShape, gcnew()
	/*static*/ T cpSegmentShape::New(cpBody^ body, cpVect a, cpVect b)
	{
		T shape = gcnew T();
		shape->_handle = (OGcpShape*)cpSegmentShapeNew(body->_handle, a, b, 0);
		shape->SetUserData();
		return shape;
	}

	/*static*/ cpSegmentShape^ cpSegmentShape::New(cpBody^ body, cpVect a, cpVect b, cpFloat radius)
	{
		return New<cpSegmentShape^>(body, a, b, radius);
	}

	/*static*/ cpSegmentShape^ cpSegmentShape::New(cpBody^ body, cpVect a, cpVect b)
	{
		return New<cpSegmentShape^>(body, a, b);
	}

	void cpSegmentShape::Init(cpBody^ body, cpVect a, cpVect b, cpFloat radius)
	{
		cpSegmentShapeInit((OGcpSegmentShape*)_handle, body->_handle, a, b, radius);
		SetUserData();
	}

	void cpSegmentShape::Init(cpBody^ body, cpVect a, cpVect b)
	{
		cpSegmentShapeInit((OGcpSegmentShape*)_handle, body->_handle, a, b, 0);
		SetUserData();
	}

	void cpSegmentShape::SetNeighbors(cpVect prev, cpVect next)
	{
		cpSegmentShapeSetNeighbors(_handle, prev, next);
	}

	cpVect cpSegmentShape::A::get()
	{
		return cpSegmentShapeGetA(_handle);
	}

	void cpSegmentShape::A::set(cpVect value)
	{
		cpSegmentShapeSetEndpoints(_handle, value, B);
	}

	cpVect cpSegmentShape::B::get()
	{
		return cpSegmentShapeGetB(_handle);
	}

	void cpSegmentShape::B::set(cpVect value)
	{
		cpSegmentShapeSetEndpoints(_handle, A, value);
	}

	cpVect cpSegmentShape::Normal::get()
	{
		return cpSegmentShapeGetNormal(_handle);
	}

	cpFloat cpSegmentShape::Radius::get()
	{
		return cpSegmentShapeGetRadius(_handle);
	}

	void cpSegmentShape::Radius::set(cpFloat value)
	{
		cpSegmentShapeSetRadius(_handle, value);
	}
}