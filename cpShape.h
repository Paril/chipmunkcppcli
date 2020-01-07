#pragma once
#include "common.h"

using OGcpShape = cpShape;
using OGcpCircleShape = cpCircleShape;
using OGcpSegmentShape = cpSegmentShape;
using OGcpPolyShape = cpPolyShape;

namespace ChipmunkCppCli
{
	value struct cpBB;
	value struct cpTransform;
	value struct cpVect;
	value struct cpPointQueryInfo;
	value struct cpSegmentQueryInfo;
	ref struct cpSpace;
	value struct cpShapeFilter;
	value struct cpContactPointSet;
	ref struct cpBody;

	public ref struct cpShape
	{
	internal:
		OGcpShape* _handle;
		GCHandle _gc;

		static cpShape^ FromHandle(OGcpShape* shape);

		void SetUserData();
		void UnsetUserData();

	public:
		void Destroy();
		void Free();

		cpBB CacheBB();
		cpBB Update(cpTransform transform);

		cpFloat PointQuery(cpVect p, [Out] cpPointQueryInfo% out);
		cpFloat PointQuery(cpVect p);

		bool SegmentQuery(cpVect a, cpVect b, cpFloat radius, [Out] cpSegmentQueryInfo% out);
		bool SegmentQuery(cpVect a, cpVect b, cpFloat radius);

		cpContactPointSet Collide(cpShape^ b);

		property cpSpace^ Space { cpSpace^ get(); }
		property cpBody^ Body { cpBody^ get(); void set(cpBody^ value); }
		property cpFloat Mass { cpFloat get(); void set(cpFloat value); }
		property cpFloat Density { cpFloat get(); void set(cpFloat value); }
		property cpFloat Moment { cpFloat get(); }
		property cpFloat Area { cpFloat get(); }
		property cpVect CenterOfGravity { cpVect get(); }
		property cpBB BB { cpBB get(); }
		property bool Sensor { bool get(); void set(bool value); }
		property cpFloat Elasticity { cpFloat get(); void set(cpFloat value); }
		property cpFloat Friction { cpFloat get(); void set(cpFloat value); }
		property cpVect SurfaceVelocity { cpVect get(); void set(cpVect value); }
		property cpCollisionType CollisionType { cpCollisionType get(); void set(cpCollisionType value); }
		property cpShapeFilter Filter { cpShapeFilter get(); void set(cpShapeFilter value); }
	};
}