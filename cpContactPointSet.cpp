#include "cpContactPointSet.h"
#include "cpVect.h"

namespace ChipmunkCppCli
{
	/*static*/ cpContactPointSet::operator OGcpContactPointSet(cpContactPointSet in)
	{
		OGcpContactPointSet set;
		set.normal = in.normal;
		set.count = in.points->Length;
		auto iptr = (cpContactPoint*)&set.points;
		
		for (int i = 0; i < set.count; i++)
		{
			*iptr = in.points[i];
			iptr++;
		}

		return set;
	}
	/*static*/ cpContactPointSet::operator cpContactPointSet(const OGcpContactPointSet& in)
	{
		cpContactPointSet set;
		set.normal = in.normal;
		set.points = gcnew array<cpContactPoint>(in.count);
		auto iptr = &set.points[0];

		for (int i = 0; i < in.count; i++)
		{
			*iptr = *(cpContactPoint*)&in.points[i];
			iptr++;
		}

		return set;
	}
}