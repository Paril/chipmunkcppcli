#pragma once
#include "cpShape.h"

namespace ChipmunkCppCli
{
	public ref struct cpSegmentShape : cpShape
	{
		generic<class T> where T : cpSegmentShape, gcnew()
		static T Alloc();

		static cpSegmentShape^ Alloc();

		generic<class T> where T : cpSegmentShape, gcnew()
		static T New(cpBody^ body, cpVect a, cpVect b, cpFloat radius);

		generic<class T> where T : cpSegmentShape, gcnew()
		static T New(cpBody^ body, cpVect a, cpVect b);

		static cpSegmentShape^ New(cpBody^ body, cpVect a, cpVect b, cpFloat radius);
		static cpSegmentShape^ New(cpBody^ body, cpVect a, cpVect b);

		void Init(cpBody^ body, cpVect a, cpVect b, cpFloat radius);
		void Init(cpBody^ body, cpVect a, cpVect b);

		void SetNeighbors(cpVect prev, cpVect next);

		property cpVect A { cpVect get(); void set(cpVect value); }
		property cpVect B { cpVect get(); void set(cpVect value); }
		property cpVect Normal { cpVect get(); }
		property cpFloat Radius { cpFloat get(); void set(cpFloat value); }
	};
}