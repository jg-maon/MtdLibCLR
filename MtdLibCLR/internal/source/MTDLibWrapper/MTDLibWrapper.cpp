#include "stdafx.h"
#include "MTDLibWrapper.h"


#include "MTD\MTDParamAccessor.h"
#include "MTD\MTDTexmapAccessor.h"

using namespace MTD;
using namespace MtdLibCLR;
using namespace MtdLibCLR::MtdLibCLRInternal;


// コンストラクタ
MTDLibWrapper::MTDLibWrapper()
	: m_Lib()
{
	
}

// デストラクタ
MTDLibWrapper::~MTDLibWrapper()
{
}

// MTDファイルの読み込み
bool MTDLibWrapper::Read(const DLString& filePath)
{
	return m_Lib.Read(filePath);
}

// MTDファイルの読み込み
bool MTDLibWrapper::Read(const DLAsciiString& filePath)
{
	return m_Lib.Read(filePath);
}

// MTDファイルの書き込み
bool MTDLibWrapper::Write(const DLString& filePath)
{
	return m_Lib.Write(filePath);
}

// MTDファイルの書き込み
bool MTDLibWrapper::Write(const DLAsciiString& filePath)
{
	return m_Lib.Write(filePath);
}

// SPXファイルパスの設定
bool MTDLibWrapper::SetSPXPath(const DLString& spx)
{
	return m_Lib.SetSPXPath(spx);
}
// SPXファイルパスの取得
bool MTDLibWrapper::GetSPXPath(DLString& spx)
{
	return m_Lib.GetSPXPath(spx);
}

// マテリアルパラメータの設定
bool MTDLibWrapper::SetParam(const DLAsciiString& name, const float val[], int elemNum)
{
	// アクセサの取得
	printf("\tFind(%s)\n", name.c_str());
	MTDParamAccessor& Acsr = m_Lib.FindParam(name);

	if (!Acsr.IsValid())
	{
		return false;
	}

	printf("\t\tSet(%d)\n", elemNum);
	DL_VECTOR4 v = {};
	//for (int i = 0; i < elemNum; ++i)
	//{
	//	v.v[i] = val[i];
	//}
	DLMemory::Copy(&v, val, sizeof(float)*elemNum);


	Acsr.SetValue(v);


	return true;
}

// マテリアルパラメータの設定
bool MTDLibWrapper::SetParam(const DLAsciiString & name, const int val[], int elemNum)
{
	// アクセサの取得
	printf("\tFind(%s)\n", name.c_str());
	MTDParamAccessor& Acsr = m_Lib.FindParam(name);

	if (!Acsr.IsValid())
	{
		return false;
	}

	printf("\t\tSet(%d)\n", elemNum);
	DL_VECTOR4 v = {};
	//for (int i = 0; i < elemNum; ++i)
	//{
	//	v.v[i] = val[i];
	//}
	DLMemory::Copy(&v, val, sizeof(int)*elemNum);


	Acsr.SetValue(v);


	return true;
}

// マテリアルパラメータの設定
bool MTDLibWrapper::SetParam(const DLAsciiString & name, const bool val[], int elemNum)
{
	// アクセサの取得
	printf("\tFind(%s)\n", name.c_str());
	MTDParamAccessor& Acsr = m_Lib.FindParam(name);

	if (!Acsr.IsValid())
	{
		return false;
	}

	printf("\t\tSet(%d)\n", elemNum);
	DL_VECTOR4 v = {};
	for (int i = 0; i < elemNum; ++i)
	{
		v.s[i] = val[i] ? 1 : 0;
	}


	Acsr.SetValue(v);


	return true;
}

// テクスチャマップパラメータの設定
bool MTDLibWrapper::SetTexmap(const DLAsciiString & name, const DLAsciiString & texPath, float tilingUScale, float tilingVScale)
{
	// アクセサの取得
	printf("\tFind(%s)\n", name.c_str());
	MTDTexmapAccessor& Acsr = m_Lib.FindTexmap(name);

	if (!Acsr.IsValid())
	{
		return false;
	}

	DL_VECTOR2 tiling = DLIVec2::Set(tilingUScale, tilingVScale);

	printf("\t\tSet(%s, %f,%f)\n", texPath.c_str(), tiling.x, tiling.y);
	Acsr.SetPath(texPath);

	Acsr.SetTiling(tiling);

	return true;
}


// マテリアルパラメータの取得
bool MTDLibWrapper::GetParam(const DLAsciiString& name, DL_VECTOR4& outVal) const
{
	MTDParamAccessorConst Acsr = m_Lib.FindParam(name);
	if (!Acsr.IsValid())
	{
		return false;
	}
	Acsr.GetValue(outVal);

	return true;
}

// テクスチャマップパラメータの取得
bool MTDLibWrapper::GetTexmap(const DLAsciiString& name, DLAsciiString& texPath, DL_VECTOR2& outTilingScale) const
{
	MTDTexmapAccessorConst Acsr = m_Lib.FindTexmap(name);
	if (!Acsr.IsValid())
	{
		return false;
	}

	Acsr.GetPath(texPath);
	Acsr.GetTiling(outTilingScale);

	return true;
}