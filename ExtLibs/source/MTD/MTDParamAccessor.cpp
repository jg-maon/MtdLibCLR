#include "stdafx.h"
#include "MTD\MTDParamAccessor.h"

using namespace MTD;

MTDParamAccessorConst::MTDParamAccessorConst(bool valid/*=true*/)
	: m_IsValid(valid)
{
}

MTDParamAccessorConst::~MTDParamAccessorConst()
{
}

void MTDParamAccessorConst::GetValue(DL_VECTOR4& v)
{
	v = m_Val;
}

MTDParamAccessor::MTDParamAccessor(bool valid/*=true*/)
	: MTDParamAccessorConst(valid)
{}

MTDParamAccessor::~MTDParamAccessor()
{}

void MTD::MTDParamAccessor::SetValue(const DL_VECTOR4 & v)
{
	m_Val = v;
}

