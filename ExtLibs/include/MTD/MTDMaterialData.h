#pragma once

#include <string>
#include <unordered_map>

#include "MTDParamAccessor.h"
#include "MTDTexmapAccessor.h"

typedef std::string DLAsciiString;
typedef std::wstring DLString;

namespace DLMemory
{
	inline void Copy(void* pDst, const void* pSrc, size_t size)
	{
		::memcpy(pDst, pSrc, size);
	}
}

namespace MTD
{
	class MTDMaterialData
	{
	public:

		bool Read(const DLAsciiString& filePath);
		bool Write(const DLAsciiString& filePath);

		bool Read(const DLString& filePath);
		bool Write(const DLString& filePath);

		bool SetSPXPath(const DLString& spx);
		bool GetSPXPath(DLString& spx);

		MTDParamAccessor& FindParam(const DLAsciiString& name);
		MTDTexmapAccessor& FindTexmap(const DLAsciiString& name);

		MTDParamAccessorConst FindParam(const DLAsciiString& name) const;
		MTDTexmapAccessorConst FindTexmap(const DLAsciiString& name) const;

		std::unordered_map<DLAsciiString, MTDParamAccessor> m_Params;
		std::unordered_map<DLAsciiString, MTDTexmapAccessor> m_Texmaps;
		DLString m_Spx;
	};
}