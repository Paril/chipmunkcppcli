#include "cpSimpleMotor.h"
#include "cpBody.h"

namespace ChipmunkCppCli
{
	generic<typename T> where T : cpSimpleMotor, gcnew()
	/*static*/ T cpSimpleMotor::Alloc()
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpSimpleMotorAlloc();
		return ret;
	}

	/*static*/ cpSimpleMotor^ cpSimpleMotor::Alloc()
	{
		return Alloc<cpSimpleMotor^>();
	}

	generic<typename T> where T : cpSimpleMotor, gcnew()
	/*static*/ T cpSimpleMotor::New(cpBody^ a, cpBody^ b, cpFloat rate)
	{
		T ret = gcnew T();
		ret->_handle = (OGcpConstraint*)cpSimpleMotorNew(a->_handle, b->_handle, rate);
		ret->SetUserData();
		return ret;
	}

	/*static*/ cpSimpleMotor^ cpSimpleMotor::New(cpBody^ a, cpBody^ b, cpFloat rate)
	{
		return New<cpSimpleMotor^>(a, b, rate);
	}

	cpSimpleMotor^ cpSimpleMotor::Init(cpBody^ a, cpBody^ b, cpFloat rate)
	{
		cpSimpleMotorInit((::cpSimpleMotor*)_handle, a->_handle, b->_handle, rate);
		SetUserData();
		return this;
	}
	
	cpFloat cpSimpleMotor::Rate::get()
	{
		return cpSimpleMotorGetRate(_handle);
	}

	void cpSimpleMotor::Rate::set(cpFloat value)
	{
		cpSimpleMotorSetRate(_handle, value);
	}
}