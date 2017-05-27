#pragma once

#ifndef _STRING_
#include <string>
#endif

namespace MtdLibCLR
{
	namespace MtdLibCLRInternal
	{
		namespace StringUtil
		{
			std::string Convert(System::String^ str);

			System::String^ Convert(const std::string& str);
			System::String^ Convert(const std::wstring& str);
		}
	}
}

#include "StringUtil.inl"