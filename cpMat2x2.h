#pragma once

#include "common.h"

using OGcpMat2x2 = ::cpMat2x2;

namespace ChipmunkCppCli
{
	value struct cpVect;

	[StructLayout(LayoutKind::Sequential)]
	public value struct cpMat2x2
	{
		cpFloat a, b, c, d;

	internal:
		static operator OGcpMat2x2(cpMat2x2 vect);
		static operator cpMat2x2(OGcpMat2x2 vect);

	public:
		cpMat2x2(cpFloat a, cpFloat b, cpFloat c, cpFloat d);

		static cpMat2x2 cpMat2x2New(cpFloat a, cpFloat b, cpFloat c, cpFloat d);
		static cpVect cpMat2x2Transform(cpMat2x2 m, cpVect v);
	};
}