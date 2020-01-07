#include "cpCircleShape.h"
#include "cpVect.h"
#include "cpBody.h"
#include "chipmunk/chipmunk_unsafe.h"

namespace ChipmunkCppCli
{
	generic<class T> where T : cpCircleShape, gcnew()
		/*static*/ T cpCircleShape::Alloc()
	{
		T shape = gcnew T();
		shape->_handle = (::cpShape*)cpCircleShapeAlloc();
		return shape;
	}

	/*static*/ cpCircleShape^ cpCircleShape::Alloc()
	{
		return Alloc<cpCircleShape^>();
	}

	generic<class T> where T : cpCircleShape, gcnew()
	/*static*/ T cpCircleShape::New(cpBody^ body, cpFloat radius, cpVect offset)
	{
		T shape = gcnew T();
		shape->_handle = (OGcpShape*)cpCircleShapeNew(body->_handle, radius, offset);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpCircleShape, gcnew()
	/*static*/ T cpCircleShape::New(cpBody^ body, cpFloat radius)
	{
		T shape = gcnew T();
		shape->_handle = (OGcpShape*)cpCircleShapeNew(body->_handle, radius, cpvzero);
		shape->SetUserData();
		return shape;
	}

	/*static*/ cpCircleShape^ cpCircleShape::New(cpBody^ body, cpFloat radius, cpVect offset)
	{
		return New<cpCircleShape^>(body, radius, offset);
	}

	/*static*/ cpCircleShape^ cpCircleShape::New(cpBody^ body, cpFloat radius)
	{
		return New<cpCircleShape^>(body, radius);
	}

	void cpCircleShape::Init(cpBody^ body, cpFloat radius, cpVect offset)
	{
		cpCircleShapeInit((OGcpCircleShape*)_handle, body->_handle, radius, offset);
		SetUserData();
	}

	void cpCircleShape::Init(cpBody^ body, cpFloat radius)
	{
		cpCircleShapeInit((OGcpCircleShape*)_handle, body->_handle, radius, cpvzero);
		SetUserData();
	}

	cpFloat cpCircleShape::Radius::get()
	{
		return cpCircleShapeGetRadius(_handle);
	}

	void cpCircleShape::Radius::set(cpFloat value)
	{
		cpCircleShapeSetRadius(_handle, value);
	}

	cpVect cpCircleShape::Offset::get()
	{
		return cpCircleShapeGetOffset(_handle);
	}

	void cpCircleShape::Offset::set(cpVect value)
	{
		cpCircleShapeSetOffset(_handle, value);
	}
}