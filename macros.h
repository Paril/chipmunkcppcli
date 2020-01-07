#pragma once

// HELPER MACROS
#undef WRAPPED_ENUM
#define WRAP_STR(x) x
#define WRAP_ENUM(name) \
	name = WRAP_STR(WRAPPED_ENUM) ## _ ## name

#define SPAN_GET_PTR(type, ptr_type, name) \
	pin_ptr<type> name ## _pin = &MemoryMarshal::GetReference(name); \
	ptr_type* name ## _ptr = (ptr_type*)name ## _pin;

#define REF_PIN(type, ptr_type, name) \
	pin_ptr<type> name ## _pin = &name; \
	auto name ## _ptr = name ## _pin;
