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

inline std::string Convert(System::String^ str)
{
	std::string text;
		
	System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
	text = static_cast<const char*>(ptr.ToPointer());
	System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
	return text;
}

inline System::String^ Convert(const std::string& str)
{
	return gcnew String(str.c_str());
}

inline System::String^ Convert(const std::wstring& str)
{
	return gcnew String(str.c_str());
}
}
}
}