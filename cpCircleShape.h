#pragma once
#include "cpShape.h"

namespace ChipmunkCppCli
{
	public ref struct cpCircleShape : cpShape
	{
		generic<class T> where T : cpCircleShape, gcnew()
		static T Alloc();

		static cpCircleShape^ Alloc();

		generic<class T> where T : cpCircleShape, gcnew()
		static T New(cpBody^ body, cpFloat radius, cpVect offset);

		generic<class T> where T : cpCircleShape, gcnew()
		static T New(cpBody^ body, cpFloat radius);

		static cpCircleShape^ New(cpBody^ body, cpFloat radius, cpVect offset);
		static cpCircleShape^ New(cpBody^ body, cpFloat radius);

		void Init(cpBody^ body, cpFloat radius, cpVect offset);
		void Init(cpBody^ body, cpFloat radius);

		property cpFloat Radius { cpFloat get(); void set(cpFloat value); }
		property cpVect Offset { cpVect get(); void set(cpVect value); }
	};
}