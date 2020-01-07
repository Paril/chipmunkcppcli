#pragma once

#include "common.h"

using OGcpSpace = cpSpace;
using namespace System::Diagnostics::CodeAnalysis;

namespace ChipmunkCppCli
{
	ref struct cpBody;
	value struct cpShapeFilter;
	value struct cpPointQueryInfo;
	value struct cpSegmentQueryInfo;
	value struct cpContactPointSet;
	ref struct cpConstraint;
	ref struct cpShape;
	value struct cpVect;
	value struct cpBB;
	ref struct cpCollisionHandler;
	value struct cpArbiter;
	interface class cpSpaceDebugDrawOptions;
	ref struct cpSpace;

	public delegate void cpPostStepFunc(cpSpace^ space, IntPtr key);
	public delegate void cpSpacePointQueryFunc(cpShape^ shape, cpVect point, cpFloat distance, cpVect gradient);
	public delegate void cpSpaceSegmentQueryFunc(cpShape^ shape, cpVect point, cpVect normal, cpFloat alpha);
	public delegate void cpSpaceBBQueryFunc(cpShape^ shape);
	public delegate void cpSpaceShapeQueryFunc(cpShape^ shape, cpContactPointSet points);
	public delegate void cpSpaceBodyIteratorFunc(cpBody^ body);
	public delegate void cpSpaceShapeIteratorFunc(cpShape^ shape);
	public delegate void cpSpaceConstraintIteratorFunc(cpConstraint^ constraint);
	public delegate void cpSpaceArbiterIteratorFunc(cpArbiter arb);

	public ref struct cpSpace : IDisposable
	{
	internal:
		OGcpSpace* _handle;
		GCHandle _gc;
		bool _initialized = false;
		cpBody^ _staticBody;

		static cpSpace^ FromHandle(OGcpSpace* handle);

		void SetUserData();
		void UnsetUserData();

		~cpSpace();
		!cpSpace();

		void ReleaseHandles();

	public:
		generic<class T> where T : cpSpace, gcnew()
		static T Alloc();

		static cpSpace^ Alloc();

		generic<class T> where T : cpSpace, gcnew()
		static T New();

		static cpSpace^ New();

		cpSpace^ Init();

		void Destroy();
		void Free();

		property int Iterations { int get(); void set(int value); }
		property cpVect Gravity { cpVect get(); void set(cpVect value); }
		property cpFloat Damping { cpFloat get(); void set(cpFloat value); }
		property cpFloat IdleSpeedThreshold { cpFloat get(); void set(cpFloat value); }
		property cpFloat SleepTimeThreshold { cpFloat get(); void set(cpFloat value); }
		property cpFloat CollisionSlop { cpFloat get(); void set(cpFloat value); }
		property cpFloat CollisionBias { cpFloat get(); void set(cpFloat value); }
		property cpTimestamp CollisionPersistence { cpTimestamp get(); void set(cpTimestamp value); }
		property cpBody^ StaticBody { cpBody^ get(); }
		property cpFloat CurrentTimeStep { cpFloat get(); }
		property bool IsLocked { bool get(); }

	internal:
		Dictionary<IntPtr, cpCollisionHandler^>^ _collisionHandlers = gcnew Dictionary<IntPtr, cpCollisionHandler^>();

		cpCollisionHandler^ GetOrAdd(::cpCollisionHandler* handle);

	public:
		[returnvalue:NotNull] cpCollisionHandler^ AddDefaultCollisionHandler();
		[returnvalue:NotNull] cpCollisionHandler^ AddCollisionHandler(cpCollisionType a, cpCollisionType b);
		[returnvalue: NotNull] cpCollisionHandler^ AddWildcardHandler(cpCollisionType type);

		cpShape^ AddShape(cpShape^ shape);
		cpBody^ AddBody(cpBody^ body);
		cpConstraint^ AddConstraint(cpConstraint^ constraint);

		void RemoveShape(cpShape^ shape);
		void RemoveBody(cpBody^ body);
		void RemoveConstraint(cpConstraint^ constraint);

		bool ContainsShape(cpShape^ shape);
		bool ContainsBody(cpBody^ body);
		bool ContainsConstraint(cpConstraint^ constraint);

		bool AddPostStepCallback(cpPostStepFunc^ func, IntPtr key);

		void PointQuery(cpVect point, cpFloat maxDistance, cpShapeFilter filter, cpSpacePointQueryFunc^ func);
		cpShape^ PointQueryNearest(cpVect point, cpFloat maxDistance, cpShapeFilter filter, [Out] cpPointQueryInfo% out);
		cpShape^ PointQueryNearest(cpVect point, cpFloat maxDistance, cpShapeFilter filter);

		void SegmentQuery(cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter, cpSpaceSegmentQueryFunc^ func);
		cpShape^ SegmentQueryFirst(cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter, [Out] cpSegmentQueryInfo% out);
		cpShape^ SegmentQueryFirst(cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter);

		void BBQuery(cpBB bb, cpShapeFilter filter, cpSpaceBBQueryFunc^ func);

		bool ShapeQuery(cpShape^ shape, cpSpaceShapeQueryFunc^ func);

		void EachBody(cpSpaceBodyIteratorFunc^ func);
		void EachShape(cpSpaceShapeIteratorFunc^ func);
		void EachConstraint(cpSpaceConstraintIteratorFunc^ func);

		void ReindexStatic();
		void ReindexShape(cpShape^ shape);
		void ReindexShapesForBody(cpBody^ body);

		void UseSpatialHash(cpFloat dim, int count);

		void Step(cpFloat dt);
		
		void DebugDraw(cpSpaceDebugDrawOptions^ options);
	};
}