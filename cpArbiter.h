#pragma once

#include "common.h"

using OGcpArbiter = cpArbiter;

namespace ChipmunkCppCli
{
	value struct cpVect;
	ref struct cpShape;
	ref struct cpSpace;
	ref struct cpBody;
	value struct cpContactPointSet;

	public value struct cpArbiter
	{
	internal:
		OGcpArbiter* _handle;

		cpArbiter(OGcpArbiter* handle);

	public:
		property cpFloat Restitution { cpFloat get(); void set(cpFloat value); }
		property cpFloat Friction { cpFloat get(); void set(cpFloat value); }
		property cpVect SurfaceVelocity { cpVect get(); void set(cpVect value); }
		property cpVect TotalImpulse { cpVect get(); }
		property cpFloat TotalKE { cpFloat get(); }

		bool Ignore();

		generic<typename T1, typename T2> where T1 : cpShape where T2 : cpShape
		void GetShapes([Out] T1% a, [Out] T2% b);

		void GetShapes([Out] cpShape^% a, [Out] cpShape^% b);

		generic<typename T1, typename T2> where T1 : cpBody where T2 : cpBody
		void GetBodies([Out] T1% a, [Out] T2% b);
		
		void GetBodies([Out] cpBody^% a, [Out] cpBody^% b);

		property cpContactPointSet ContactPointSet { cpContactPointSet get(); void set(cpContactPointSet value); }
		property bool IsFirstContact { bool get(); }
		property bool IsRemoval { bool get(); }
		property int Count { int get(); }
		property cpVect Normal { cpVect get(); }

		cpVect GetPointA(int i);
		cpVect GetPointB(int i);
		cpFloat GetDepth(int i);

		bool CallWildcardBeginA(cpSpace^ space);
		bool CallWildcardBeginB(cpSpace^ space);

		bool CallWildcardPreSolveA(cpSpace^ space);
		bool CallWildcardPreSolveB(cpSpace^ space);

		void CallWildcardPostSolveA(cpSpace^ space);
		void CallWildcardPostSolveB(cpSpace^ space);

		void CallWildcardSeparateA(cpSpace^ space);
		void CallWildcardSeparateB(cpSpace^ space);
	};
}