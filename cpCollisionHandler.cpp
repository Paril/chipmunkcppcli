#include "cpCollisionHandler.h"
#include "cpSpace.h"
#include "cpArbiter.h"

namespace ChipmunkCppCli
{
	cpCollisionHandler::cpCollisionHandler(OGcpCollisionHandler* handle) :
		_handle(handle)
	{
		_handle->userData = _handle;

		_defaultBeginFunc = _handle->beginFunc;
		_defaultPreSolveFunc = _handle->preSolveFunc;
		_defaultPostSolveFunc = _handle->postSolveFunc;
		_defaultSeparateFunc = _handle->separateFunc;
	}

#define HANDLER_IMPL(prop, delegate, val, handle, default, member, wrapper) \
	delegate^ cpCollisionHandler::prop::get() \
	{ \
		return val; \
	} \
	void cpCollisionHandler::prop::set(delegate^ value) \
	{ \
		val = value; \
		_handle->member = val ? wrapper : default; \
	}

	static cpBool cpCollisionBeginFunc_wrap(::cpArbiter* arb, ::cpSpace* space_handle, cpDataPointer userData)
	{
		auto space = cpSpace::FromHandle(space_handle);
		auto handler = space->_collisionHandlers[(IntPtr)userData];
		return handler->Begin(cpArbiter(arb), space);
	}

	HANDLER_IMPL(Begin, cpCollisionBeginFunc, _beginFunc, _beginHandle, _defaultBeginFunc, beginFunc, cpCollisionBeginFunc_wrap);

	static cpBool cpCollisionPreSolveFunc_wrap(::cpArbiter* arb, ::cpSpace* space_handle, cpDataPointer userData)
	{
		auto space = cpSpace::FromHandle(space_handle);
		auto handler = space->_collisionHandlers[(IntPtr)userData];
		return handler->PreSolve(cpArbiter(arb), space);
	}

	HANDLER_IMPL(PreSolve, cpCollisionPreSolveFunc, _preSolveFunc, _preSolveHandle, _defaultPreSolveFunc, preSolveFunc, cpCollisionPreSolveFunc_wrap);

	static void cpCollisionPostSolveFunc_wrap(::cpArbiter* arb, ::cpSpace* space_handle, cpDataPointer userData)
	{
		auto space = cpSpace::FromHandle(space_handle);
		auto handler = space->_collisionHandlers[(IntPtr)userData];
		handler->PostSolve(cpArbiter(arb), space);
	}

	HANDLER_IMPL(PostSolve, cpCollisionPostSolveFunc, _postSolveFunc, _postSolveHandle, _defaultPostSolveFunc, postSolveFunc, cpCollisionPostSolveFunc_wrap);

	static void cpCollisionSeparateFunc_wrap(::cpArbiter* arb, ::cpSpace* space_handle, cpDataPointer userData)
	{
		auto space = cpSpace::FromHandle(space_handle);
		auto handler = space->_collisionHandlers[(IntPtr)userData];
		handler->Separate(cpArbiter(arb), space);
	}

	HANDLER_IMPL(Separate, cpCollisionSeparateFunc, _separateFunc, _separateHandle, _defaultSeparateFunc, separateFunc, cpCollisionSeparateFunc_wrap);

}