#pragma once

#include <cstddef>
#include <cinttypes>
#include <type_traits>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

#pragma managed(push, off)
#include "chipmunk/chipmunk.h"
#pragma managed(pop)

#include "macros.h"

// A helper class to handle Chipmunk classes that hold delegates
using DelegateHandlerSetter = void (*)(void*, void*);
using DelegateHandlerGetter = void* (*)(void*);

generic<typename T> where T : Delegate
value struct DelegateHandler
{
private:
	void* _wrapper;
	DelegateHandlerSetter _setter;
	DelegateHandlerGetter _getter;
	void* _handle;
	void* _default;
	T _delegate;
	bool _init;

public:
	DelegateHandler(DelegateHandlerSetter setter, DelegateHandlerGetter getter, void* wrapper) :
		_wrapper(wrapper),
		_setter(setter),
		_getter(getter),
		_init(false)
	{
	}

	DelegateHandler(DelegateHandlerSetter setter, void* default, void* wrapper) :
		_wrapper(wrapper),
		_setter(setter),
		_default(default),
		_init(true)
	{
	}

	void Init(void* handle)
	{
		_handle = handle;

		if (_init)
		{
			Delegate = _delegate;
			return;
		}

		if (_getter)
			_default = _getter(handle);
		_init = true;
	}

	void Free()
	{
		_handle = nullptr;
	}

	property T Delegate
	{
		T get() { return _delegate; }
		void set(T value)
		{
			_delegate = value;

			if (_delegate)
				_setter(_handle, _wrapper);
			else
				_setter(_handle, _default);
		}
	}
};