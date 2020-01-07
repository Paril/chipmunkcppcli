#pragma once

#include "common.h"
#include "cpBodyType.h"

using OGcpBody = cpBody;

namespace ChipmunkCppCli
{
	value struct cpVect;
	ref struct cpSpace;
	ref struct cpShape;
	value struct cpArbiter;
	ref struct cpConstraint;
	ref struct cpBody;

	public delegate void cpBodyVelocityFunc(cpBody^ body, cpVect gravity, cpFloat damping, cpFloat dt);
	public delegate void cpBodyPositionFunc(cpBody^ body, cpFloat dt);

	public delegate void cpBodyShapeIteratorFunc(cpBody^ body, cpShape^ shape);
	public delegate void cpBodyConstraintIteratorFunc(cpBody^ body, cpConstraint^ constraint);
	public delegate void cpBodyArbiterIteratorFunc(cpBody^ body, cpArbiter arbiter);

	public ref struct cpBody
	{
	internal:
		OGcpBody* _handle;
		GCHandle _gc;
		DelegateHandler<cpBodyVelocityFunc^> _velocityFunc;
		DelegateHandler<cpBodyPositionFunc^> _positionFunc;

		static cpBody^ FromHandle(OGcpBody* body);

		void SetUserData();
		void UnsetUserData();

	public:
		cpBody();

		generic<class T> where T : cpBody, gcnew()
		static T Alloc();

		static cpBody^ Alloc();

		generic<class T> where T : cpBody, gcnew()
		static T New(cpFloat mass, cpFloat moment);

		static cpBody^ New(cpFloat mass, cpFloat moment);

		generic<class T> where T : cpBody, gcnew()
		static T New();

		static cpBody^ New();

		generic<class T> where T : cpBody, gcnew()
		static T New(cpBodyType type);

		static cpBody^ New(cpBodyType type);

		generic<class T> where T : cpBody, gcnew()
		static T NewKinematic();

		static cpBody^ NewKinematic();

		generic<class T> where T : cpBody, gcnew()
		static T NewStatic();

		static cpBody^ NewStatic();

		cpBody^ Init(cpFloat mass, cpFloat moment);

		void Destroy();
		void Free();

		void Activate();
		void ActivateStatic(cpShape^ filter);

		void Sleep();
		void SleepWithGroup(cpBody^ group);

		property bool IsSleeping { bool get(); }
		property cpBodyType Type { cpBodyType get(); void set(cpBodyType type); }
		property cpSpace^ Space { cpSpace^ get(); }
		property cpFloat Mass { cpFloat get(); void set(cpFloat value); }
		property cpFloat Moment { cpFloat get(); void set(cpFloat value); }
		property cpVect Position { cpVect get(); void set(cpVect value); }
		property cpVect CenterOfGravity { cpVect get(); void set(cpVect value); }
		property cpVect Velocity { cpVect get(); void set(cpVect value); }
		property cpVect Force { cpVect get(); void set(cpVect value); }
		property cpFloat Angle { cpFloat get(); void set(cpFloat value); }
		property cpFloat AngularVelocity { cpFloat get(); void set(cpFloat value); }
		property cpFloat Torque { cpFloat get(); void set(cpFloat value); }
		property cpVect Rotation { cpVect get(); }
		property cpBodyVelocityFunc^ VelocityUpdateFunc { cpBodyVelocityFunc^ get(); void set(cpBodyVelocityFunc^ value); }
		property cpBodyPositionFunc^ PositionUpdateFunc { cpBodyPositionFunc^ get(); void set(cpBodyPositionFunc^ value); }

		void UpdateVelocity(cpVect gravity, cpFloat damping, cpFloat dt);
		void UpdatePosition(cpFloat dt);

		cpVect LocalToWorld(cpVect point);
		cpVect WorldToLocal(cpVect point);

		void ApplyForceAtWorldPoint(cpVect force, cpVect point);
		void ApplyForceAtLocalPoint(cpVect force, cpVect point);

		void ApplyImpulseAtWorldPoint(cpVect impulse, cpVect point);
		void ApplyImpulseAtLocalPoint(cpVect impulse, cpVect point);

		cpVect GetVelocityAtWorldPoint(cpVect point);
		cpVect GetVelocityAtLocalPoint(cpVect point);

		property cpFloat KineticEnergy { cpFloat get(); }

		void EachShape(cpBodyShapeIteratorFunc^ func);
		void EachConstraint(cpBodyConstraintIteratorFunc^ func);
		void EachArbiter(cpBodyArbiterIteratorFunc^ func);
	};
}