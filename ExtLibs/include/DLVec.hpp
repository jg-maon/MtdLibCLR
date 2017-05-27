#pragma once

struct DL_VECTOR4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			int ix, iy, iz, iw;			
		};
		float v[4];
		int s[4];

	};
};

struct DL_VECTOR2
{
	union {
		struct 
		{
			union {
				float x, y;
				int ix, iy;
			};
		};
		float v[2];
		int s[2];
	};

};

namespace DLIVec4
{
	inline DL_VECTOR4 Set(float x, float y, float z, float w)
	{
		DL_VECTOR4 v;
		v.x = x;
		v.y = y;
		v.z = z;
		v.w = w;

		return v;
	}
	inline DL_VECTOR4 Set(int x, int y, int z, int w)
	{
		DL_VECTOR4 v;
		v.ix = x;
		v.iy = y;
		v.iz = z;
		v.iw = w;

		return v;
	}
}


namespace DLIVec2
{
	inline DL_VECTOR2 Set(float x, float y)
	{
		DL_VECTOR2 v;
		v.x = x;
		v.y = y;
		return v;
	}
	inline DL_VECTOR2 Set(int x, int y)
	{
		DL_VECTOR2 v;
		v.ix = x;
		v.iy = y;
		return v;
	}
}