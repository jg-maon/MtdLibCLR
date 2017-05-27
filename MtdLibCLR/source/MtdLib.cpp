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
	// m_hImpl��GC�̉���ɔC����
}

bool MtdLib::IsRead::get()
{
	return m_hImpl->IsRead;
}

// MTD�t�@�C���̓ǂݍ���
bool MtdLib::Read(String^ filePath)
{
	return m_hImpl->Read(filePath);
}

// MTD�t�@�C���̏�������
bool MtdLib::Write(String^ filePath)
{
	return m_hImpl->Write(filePath);
}

// SPX�t�@�C���p�X�̐ݒ�
bool MtdLib::SetSPXPath(String^ spx)
{
	return m_hImpl->SetSPXPath(spx);
}
// SPX�t�@�C���p�X�̎擾
bool MtdLib::GetSPXPath(String^% spx)
{
	return m_hImpl->GetSPXPath(spx);
}

// �}�e���A���p�����[�^�̐ݒ�
bool MtdLib::SetParam(String^ paramName, array<float>^ val)
{
	return m_hImpl->SetParam(paramName, val);
}
// �}�e���A���p�����[�^�̐ݒ�
bool MtdLib::SetParam(String^ paramName, array<int>^ val)
{
	return m_hImpl->SetParam(paramName, val);
}
// �}�e���A���p�����[�^�̐ݒ�
bool MtdLib::SetParam(String^ paramName, array<bool>^ val)
{
	return m_hImpl->SetParam(paramName, val);
}

// �e�N�X�`���}�b�v�p�����[�^�̐ݒ�
bool MtdLib::SetTexmap(String^ texmapName, String^ texPath, float u, float v)
{
	return m_hImpl->SetTexmap(texmapName, texPath, u, v);
}


// �}�e���A���p�����[�^�̎擾
bool MtdLib::GetParam(String^ paramName, array<float>^ val)
{
	return m_hImpl->GetParam(paramName, val);
}
// �}�e���A���p�����[�^�̎擾
bool MtdLib::GetParam(String^ paramName, array<int>^ val)
{
	return m_hImpl->GetParam(paramName, val);
}
// �}�e���A���p�����[�^�̎擾
bool MtdLib::GetParam(String^ paramName, array<bool>^ val)
{
	return m_hImpl->GetParam(paramName, val);
}
// �e�N�X�`���}�b�v�p�����[�^�̎擾
bool MtdLib::GetTexmap(String^ texmapName, String^% outTexPath, array<float>^ outTilingScale)
{
	return m_hImpl->GetTexmap(texmapName, outTexPath, outTilingScale);
}

