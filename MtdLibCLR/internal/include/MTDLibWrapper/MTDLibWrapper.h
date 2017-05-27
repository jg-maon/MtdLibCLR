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
				@biref		コンストラクタ
			*/
			MTDLibWrapper();
			/**
				@brief		デストラクタ
			*/
			virtual ~MTDLibWrapper();

		public:

#pragma region MTDLib methods

			/**
				@biref		MTDファイルの読み込み
				@param[in]	filePath	ファイルパス
				@return		成功判定
			*/
			bool Read(const DLString& filePath);

			/**
				@biref		MTDファイルの読み込み
				@param[in]	filePath	ファイルパス
				@return		成功判定
			*/
			bool Read(const DLAsciiString& filePath);


			/**
				@biref		MTDファイルの書き込み
				@param[in]	filePath	ファイルパス
				@return		成功判定
			*/
			bool Write(const DLString& filePath);

			/**
				@biref		MTDファイルの書き込み
				@param[in]	filePath	ファイルパス
				@return		成功判定
			*/
			bool Write(const DLAsciiString& filePath);

			/**
				@brief		SPXファイルパスの設定
				@param[in]	spx	SPXファイルパス
				@return		成功判定
			*/
			bool SetSPXPath(const DLString& spx);
			
			/**
				@brief		SPXファイルパスの取得
				@param[out]	spx	SPXファイルパス
				@return		成功判定
			*/
			bool GetSPXPath(DLString& spx);

#pragma endregion	// #pragma region MTDLib methods

		public:

#pragma region Extends methods

			/**
				@biref		マテリアルパラメータの設定
				@param[in]	name	マテリアルパラメータ識別名
				@param[in]	val		パラメータ配列
				@param[in]	elemNum	配列要素数
				@return		成功判定
			*/
			bool SetParam(const DLAsciiString& name, const float val[], int elemNum);
			/**
				@biref		マテリアルパラメータの設定
				@param[in]	name	マテリアルパラメータ識別名
				@param[in]	val		パラメータ配列
				@param[in]	elemNum	配列要素数
				@return		成功判定
			*/
			bool SetParam(const DLAsciiString& name, const int val[], int elemNum);
			/**
				@biref		マテリアルパラメータの設定
				@param[in]	name	マテリアルパラメータ識別名
				@param[in]	val		パラメータ配列
				@param[in]	elemNum	配列要素数
				@return		成功判定
			*/
			bool SetParam(const DLAsciiString& name, const bool val[], int elemNum);


			/**
				@brief		テクスチャマップパラメータの設定
				@param[in]	name			テクスチャマップ識別名
				@param[in]	texPath			テクスチャファイルパス
				@param[in]	tilingUScale	U方向のテクスチャタイリングスケール
				@param[in]	tilingVScale	V方向のテクスチャタイリングスケール
				@return		成功判定
			*/
			bool SetTexmap(const DLAsciiString& name, const DLAsciiString& texPath, float tilingUScale, float tilingVScale);


			/**
				@brief		マテリアルパラメータの取得
				@param[in]	name	マテリアルパラメータ識別名
				@param[out]	outVal	パラメータ配列
				@return		成功判定
			*/
			bool GetParam(const DLAsciiString& name, DL_VECTOR4& outVal) const;
			
			/**
				@param[in]	name			テクスチャマップ識別名
				@param[out]	texPath			テクスチャファイルパス
				@param[out]	outTilingScale	テクスチャタイリングスケール
				@return		成功判定
			*/
			bool GetTexmap(const DLAsciiString& name, DLAsciiString& texPath, DL_VECTOR2& outTilingScale) const;


#pragma endregion	// #pragma region Extends methods

		private:

			MTD::MTDMaterialData	m_Lib;	//!< MTDLib

		};
	}	// namespace MtdLibCLRInternal
}	// namespace MtdLibCLR


#endif	// __MtdLibCLR_MtdLibWrapper_h__