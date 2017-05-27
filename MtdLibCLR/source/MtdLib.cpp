#include "Stdafx.h"
#include "MtdLib.h"

#include "MtdLibImpl.h"

using namespace MtdLibCLR;
using namespace MtdLibCLRInternal;

MtdLib::MtdLib()
{
	m_hImpl = gcnew MtdLibImpl();
}

MtdLib::~MtdLib()
{
	this->!MtdLib();
}

MtdLib::!MtdLib()
{
	// m_hImplはGCの解放に任せる
}

bool MtdLib::IsRead::get()
{
	return m_hImpl->IsRead;
}

// MTDファイルの読み込み
bool MtdLib::Read(String^ filePath)
{
	return m_hImpl->Read(filePath);
}

// MTDファイルの書き込み
bool MtdLib::Write(String^ filePath)
{
	return m_hImpl->Write(filePath);
}

// SPXファイルパスの設定
bool MtdLib::SetSPXPath(String^ spx)
{
	return m_hImpl->SetSPXPath(spx);
}
// SPXファイルパスの取得
bool MtdLib::GetSPXPath(String^% spx)
{
	return m_hImpl->GetSPXPath(spx);
}

// マテリアルパラメータの設定
bool MtdLib::SetParam(String^ paramName, array<float>^ val)
{
	return m_hImpl->SetParam(paramName, val);
}
// マテリアルパラメータの設定
bool MtdLib::SetParam(String^ paramName, array<int>^ val)
{
	return m_hImpl->SetParam(paramName, val);
}
// マテリアルパラメータの設定
bool MtdLib::SetParam(String^ paramName, array<bool>^ val)
{
	return m_hImpl->SetParam(paramName, val);
}

// テクスチャマップパラメータの設定
bool MtdLib::SetTexmap(String^ texmapName, String^ texPath, float u, float v)
{
	return m_hImpl->SetTexmap(texmapName, texPath, u, v);
}


// マテリアルパラメータの取得
bool MtdLib::GetParam(String^ paramName, array<float>^ val)
{
	return m_hImpl->GetParam(paramName, val);
}
// マテリアルパラメータの取得
bool MtdLib::GetParam(String^ paramName, array<int>^ val)
{
	return m_hImpl->GetParam(paramName, val);
}
// マテリアルパラメータの取得
bool MtdLib::GetParam(String^ paramName, array<bool>^ val)
{
	return m_hImpl->GetParam(paramName, val);
}
// テクスチャマップパラメータの取得
bool MtdLib::GetTexmap(String^ texmapName, String^% outTexPath, array<float>^ outTilingScale)
{
	return m_hImpl->GetTexmap(texmapName, outTexPath, outTilingScale);
}

