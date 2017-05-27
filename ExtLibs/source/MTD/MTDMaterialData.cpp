
#include "stdafx.h"
#include "MTD\MTDMaterialData.h"

using namespace MTD;

bool MTD::MTDMaterialData::Read(const DLAsciiString & filePath)
{
	printf("Read:%s\n", filePath.c_str());
	{
		auto param = MTDParamAccessor();
		param.SetValue(DLIVec4::Set(1.f, 1.f, 1.f, 1.f));
		m_Params["g_diffuseMapColor"] = param;
	}
	{
		auto param = MTDParamAccessor();
		param.SetValue(DLIVec4::Set(1.f, 1.f, 1.f, 1.f));
		m_Params["param1"] = param;
	}
	{
		auto param = MTDParamAccessor();
		param.SetValue(DLIVec4::Set(0, 0, 0, 255));
		m_Params["param2"] = param;
	}
	{
		auto param = MTDParamAccessor();
		param.SetValue(DLIVec4::Set(1, 0, 0, 0));
		m_Params["param3"] = param;
	}



	{
		auto tex = MTDTexmapAccessor();
		tex.SetPath("N:\\GS\\RootBranch\\data\\ShaderAuthoringTool\\Image\\001.jpg");
		tex.SetTiling(DLIVec2::Set(1.0f, 1.0f));
		m_Texmaps["g_AlbedoMap"] = tex;
	}
	{
		auto tex = MTDTexmapAccessor();
		tex.SetPath("N:\\GS\\RootBranch\\c3000_n.tif");
		tex.SetTiling(DLIVec2::Set(1.0f, 1.0f));
		m_Texmaps["g_NormalMap"] = tex;
	}
	{
		auto tex = MTDTexmapAccessor();
		tex.SetPath("N:\\GS\\RootBranch\\c3000_s.tif");
		tex.SetTiling(DLIVec2::Set(1.0f, 1.0f));
		m_Texmaps["g_ShininessMap"] = tex;
	}
	{
		auto tex = MTDTexmapAccessor();
		tex.SetPath("N:\\GS\\RootBranch\\c3000detail_a.tif");
		tex.SetTiling(DLIVec2::Set(1.0f, 1.0f));
		m_Texmaps["g_AlbedoMap1"] = tex;
	}

	return true;
}

bool MTD::MTDMaterialData::Write(const DLAsciiString & filePath)
{
	printf("Write:%s\n", filePath.c_str());

	for (auto& pair : m_Params)
	{
		auto& Acsr = pair.second;
		auto& name = pair.first;
		DL_VECTOR4 val = {};
		Acsr.GetValue(std::ref(val));
		std::printf("[%s] : (%6f, %6f, %6f, %6f) : (%6d, %6d, %6d, %6d)\n",
			name.c_str(),
			val.x, val.y, val.z, val.w,
			val.ix, val.iy, val.iz, val.iw
		);
	}

	for (auto& pair : m_Texmaps)
	{
		auto& Acsr = pair.second;
		auto& name = pair.first;
		DLAsciiString path;
		DL_VECTOR2 tiling;
		Acsr.GetPath(path);
		Acsr.GetTiling(tiling);
		std::printf("[%s] (%.2f, %.2f) : %s\n", name.c_str(), tiling.x, tiling.y, path.c_str());
	}
	return true;
}

bool MTD::MTDMaterialData::Read(const DLString & filePath)
{
	Read(DLAsciiString(filePath.begin(), filePath.end()));
	return true;
}

bool MTD::MTDMaterialData::Write(const DLString & filePath)
{
	Write(DLAsciiString(filePath.begin(), filePath.end()));
	return true;
}

bool MTD::MTDMaterialData::SetSPXPath(const DLString& spx)
{
	m_Spx = spx;
	return true;
}
bool MTD::MTDMaterialData::GetSPXPath(DLString& spx)
{
	spx = m_Spx;
	return true;
}

static MTD::MTDParamAccessor s_dummyAcsr(false);
static MTD::MTDTexmapAccessor s_dummyTexAcsr(false);

MTDParamAccessor & MTD::MTDMaterialData::FindParam(const DLAsciiString & name)
{
	auto it = m_Params.find(name);
	if (m_Params.end() != it)
	{
		return it->second;
	}
	
	return s_dummyAcsr;
}

MTDTexmapAccessor & MTD::MTDMaterialData::FindTexmap(const DLAsciiString & name)
{
	auto it = m_Texmaps.find(name);
	if (m_Texmaps.end() != it)
	{
		return it->second;
	}

	return s_dummyTexAcsr;

}


MTDParamAccessorConst MTDMaterialData::FindParam(const DLAsciiString & name) const
{
	return const_cast<MTDMaterialData*>(this)->FindParam(name);
}

MTDTexmapAccessorConst MTDMaterialData::FindTexmap(const DLAsciiString & name) const
{
	return const_cast<MTDMaterialData*>(this)->FindTexmap(name);
}
