#pragma once

#include "DLVec.hpp"

namespace MTD
{

	class MTDParamAccessorConst
	{
	public:
		explicit MTDParamAccessorConst(bool valid = true);
		virtual ~MTDParamAccessorConst();

		void GetValue(DL_VECTOR4& v);


		bool IsValid() const {
			return m_IsValid;
		}
		bool m_IsValid;
	protected:

		DL_VECTOR4 m_Val;
	};

	class MTDParamAccessor : public MTDParamAccessorConst
	{
	public:
		explicit MTDParamAccessor(bool valid=true);
		virtual ~MTDParamAccessor();


		void SetValue(const DL_VECTOR4& v);

	};


}