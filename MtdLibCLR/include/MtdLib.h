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
			@brief		コンストラクタ
		*/
		MtdLib();
		/**
			@brief		デストラクタ
		*/
		~MtdLib();

		/**
			@brief		ファイナライザ
		*/
		!MtdLib();


	public:
		
		/**
			@brief		読み込み済みか取得
		*/
		property bool IsRead {
			/**
				@brief		読み込み済みか取得
				@return		読み込み済みか
			*/
			bool get();
		}

	public:
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


	public:

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

		MtdLibCLRInternal::MtdLibImpl^ m_hImpl;	//!< 実装

	};

}

