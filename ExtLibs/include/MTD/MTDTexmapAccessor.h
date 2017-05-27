#pragma once

#include <string>
#include <DLVec.hpp>

typedef std::string DLAsciiString;
typedef std::wstring DLString;

namespace MTD
{

	class MTDTexmapAccessorConst
	{
	public:
		explicit MTDTexmapAccessorConst(bool valid=true) :m_IsValid(valid) {}
		virtual ~MTDTexmapAccessorConst() {}

		void GetPath(DLAsciiString& texPath);

		void GetTiling(DL_VECTOR2& tiling);

		bool IsValid() const {
			return m_IsValid;
		}
		bool m_IsValid;
	protected:
		DLAsciiString m_TexPath;
		DL_VECTOR2 m_tilingUV;

	};
	class MTDTexmapAccessor : public MTDTexmapAccessorConst
	{
	public:
		explicit MTDTexmapAccessor(bool valid = true) :MTDTexmapAccessorConst(valid) {}
		virtual ~MTDTexmapAccessor() {}

		void SetPath(const DLAsciiString& texPath);
		
		void SetTiling(const DL_VECTOR2& tiling);
	};
}
