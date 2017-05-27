#pragma once
#ifndef	__MtdLibCLR_MtdLibWrapper_h__
#define __MtdLibCLR_MtdLibWrapper_h__

#include "MTD\MTDMaterialData.h"

namespace MtdLibCLR
{
	namespace MtdLibCLRInternal
	{
		class MTDLibWrapper
		{
		public:
			/**
				@biref		�R���X�g���N�^
			*/
			MTDLibWrapper();
			/**
				@brief		�f�X�g���N�^
			*/
			virtual ~MTDLibWrapper();

		public:

#pragma region MTDLib methods

			/**
				@biref		MTD�t�@�C���̓ǂݍ���
				@param[in]	filePath	�t�@�C���p�X
				@return		��������
			*/
			bool Read(const DLString& filePath);

			/**
				@biref		MTD�t�@�C���̓ǂݍ���
				@param[in]	filePath	�t�@�C���p�X
				@return		��������
			*/
			bool Read(const DLAsciiString& filePath);


			/**
				@biref		MTD�t�@�C���̏�������
				@param[in]	filePath	�t�@�C���p�X
				@return		��������
			*/
			bool Write(const DLString& filePath);

			/**
				@biref		MTD�t�@�C���̏�������
				@param[in]	filePath	�t�@�C���p�X
				@return		��������
			*/
			bool Write(const DLAsciiString& filePath);

			/**
				@brief		SPX�t�@�C���p�X�̐ݒ�
				@param[in]	spx	SPX�t�@�C���p�X
				@return		��������
			*/
			bool SetSPXPath(const DLString& spx);
			
			/**
				@brief		SPX�t�@�C���p�X�̎擾
				@param[out]	spx	SPX�t�@�C���p�X
				@return		��������
			*/
			bool GetSPXPath(DLString& spx);

#pragma endregion	// #pragma region MTDLib methods

		public:

#pragma region Extends methods

			/**
				@biref		�}�e���A���p�����[�^�̐ݒ�
				@param[in]	name	�}�e���A���p�����[�^���ʖ�
				@param[in]	val		�p�����[�^�z��
				@param[in]	elemNum	�z��v�f��
				@return		��������
			*/
			bool SetParam(const DLAsciiString& name, const float val[], int elemNum);
			/**
				@biref		�}�e���A���p�����[�^�̐ݒ�
				@param[in]	name	�}�e���A���p�����[�^���ʖ�
				@param[in]	val		�p�����[�^�z��
				@param[in]	elemNum	�z��v�f��
				@return		��������
			*/
			bool SetParam(const DLAsciiString& name, const int val[], int elemNum);
			/**
				@biref		�}�e���A���p�����[�^�̐ݒ�
				@param[in]	name	�}�e���A���p�����[�^���ʖ�
				@param[in]	val		�p�����[�^�z��
				@param[in]	elemNum	�z��v�f��
				@return		��������
			*/
			bool SetParam(const DLAsciiString& name, const bool val[], int elemNum);


			/**
				@brief		�e�N�X�`���}�b�v�p�����[�^�̐ݒ�
				@param[in]	name			�e�N�X�`���}�b�v���ʖ�
				@param[in]	texPath			�e�N�X�`���t�@�C���p�X
				@param[in]	tilingUScale	U�����̃e�N�X�`���^�C�����O�X�P�[��
				@param[in]	tilingVScale	V�����̃e�N�X�`���^�C�����O�X�P�[��
				@return		��������
			*/
			bool SetTexmap(const DLAsciiString& name, const DLAsciiString& texPath, float tilingUScale, float tilingVScale);


			/**
				@brief		�}�e���A���p�����[�^�̎擾
				@param[in]	name	�}�e���A���p�����[�^���ʖ�
				@param[out]	outVal	�p�����[�^�z��
				@return		��������
			*/
			bool GetParam(const DLAsciiString& name, DL_VECTOR4& outVal) const;
			
			/**
				@param[in]	name			�e�N�X�`���}�b�v���ʖ�
				@param[out]	texPath			�e�N�X�`���t�@�C���p�X
				@param[out]	outTilingScale	�e�N�X�`���^�C�����O�X�P�[��
				@return		��������
			*/
			bool GetTexmap(const DLAsciiString& name, DLAsciiString& texPath, DL_VECTOR2& outTilingScale) const;


#pragma endregion	// #pragma region Extends methods

		private:

			MTD::MTDMaterialData	m_Lib;	//!< MTDLib

		};
	}	// namespace MtdLibCLRInternal
}	// namespace MtdLibCLR


#endif	// __MtdLibCLR_MtdLibWrapper_h__