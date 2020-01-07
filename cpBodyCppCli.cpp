#include "cpBody.h"
#include "cpSpace.h"
#include "cpShape.h"
#include "cpVect.h"
#include "cpConstraint.h"
#include "cpArbiter.h"

namespace ChipmunkCppCli
{
	/*static*/ cpBody^ cpBody::FromHandle(OGcpBody* body)
	{
		return (cpBody^)GCHandle::FromIntPtr((IntPtr)cpBodyGetUserData(body)).Target;
	}

	void cpBody::SetUserData()
	{
		_gc = GCHandle::Alloc(this);
		cpBodySetUserData(_handle, GCHandle::ToIntPtr(_gc).ToPointer());
		_velocityFunc.Init(_handle);
		_positionFunc.Init(_handle);
	}

	void cpBody::UnsetUserData()
	{
		cpBodySetUserData(_handle, nullptr);
		if (_gc.IsAllocated)
			_gc.Free();
		_velocityFunc.Free();
		_positionFunc.Free();
	}

	static void cpBodySetVelocityUpdateFunc_wrapper(::cpBody* body, ::cpVect gravity, cpFloat damping, cpFloat dt)
	{
		cpBody^ body_ptr = cpBody::FromHandle(body);
		body_ptr->VelocityUpdateFunc(body_ptr, gravity, damping, dt);
	}

	static void cpBodySetPositionUpdateFunc_wrapper(::cpBody* body, cpFloat dt)
	{
		cpBody^ body_ptr = cpBody::FromHandle(body);
		body_ptr->PositionUpdateFunc(body_ptr, dt);
	}

	cpBody::cpBody() :
		_velocityFunc((DelegateHandlerSetter)cpBodySetVelocityUpdateFunc, ::cpBodyUpdateVelocity, cpBodySetVelocityUpdateFunc_wrapper),
		_positionFunc((DelegateHandlerSetter)cpBodySetPositionUpdateFunc, ::cpBodyUpdatePosition, cpBodySetPositionUpdateFunc_wrapper)
	{
	}

	generic<class T> where T : cpBody, gcnew()
	/*static*/ T cpBody::Alloc()
	{
		T body = gcnew T();
		body->_handle = cpBodyAlloc();
		return body;
	}

	/*static*/ cpBody^ cpBody::Alloc()
	{
		return Alloc<cpBody^>();
	}

	generic<class T> where T : cpBody, gcnew()
	/*static*/ T cpBody::New(cpFloat mass, cpFloat moment)
	{
		T body = gcnew T();
		body->_handle = cpBodyNew(mass, moment);
		body->SetUserData();
		return body;
	}

	/*static*/ cpBody^ cpBody::New(cpFloat mass, cpFloat moment)
	{
		return New<cpBody^>(mass, moment);
	}

	generic<class T> where T : cpBody, gcnew()
	/*static*/ T cpBody::New()
	{
		T body = gcnew T();
		body->_handle = cpBodyNew(0, 0);
		body->SetUserData();
		return body;
	}

	/*static*/ cpBody^ cpBody::New()
	{
		return New<cpBody^>();
	}

	generic<class T> where T : cpBody, gcnew()
	/*static*/ T cpBody::New(cpBodyType type)
	{
		switch (type)
		{
			case cpBodyType::Dynamic:
				return New<T>();
			case cpBodyType::Kinematic:
				return NewKinematic<T>();
			case cpBodyType::Static:
				return NewStatic<T>();
		}

		throw gcnew ArgumentException("Not a valid body type", "type");
	}

	/*static*/ cpBody^ cpBody::New(cpBodyType type)
	{
		return New<cpBody^>(type);
	}

	generic<class T> where T : cpBody, gcnew()
	/*static*/ T cpBody::NewKinematic()
	{
		T body = gcnew T();
		body->_handle = cpBodyNewKinematic();
		body->SetUserData();
		return body;
	}

	/*static*/ cpBody^ cpBody::NewKinematic()
	{
		return NewKinematic<cpBody^>();
	}

	generic<class T> where T : cpBody, gcnew()
	/*static*/ T cpBody::NewStatic()
	{
		T body = gcnew T();
		body->_handle = cpBodyNewStatic();
		body->SetUserData();
		return body;
	}

	/*static*/ cpBody^ cpBody::NewStatic()
	{
		return NewStatic<cpBody^>();
	}

	cpBody^ cpBody::Init(cpFloat mass, cpFloat moment)
	{
		cpBodyInit(_handle, mass, moment);
		SetUserData();
		return this;
	}

	void cpBody::Destroy()
	{
		UnsetUserData();
		cpBodyDestroy(_handle);
	}

	void cpBody::Free()
	{
		UnsetUserData();
		cpBodyFree(_handle);
		_handle = nullptr;
	}

	void cpBody::Activate()
	{
		cpBodyActivate(_handle);
	}

	void cpBody::ActivateStatic(cpShape^ filter)
	{
		cpBodyActivateStatic(_handle, filter->_handle);
	}

	void cpBody::Sleep()
	{
		cpBodySleep(_handle);
	}

	void cpBody::SleepWithGroup(cpBody^ group)
	{
		cpBodySleepWithGroup(_handle, group->_handle);
	}

	bool cpBody::IsSleeping::get()
	{
		return cpBodyIsSleeping(_handle);
	}

	cpBodyType cpBody::Type::get()
	{
		return (cpBodyType)cpBodyGetType(_handle);
	}
	
	void cpBody::Type::set(cpBodyType type)
	{
		cpBodySetType(_handle, (OGcpBodyType)type);
	}

	cpSpace^ cpBody::Space::get()
	{
		return cpSpace::FromHandle(cpBodyGetSpace(_handle));
	}

	cpFloat cpBody::Mass::get()
	{
		return cpBodyGetMass(_handle);
	}

	void cpBody::Mass::set(cpFloat value)
	{
		cpBodySetMass(_handle, value);
	}

	cpFloat cpBody::Moment::get()
	{
		return cpBodyGetMoment(_handle);
	}

	void cpBody::Moment::set(cpFloat value)
	{
		cpBodySetMoment(_handle, value);
	}

	cpVect cpBody::Position::get()
	{
		return cpBodyGetPosition(_handle);
	}

	void cpBody::Position::set(cpVect value)
	{
		cpBodySetPosition(_handle, value);
	}

	cpVect cpBody::CenterOfGravity::get()
	{
		return cpBodyGetCenterOfGravity(_handle);
	}

	void cpBody::CenterOfGravity::set(cpVect value)
	{
		cpBodySetCenterOfGravity(_handle, value);
	}

	cpVect cpBody::Velocity::get()
	{
		return cpBodyGetVelocity(_handle);
	}

	void cpBody::Velocity::set(cpVect value)
	{
		cpBodySetVelocity(_handle, value);
	}

	cpVect cpBody::Force::get()
	{
		return cpBodyGetForce(_handle);
	}

	void cpBody::Force::set(cpVect value)
	{
		cpBodySetForce(_handle, value);
	}

	cpFloat cpBody::Angle::get()
	{
		return cpBodyGetAngle(_handle);
	}
	
	void cpBody::Angle::set(cpFloat value)
	{
		cpBodySetAngle(_handle, value);
	}

	cpFloat cpBody::AngularVelocity::get()
	{
		return cpBodyGetAngularVelocity(_handle);
	}
	
	void cpBody::AngularVelocity::set(cpFloat value)
	{
		cpBodySetAngularVelocity(_handle, value);
	}

	cpFloat cpBody::Torque::get()
	{
		return cpBodyGetTorque(_handle);
	}
		
	void cpBody::Torque::set(cpFloat value)
	{
		cpBodySetTorque(_handle, value);
	}

	cpVect cpBody::Rotation::get()
	{
		return cpBodyGetRotation(_handle);
	}

	cpBodyVelocityFunc^ cpBody::VelocityUpdateFunc::get()
	{
		return _velocityFunc.Delegate;
	}

	void cpBody::VelocityUpdateFunc::set(cpBodyVelocityFunc^ value)
	{
		_velocityFunc.Delegate = value;
	}

	cpBodyPositionFunc^ cpBody::PositionUpdateFunc::get()
	{
		return _positionFunc.Delegate;
	}

	void cpBody::PositionUpdateFunc::set(cpBodyPositionFunc^ value)
	{
		_positionFunc.Delegate = value;
	}

	void cpBody::UpdateVelocity(cpVect gravity, cpFloat damping, cpFloat dt)
	{
		cpBodyUpdateVelocity(_handle, gravity, damping, dt);
	}
	
	void cpBody::UpdatePosition(cpFloat dt)
	{
		cpBodyUpdatePosition(_handle, dt);
	}

	cpVect cpBody::LocalToWorld(cpVect point)
	{
		return cpBodyLocalToWorld(_handle, point);
	}

	cpVect cpBody::WorldToLocal(cpVect point)
	{
		return cpBodyWorldToLocal(_handle, point);
	}

	void cpBody::ApplyForceAtWorldPoint(cpVect force, cpVect point)
	{
		cpBodyApplyForceAtWorldPoint(_handle, force, point);
	}

	void cpBody::ApplyForceAtLocalPoint(cpVect force, cpVect point)
	{
		cpBodyApplyForceAtLocalPoint(_handle, force, point);
	}

	void cpBody::ApplyImpulseAtWorldPoint(cpVect impulse, cpVect point)
	{
		cpBodyApplyImpulseAtWorldPoint(_handle, impulse, point);
	}

	void cpBody::ApplyImpulseAtLocalPoint(cpVect impulse, cpVect point)
	{
		cpBodyApplyImpulseAtLocalPoint(_handle, impulse, point);
	}

	cpVect cpBody::GetVelocityAtWorldPoint(cpVect point)
	{
		return cpBodyGetVelocityAtWorldPoint(_handle, point);
	}

	cpVect cpBody::GetVelocityAtLocalPoint(cpVect point)
	{
		return cpBodyGetVelocityAtLocalPoint(_handle, point);
	}

	cpFloat cpBody::KineticEnergy::get()
	{
		return cpBodyKineticEnergy(_handle);
	}

	static void EachShape_wrap(::cpBody* body, ::cpShape* shape, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpBodyShapeIteratorFunc^)handle.Target;
		func_ptr(cpBody::FromHandle(body), cpShape::FromHandle(shape));
	}

	void cpBody::EachShape(cpBodyShapeIteratorFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpBodyEachShape(_handle, EachShape_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	static void EachConstraint_wrap(::cpBody* body, ::cpConstraint* shape, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpBodyConstraintIteratorFunc^)handle.Target;
		func_ptr(cpBody::FromHandle(body), cpConstraint::FromHandle(shape));
	}

	void cpBody::EachConstraint(cpBodyConstraintIteratorFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpBodyEachConstraint(_handle, EachConstraint_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}

	static void EachArbiter_wrap(::cpBody* body, ::cpArbiter* arb, void* data)
	{
		auto handle = GCHandle::FromIntPtr(IntPtr(data));
		auto func_ptr = (cpBodyArbiterIteratorFunc^)handle.Target;
		func_ptr(cpBody::FromHandle(body), cpArbiter(arb));
	}

	void cpBody::EachArbiter(cpBodyArbiterIteratorFunc^ func)
	{
		auto handle = GCHandle::Alloc(func);
		cpBodyEachArbiter(_handle, EachArbiter_wrap, GCHandle::ToIntPtr(handle).ToPointer());
		handle.Free();
	}
}