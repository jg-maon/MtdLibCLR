
#pragma once
#ifndef __MtdLibCLR_MtdLibImpl_h__
#define __MtdLibCLR_MtdLibImpl_h__

using namespace System;

struct DL_VECTOR4;

namespace MtdLibCLR
{
	namespace MtdLibCLRInternal
	{
		class MTDLibWrapper;
	}
}

namespace MtdLibCLR
{
	namespace MtdLibCLRInternal
	{
		ref class MtdLibImpl
		{
		internal:
			/**
				@brief		コンストラクタ
			*/
			MtdLibImpl();
			/**
				@brief		デストラクタ
			*/
			~MtdLibImpl();

			/**
				@brief		ファイナライザ
			*/
			!MtdLibImpl();



		internal:

			/**
				@brief		読み込み済みか取得
			*/
			property bool IsRead {
				/**
					@brief		読み込み済みか取得
					@return		読み込み済みか
				*/
				bool get()
				{
					return nullptr != m_pMTDLibWrapper;
				}
			}

			
		internal:
			/**
				@biref		MTDファイルの読み込み
				@param[in]	filePath	ファイルパス
				@return		成功判定
			*/
			bool Read(String^ filePath);

			/**
				@biref		MTDファイルの書き込み
				@param[in]	filePath	ファイルパス
				@return		成功判定
			*/
			bool Write(String^ filePath);

			/**
				@brief		SPXファイルパスの設定
				@param[in]	spx	SPXファイルパス
				@return		成功判定
			*/
			bool SetSPXPath(String^ spx);
			
			/**
				@brief		SPXファイルパスの取得
				@param[out]	spx	SPXファイルパス
				@return		成功判定
			*/
			bool GetSPXPath([Runtime::InteropServices::Out]String^% spx);


		internal:

			/**
				@biref		マテリアルパラメータの設定
				@param[in]	paramName	マテリアルパラメータ識別名
				@param[in]	val			パラメータ配列
				@return		成功判定
			*/
			bool SetParam(String^ paramName, array<float>^ val);
			/**
				@biref		マテリアルパラメータの設定
				@param[in]	paramName	マテリアルパラメータ識別名
				@param[in]	val			パラメータ配列
				@return		成功判定
			*/
			bool SetParam(String^ paramName, array<int>^ val);
			/**
				@biref		マテリアルパラメータの設定
				@param[in]	paramName	マテリアルパラメータ識別名
				@param[in]	val			パラメータ配列
				@return		成功判定
			*/
			bool SetParam(String^ paramName, array<bool>^ val);
		
			/**
				@brief		テクスチャマップパラメータの設定
				@param[in]	texmapName	テクスチャマップ識別名
				@param[in]	texPath		テクスチャファイルパス
				@param[in]	v			V方向のテクスチャタイリングスケール
				@param[in]	u			U方向のテクスチャタイリングスケール
				@return		成功判定
			*/
			bool SetTexmap(String^ texmapName, String^ texPath, float u, float v);
		


			/**
				@biref		マテリアルパラメータの取得
				@param[in]	paramName	マテリアルパラメータ識別名
				@param[out]	outVal		パラメータ配列
				@return		成功判定
			*/
			bool GetParam(String^ paramName, array<float>^ outVal);
			/**
				@biref		マテリアルパラメータの取得
				@param[in]	paramName	マテリアルパラメータ識別名
				@param[out]	outVal		パラメータ配列
				@return		成功判定
			*/
			bool GetParam(String^ paramName, array<int>^ outVal);
			/**
				@biref		マテリアルパラメータの取得
				@param[in]	paramName	マテリアルパラメータ識別名
				@param[out]	outVal		パラメータ配列
				@return		成功判定
			*/
			bool GetParam(String^ paramName, array<bool>^ outVal);

			/**
				@brief		テクスチャマップパラメータの取得
				@param[in]	texmapName		テクスチャマップパラメータ
				@param[out]	outTexPath		テクスチャパス
				@param[out]	outTilingScale	タイリングスケール
				@return		成功判定
			*/
			bool GetTexmap(String^ texmapName, [Runtime::InteropServices::Out]String^% outTexPath, array<float>^ outTilingScale);

		private:
			bool _GetParam(String^ paramName, DL_VECTOR4& outVal);

		private:

			MTDLibWrapper*	m_pMTDLibWrapper;	//!< ライブラリラッパー

		};

	}	// namespace MtdLibCLRInternal

}	// namespace MtdLibCLR

#endif	// __MtdLibCLR_MtdLibImpl_h__