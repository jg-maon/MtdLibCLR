// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。

#pragma once


#ifndef SAFE_DELETE
#define SAFE_DELETE(p) do { if (p) { delete p; p = nullptr; } } while (0)
#endif