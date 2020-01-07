#pragma once

#include "common.h"

using OGcpShapeFilter = cpShapeFilter;

namespace ChipmunkCppCli
{
	[StructLayout(LayoutKind::Sequential)]
	public value struct cpShapeFilter
	{
		static initonly cpShapeFilter All = cpShapeFilter(CP_NO_GROUP, CP_ALL_CATEGORIES, CP_ALL_CATEGORIES);
		static initonly cpShapeFilter None = cpShapeFilter(CP_NO_GROUP, ~CP_ALL_CATEGORIES, ~CP_ALL_CATEGORIES);

		cpGroup group;
		cpBitmask categories;
		cpBitmask mask;

		cpShapeFilter(cpGroup group, cpBitmask categories, cpBitmask mask) :
			group(group),
			categories(categories),
			mask(mask)
		{
		}

	internal:
		static operator OGcpShapeFilter(cpShapeFilter filter)
		{
			return *(OGcpShapeFilter*)&filter;
		}

		static operator cpShapeFilter(OGcpShapeFilter filter)
		{
			return *(cpShapeFilter*)&filter;
		}
	};
}