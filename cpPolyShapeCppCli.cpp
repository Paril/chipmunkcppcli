#include "cpPolyShape.h"
#include "cpVect.h"
#include "cpBody.h"
#include "cpBB.h"
#include "cpTransform.h"
#include "chipmunk/chipmunk_unsafe.h"

namespace ChipmunkCppCli
{
	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::Alloc()
	{
		T shape = gcnew T();
		shape->_handle = (::cpShape*)cpPolyShapeAlloc();
		return shape;
	}

	/*static*/ cpPolyShape^ cpPolyShape::Alloc()
	{
		return Alloc<cpPolyShape^>();
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform, cpFloat radius)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		T shape = gcnew T();
		shape->_handle = cpPolyShapeNew(body->_handle, verts.Length, verts_ptr, transform, radius);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		T shape = gcnew T();
		shape->_handle = cpPolyShapeNew(body->_handle, verts.Length, verts_ptr, transform, 0);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpFloat radius)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		T shape = gcnew T();
		shape->_handle = cpPolyShapeNewRaw(body->_handle, verts.Length, verts_ptr, radius);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		T shape = gcnew T();
		shape->_handle = cpPolyShapeNewRaw(body->_handle, verts.Length, verts_ptr, 0);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, cpFloat width, cpFloat height, cpFloat radius)
	{
		T shape = gcnew T();
		shape->_handle = cpBoxShapeNew(body->_handle, width, height, radius);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, cpFloat width, cpFloat height)
	{
		T shape = gcnew T();
		shape->_handle = cpBoxShapeNew(body->_handle, width, height, 0);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, cpBB box, cpFloat radius)
	{
		T shape = gcnew T();
		shape->_handle = cpBoxShapeNew2(body->_handle, box, radius);
		shape->SetUserData();
		return shape;
	}

	generic<class T> where T : cpPolyShape, gcnew()
	/*static*/ T cpPolyShape::New(cpBody^ body, cpBB box)
	{
		T shape = gcnew T();
		shape->_handle = cpBoxShapeNew2(body->_handle, box, 0);
		shape->SetUserData();
		return shape;
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform, cpFloat radius)
	{
		return New<cpPolyShape^>(body, verts, transform, radius);
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform)
	{
		return New<cpPolyShape^>(body, verts, transform);
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpFloat radius)
	{
		return New<cpPolyShape^>(body, verts, radius);
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, ReadOnlySpan<cpVect> verts)
	{
		return New<cpPolyShape^>(body, verts);
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, cpFloat width, cpFloat height, cpFloat radius)
	{
		return New<cpPolyShape^>(body, width, height, radius);
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, cpFloat width, cpFloat height)
	{
		return New<cpPolyShape^>(body, width, height);
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, cpBB box, cpFloat radius)
	{
		return New<cpPolyShape^>(body, box, radius);
	}

	/*static*/ cpPolyShape^ cpPolyShape::New(cpBody^ body, cpBB box)
	{
		return New<cpPolyShape^>(body, box);
	}

	void cpPolyShape::Init(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform, cpFloat radius)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		cpPolyShapeInit((OGcpPolyShape*)_handle, body->_handle, verts.Length, verts_ptr, transform, radius);
		SetUserData();
	}

	void cpPolyShape::Init(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		cpPolyShapeInit((OGcpPolyShape*)_handle, body->_handle, verts.Length, verts_ptr, transform, 0);
		SetUserData();
	}

	void cpPolyShape::Init(cpBody^ body, ReadOnlySpan<cpVect> verts, cpFloat radius)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		cpPolyShapeInitRaw((OGcpPolyShape*)_handle, body->_handle, verts.Length, verts_ptr, radius);
		SetUserData();
	}

	void cpPolyShape::Init(cpBody^ body, ReadOnlySpan<cpVect> verts)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, verts);
		cpPolyShapeInitRaw((OGcpPolyShape*)_handle, body->_handle, verts.Length, verts_ptr, 0);
		SetUserData();
	}

	void cpPolyShape::Init(cpBody^ body, cpFloat width, cpFloat height, cpFloat radius)
	{
		cpBoxShapeInit((OGcpPolyShape*)_handle, body->_handle, width, height, radius);
		SetUserData();
	}

	void cpPolyShape::Init(cpBody^ body, cpFloat width, cpFloat height)
	{
		cpBoxShapeInit((OGcpPolyShape*)_handle, body->_handle, width, height, 0);
		SetUserData();
	}

	void cpPolyShape::Init(cpBody^ body, cpBB box, cpFloat radius)
	{
		cpBoxShapeInit2((OGcpPolyShape*)_handle, body->_handle, box, radius);
		SetUserData();
	}

	void cpPolyShape::Init(cpBody^ body, cpBB box)
	{
		cpBoxShapeInit2((OGcpPolyShape*)_handle, body->_handle, box, 0);
		SetUserData();
	}

	int cpPolyShape::Count::get()
	{
		return cpPolyShapeGetCount(_handle);
	}

	cpVect cpPolyShape::GetVert(int index)
	{
		return cpPolyShapeGetVert(_handle, index);
	}

	ReadOnlySpan<cpVect> cpPolyShape::Verts::get()
	{
		return ReadOnlySpan<cpVect>(&cpPolyShapeGetVert(_handle, 0), cpPolyShapeGetCount(_handle));
	}

	void cpPolyShape::SetVerts(ReadOnlySpan<cpVect> value, cpTransform transform)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, value);
		cpPolyShapeSetVerts(_handle, value.Length, value_ptr, transform);
	}

	void cpPolyShape::SetVerts(ReadOnlySpan<cpVect> value)
	{
		SPAN_GET_PTR(cpVect, OGcpVect, value);
		cpPolyShapeSetVertsRaw(_handle, value.Length, value_ptr);
	}

	cpFloat cpPolyShape::Radius::get()
	{
		return cpPolyShapeGetRadius(_handle);
	}

	void cpPolyShape::Radius::set(cpFloat value)
	{
		cpPolyShapeSetRadius(_handle, value);
	}
}