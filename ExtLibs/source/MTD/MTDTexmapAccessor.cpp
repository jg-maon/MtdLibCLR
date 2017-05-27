#include "stdafx.h"
#include "MTD\MTDTexmapAccessor.h"

using namespace MTD;

void MTDTexmapAccessorConst::GetPath(DLAsciiString & texPath)
{
	texPath = m_TexPath;
}
void MTDTexmapAccessorConst::GetTiling(DL_VECTOR2 & tiling)
{
	tiling = m_tilingUV;
}

void MTDTexmapAccessor::SetPath(const DLAsciiString& texPath)
{
	m_TexPath = texPath;
}
void MTDTexmapAccessor::SetTiling(const DL_VECTOR2 & tiling)
{
	m_tilingUV = tiling;
}
