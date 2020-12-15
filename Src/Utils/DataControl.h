//---------------------------------------------------------------------------

#ifndef DataControlH
#define DataControlH

#include "SmartCardPCH.h"

namespace SmartGrid
{
	namespace DataControl
	{
		bool WriteGridData(const Types::Parameters::GridParameters& gridParams, const std::string& fileName);
		bool ReadGridData(const std::string fileName, Types::Parameters::GridParameters& gridParams);
	}
}
//---------------------------------------------------------------------------
#endif
