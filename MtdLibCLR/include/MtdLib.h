#pragma once


using namespace System;

namespace MtdLibCLR
{
	namespace MtdLibCLRInternal
	{
		ref class MtdLibImpl;
	}

	public ref class MtdLib
	{
	public:
		/**
			@brief		�R���X�g���N�^
		*/
		MtdLib();
		/**
			@brief		�f�X�g���N�^
		*/
		~MtdLib();

		/**
			@brief		�t�@�C�i���C�U
		*/
		!MtdLib();


	public:
		
		/**
			@brief		�ǂݍ��ݍς݂��擾
		*/
		property bool IsRead {
			/**
				@brief		�ǂݍ��ݍς݂��擾
				@return		�ǂݍ��ݍς݂�
			*/
			bool get();
		}

	public:
		/**
			@biref		MTD�t�@�C���̓ǂݍ���
			@param[in]	filePath	�t�@�C���p�X
			@return		��������
		*/
		bool Read(String^ filePath);

		/**
			@biref		MTD�t�@�C���̏�������
			@param[in]	filePath	�t�@�C���p�X
			@return		��������
		*/
		bool Write(String^ filePath);

		/**
			@brief		SPX�t�@�C���p�X�̐ݒ�
			@param[in]	spx	SPX�t�@�C���p�X
			@return		��������
		*/
		bool SetSPXPath(String^ spx);
		
		/**
			@brief		SPX�t�@�C���p�X�̎擾
			@param[out]	spx	SPX�t�@�C���p�X
			@return		��������
		*/
		bool GetSPXPath([Runtime::InteropServices::Out]String^% spx);


	public:

		/**
			@biref		�}�e���A���p�����[�^�̐ݒ�
			@param[in]	paramName	�}�e���A���p�����[�^���ʖ�
			@param[in]	val			�p�����[�^�z��
			@return		��������
		*/
		bool SetParam(String^ paramName, array<float>^ val);
		/**
			@biref		�}�e���A���p�����[�^�̐ݒ�
			@param[in]	paramName	�}�e���A���p�����[�^���ʖ�
			@param[in]	val			�p�����[�^�z��
			@return		��������
		*/
		bool SetParam(String^ paramName, array<int>^ val);
		/**
			@biref		�}�e���A���p�����[�^�̐ݒ�
			@param[in]	paramName	�}�e���A���p�����[�^���ʖ�
			@param[in]	val			�p�����[�^�z��
			@return		��������
		*/
		bool SetParam(String^ paramName, array<bool>^ val);
		
		/**
			@brief		�e�N�X�`���}�b�v�p�����[�^�̐ݒ�
			@param[in]	texmapName	�e�N�X�`���}�b�v���ʖ�
			@param[in]	texPath		�e�N�X�`���t�@�C���p�X
			@param[in]	v			V�����̃e�N�X�`���^�C�����O�X�P�[��
			@param[in]	u			U�����̃e�N�X�`���^�C�����O�X�P�[��
			@return		��������
		*/
		bool SetTexmap(String^ texmapName, String^ texPath, float u, float v);






		/**
			@biref		�}�e���A���p�����[�^�̎擾
			@param[in]	paramName	�}�e���A���p�����[�^���ʖ�
			@param[out]	outVal		�p�����[�^�z��
			@return		��������
		*/
		bool GetParam(String^ paramName, array<float>^ outVal);
		/**
			@biref		�}�e���A���p�����[�^�̎擾
			@param[in]	paramName	�}�e���A���p�����[�^���ʖ�
			@param[out]	outVal		�p�����[�^�z��
			@return		��������
		*/
		bool GetParam(String^ paramName, array<int>^ outVal);
		/**
			@biref		�}�e���A���p�����[�^�̎擾
			@param[in]	paramName	�}�e���A���p�����[�^���ʖ�
			@param[out]	outVal		�p�����[�^�z��
			@return		��������
		*/
		bool GetParam(String^ paramName, array<bool>^ outVal);

		/**
			@brief		�e�N�X�`���}�b�v�p�����[�^�̎擾
			@param[in]	texmapName		�e�N�X�`���}�b�v�p�����[�^
			@param[out]	outTexPath		�e�N�X�`���p�X
			@param[out]	outTilingScale	�^�C�����O�X�P�[��
			@return		��������
		*/
		bool GetTexmap(String^ texmapName, [Runtime::InteropServices::Out]String^% outTexPath, array<float>^ outTilingScale);


	private:

		MtdLibCLRInternal::MtdLibImpl^ m_hImpl;	//!< ����

	};

}

