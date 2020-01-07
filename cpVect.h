#pragma once

#include "common.h"

using OGcpVect = ::cpVect;

namespace ChipmunkCppCli
{
	[StructLayout(LayoutKind::Sequential)]
	public value struct cpVect
	{
		static initonly cpVect cpvzero = ::cpvzero;
		static initonly cpVect Zero = ::cpvzero;
		cpFloat x, y;

	internal:
		static operator OGcpVect(cpVect vect);
		static operator cpVect(OGcpVect vect);

	public:
		cpVect(cpFloat x, cpFloat y);

		bool Equals(cpVect v) { return cpveql(*this, v); }
		bool Equals(Object^ o) override
		{
			if (o->GetType() == cpVect::typeid)
				return Equals((cpVect)o);

			return ValueType::Equals(o);
		}

		int GetHashCode() override { return HashCode::Combine(x, y); }

		static cpVect operator *(cpVect v, cpFloat s) { return cpvmult(v, s); }
		static cpVect operator *(cpFloat s, cpVect v) { return cpvmult(v, s); }
		static cpVect operator +(cpVect v1, cpVect v2) { return cpvadd(v1, v2); }
		static cpVect operator -(cpVect v1, cpVect v2) { return cpvsub(v1, v2); }
		static cpBool operator ==(cpVect v1, cpVect v2) { return cpveql(v1, v2); }
		static cpVect operator -(cpVect v) { return cpvneg(v); }

		cpFloat Dot(cpVect v2) { return cpvdot(*this, v2); }
		cpFloat Cross(cpVect v2) { return cpvcross(*this, v2); }
		cpVect Project(cpVect v2) { return cpvproject(*this, v2); }
		static cpVect FromAngle(cpFloat v) { return cpvforangle(v); }
		cpVect Rotate(cpVect v2) { return cpvrotate(*this, v2); }
		cpVect UnRotate(cpVect v2) { return cpvunrotate(*this, v2); }

		property cpVect Perp { cpVect get() { return cpvperp(*this); } }
		property cpVect RPerp { cpVect get() { return cpvrperp(*this); } }
		property cpFloat Angle { cpFloat get() { return cpvtoangle(*this); } }
		property cpFloat LengthSquared { cpFloat get() { return cpvlengthsq(*this); } }
		property cpFloat Length { cpFloat get() { return cpvlength(*this); } }
		property cpVect Normalized { cpVect get() { return cpvnormalize(*this); } }

		cpVect Lerp(cpVect v2, cpFloat t) { return cpvlerp(*this, v2, t); }
		cpVect SLerp(cpVect v2, cpFloat t) { return cpvslerp(*this, v2, t); }
		cpVect SLerpConst(cpVect v2, cpFloat a) { return cpvslerpconst(*this, v2, a); }
		cpVect Clamp(cpFloat len) { return cpvclamp(*this, len); }
		cpVect LerpConst(cpVect v2, cpFloat t) { return cpvlerpconst(*this, v2, t); }
		cpFloat Dist(cpVect v2) { return cpvdist(*this, v2); }
		cpFloat DistSquared(cpVect v2) { return cpvdistsq(*this, v2); }
		bool IsNear(cpVect v2, cpFloat dist) { return cpvnear(*this, v2, dist); }

		static cpVect cpv(cpFloat x, cpFloat y);
		static bool cpveql(cpVect v1, cpVect v2);
		static cpVect cpvadd(cpVect v1, cpVect v2);
		static cpVect cpvsub(cpVect v1, cpVect v2);
		static cpVect cpvneg(cpVect v);
		static cpVect cpvmult(cpVect v, cpFloat s);
		static cpFloat cpvdot(cpVect v1, cpVect v2);
		static cpFloat cpvcross(cpVect v1, cpVect v2);
		static cpVect cpvperp(cpVect v);
		static cpVect cpvrperp(cpVect v);
		static cpVect cpvproject(cpVect v1, cpVect v2);
		static cpVect cpvforangle(cpFloat v);
		static cpFloat cpvtoangle(cpVect v);
		static cpVect cpvrotate(cpVect v1, cpVect v2);
		static cpVect cpvunrotate(cpVect v1, cpVect v2);
		static cpFloat cpvlengthsq(cpVect v);
		static cpFloat cpvlength(cpVect v);
		static cpVect cpvlerp(cpVect v1, cpVect v2, cpFloat t);
		static cpVect cpvnormalize(cpVect v);
		static cpVect cpvslerp(cpVect v1, cpVect v2, cpFloat t);
		static cpVect cpvslerpconst(cpVect v1, cpVect v2, cpFloat a);
		static cpVect cpvclamp(cpVect v, cpFloat len);
		static cpVect cpvlerpconst(cpVect v1, cpVect v2, cpFloat t);
		static cpFloat cpvdist(cpVect v1, cpVect v2);
		static cpFloat cpvdistsq(cpVect v1, cpVect v2);
		static bool cpvnear(cpVect v1, cpVect v2, cpFloat dist);
	};
}