//---------------------------------------------------------------------------

#ifndef GridControlH
#define GridControlH

#include "SmartCardPCH.h"
#include "Types.h"

namespace SmartGrid
{
	namespace GridControl
	{
		bool BuildGrid(TChart* gridChart, const Types::Parameters::GridParameters& gridParams);
	}
}

//---------------------------------------------------------------------------
#endif
