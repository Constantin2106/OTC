//---------------------------------------------------------------------------

#ifndef GridControlH
#define GridControlH

#include "SmartCardPCH.h"

namespace SmartGrid
{
	namespace GridControl
	{
        void SetAxisLabels(TChartAxis* axis, int min, int max, int step);
		bool BuildGrid(TChart* gridChart, const Types::Parameters::GridParameters& gridParams);
	}
}

//---------------------------------------------------------------------------
#endif
