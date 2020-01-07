#pragma once

#include "common.h"

using OGcpSpaceDebugDrawOptions = ::cpSpaceDebugDrawOptions;
using OGcpSpaceDebugColor = ::cpSpaceDebugColor;

namespace ChipmunkCppCli
{
	value struct cpVect;
	ref struct cpShape;

	public enum class cpSpaceDebugDrawFlags
	{
		DrawShapes = CP_SPACE_DEBUG_DRAW_SHAPES,
		DrawConstraints = CP_SPACE_DEBUG_DRAW_CONSTRAINTS,
		DrawCollisionPoints = CP_SPACE_DEBUG_DRAW_COLLISION_POINTS
	};

	[StructLayout(LayoutKind::Sequential)]
	public value struct cpSpaceDebugColor
	{
		float r, g, b, a;

	internal:
		static operator OGcpSpaceDebugColor(cpSpaceDebugColor color)
		{
			return *(OGcpSpaceDebugColor*)&color;
		}
		static operator cpSpaceDebugColor(const OGcpSpaceDebugColor& color)
		{
			return *(cpSpaceDebugColor*)&color;
		}

	public:

		cpSpaceDebugColor(float r, float g, float b, float a) :
			r(r),
			g(g),
			b(b),
			a(a)
		{
		}

		cpSpaceDebugColor(float r, float g, float b) :
			cpSpaceDebugColor(r, g, b, 1)
		{
		}
	};

	public interface class cpSpaceDebugDrawOptions
	{
	public:
		void DrawCircle(cpVect pos, cpFloat angle, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor);
		void DrawSegment(cpVect a, cpVect b, cpSpaceDebugColor color);
		void DrawFatSegment(cpVect a, cpVect b, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor);
		void DrawPolygon(ReadOnlySpan<cpVect> verts, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor);
		void DrawDot(cpFloat size, cpVect pos, cpSpaceDebugColor color);
		cpSpaceDebugColor ColorForShape(cpShape^ shape);

		property cpSpaceDebugDrawFlags Flags { cpSpaceDebugDrawFlags get(); }
		property cpSpaceDebugColor ShapeOutlineColor { cpSpaceDebugColor get(); }
		property cpSpaceDebugColor ConstraintColor { cpSpaceDebugColor get(); }
		property cpSpaceDebugColor CollisionPointColor { cpSpaceDebugColor get(); }
	};
}