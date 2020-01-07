#pragma once
#include "cpShape.h"

namespace ChipmunkCppCli
{
	public ref struct cpPolyShape : cpShape
	{
		generic<class T> where T : cpPolyShape, gcnew()
		static T Alloc();

		static cpPolyShape^ Alloc();

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform, cpFloat radius);

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform);

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpFloat radius);

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, ReadOnlySpan<cpVect> verts);

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, cpFloat width, cpFloat height, cpFloat radius);

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, cpFloat width, cpFloat height);

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, cpBB box, cpFloat radius);

		generic<class T> where T : cpPolyShape, gcnew()
		static T New(cpBody^ body, cpBB box);

		static cpPolyShape^ New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform, cpFloat radius);
		static cpPolyShape^ New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform);
		static cpPolyShape^ New(cpBody^ body, ReadOnlySpan<cpVect> verts, cpFloat radius);
		static cpPolyShape^ New(cpBody^ body, ReadOnlySpan<cpVect> verts);
		static cpPolyShape^ New(cpBody^ body, cpFloat width, cpFloat height, cpFloat radius);
		static cpPolyShape^ New(cpBody^ body, cpFloat width, cpFloat height);
		static cpPolyShape^ New(cpBody^ body, cpBB box, cpFloat radius);
		static cpPolyShape^ New(cpBody^ body, cpBB box);

		void Init(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform, cpFloat radius);
		void Init(cpBody^ body, ReadOnlySpan<cpVect> verts, cpTransform transform);
		void Init(cpBody^ body, ReadOnlySpan<cpVect> verts, cpFloat radius);
		void Init(cpBody^ body, ReadOnlySpan<cpVect> verts);
		void Init(cpBody^ body, cpFloat width, cpFloat height, cpFloat radius);
		void Init(cpBody^ body, cpFloat width, cpFloat height);
		void Init(cpBody^ body, cpBB box, cpFloat radius);
		void Init(cpBody^ body, cpBB box);

		property int Count { int get(); }
		cpVect GetVert(int index);
		property ReadOnlySpan<cpVect> Verts { ReadOnlySpan<cpVect> get(); }
		void SetVerts(ReadOnlySpan<cpVect> value, cpTransform transform);
		void SetVerts(ReadOnlySpan<cpVect> value);

		property cpFloat Radius { cpFloat get(); void set(cpFloat value); }
	};
}