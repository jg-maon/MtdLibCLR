#include "Stdafx.h"
#include "MtdLibImpl.h"

#include "StringUtil.h"


#ifndef __MtdLibCLR_MtdLibWrapper_h__
#include "MTDLibWrapper\MTDLibWrapper.h"
#endif

//namespace StringUtil = MtdLibCLR::MtdLibCLRInternal::StringUtil;
using namespace MtdLibCLR;
using namespace MtdLibCLR::MtdLibCLRInternal;


// �R���X�g���N�^
MtdLibImpl::MtdLibImpl()
	: m_pMTDLibWrapper(nullptr)
{
}

// �f�X�g���N�^
MtdLibImpl::~MtdLibImpl()
{
	this->!MtdLibImpl();
}
// �t�@�C�i���C�U
MtdLibImpl::!MtdLibImpl()
{
	SAFE_DELETE(m_pMTDLibWrapper);
}


// MTD�t�@�C���̓ǂݍ���
bool MtdLibImpl::Read(String^ filePath)
{
	if (IsRead)
	{
		return true;
	}

	m_pMTDLibWrapper = new MTDLibWrapper();

	const std::string path = StringUtil::Convert(filePath);

	return m_pMTDLibWrapper->Read(path.c_str());
}

// MTD�t�@�C���̏�������
bool MtdLibImpl::Write(String^ filePath)
{
	if (!IsRead)
	{
		return false;
	}

	const std::string path = StringUtil::Convert(filePath);

	return m_pMTDLibWrapper->Write(path.c_str());
}

// SPX�t�@�C���p�X�̐ݒ�
bool MtdLibImpl::SetSPXPath(String^ spx)
{
	if (!IsRead)
	{
		return false;
	}

	const std::string path = StringUtil::Convert(spx);

	return m_pMTDLibWrapper->SetSPXPath(DLString(path.begin(), path.end()));
}
// SPX�t�@�C���p�X�̎擾
bool MtdLibImpl::GetSPXPath(String^% spx)
{
	if (!IsRead)
	{
		return false;
	}

	DLString path;
	if (!m_pMTDLibWrapper->GetSPXPath(path))
	{
		return false;
	}

	spx = StringUtil::Convert(path);

	return true;
}

// �}�e���A���p�����[�^�̐ݒ�
bool MtdLibImpl::SetParam(String^ paramName, array<float>^ val)
{
	if (!IsRead)
	{
		return false;
	}
	const std::string name = StringUtil::Convert(paramName);
	pin_ptr<float> ptr = &val[0];

	return m_pMTDLibWrapper->SetParam(name, static_cast<float*>(ptr), val->Length);
}
// �}�e���A���p�����[�^�̐ݒ�
bool MtdLibImpl::SetParam(String^ paramName, array<int>^ val)
{
	if (!IsRead)
	{
		return false;
	}
	const std::string name = StringUtil::Convert(paramName);
	pin_ptr<int> ptr = &val[0];

	return m_pMTDLibWrapper->SetParam(name, static_cast<int*>(ptr), val->Length);
}
// �}�e���A���p�����[�^�̐ݒ�
bool MtdLibImpl::SetParam(String^ paramName, array<bool>^ val)
{
	if (!IsRead)
	{
		return false;
	}
	const std::string name = StringUtil::Convert(paramName);
	pin_ptr<bool> ptr = &val[0];

	return m_pMTDLibWrapper->SetParam(name, static_cast<bool*>(ptr), val->Length);
}

// �e�N�X�`���}�b�v�p�����[�^�̐ݒ�
bool MtdLibImpl::SetTexmap(String^ texmapName, String^ texPath, float u, float v)
{
	if (!IsRead)
	{
		return false;
	}
	const std::string name = StringUtil::Convert(texmapName);
	const std::string path = StringUtil::Convert(texPath);
	
	return m_pMTDLibWrapper->SetTexmap(name, path, u, v);
}

// �}�e���A���p�����[�^�̎擾
bool MtdLibImpl::GetParam(String^ paramName, array<float>^ outVal)
{
	DL_VECTOR4 val;
	if (!_GetParam(paramName, val))
	{
		return false;
	}

	for (int i = 0; i < outVal->Length; ++i)
	{
		outVal[i] = val.v[i];
	}

	return true;
}


// �}�e���A���p�����[�^�̎擾
bool MtdLibImpl::GetParam(String^ paramName, array<int>^ outVal)
{
	DL_VECTOR4 val;
	if (!_GetParam(paramName, val))
	{
		return false;
	}

	for (int i = 0; i < outVal->Length; ++i)
	{
		outVal[i] = val.s[i];
	}

	return true;
}

// �}�e���A���p�����[�^�̎擾
bool MtdLibImpl::GetParam(String^ paramName, array<bool>^ outVal)
{
	DL_VECTOR4 val;
	if (!_GetParam(paramName, val))
	{
		return false;
	}

	for (int i = 0; i < outVal->Length; ++i)
	{
		outVal[i] = val.s[i] != 0;
	}
	return true;
}

bool MtdLibImpl::GetTexmap(String^ texmapName, String^% outTexPath, array<float>^ outTilingScale)
{
	if (!IsRead)
	{
		return false;
	}
	DL_VECTOR2 uv;
	DLAsciiString texPath;
	if (!m_pMTDLibWrapper->GetTexmap(StringUtil::Convert(texmapName), texPath, uv))
	{
		return false;
	}

	outTexPath = StringUtil::Convert(texPath);
	
	outTilingScale[0] = uv.x;
	outTilingScale[1] = uv.y;

	return true;
}


bool MtdLibImpl::_GetParam(String^ paramName, DL_VECTOR4& outVal)
{
	if (!IsRead)
	{
		return false;
	}
	DL_VECTOR4 val;
	const std::string name = StringUtil::Convert(paramName);
	if (!m_pMTDLibWrapper->GetParam(name, val))
	{
		return false;
	}
	outVal = val;
	return true;
}