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
		void SetSpeedLimitPoint(TChartSeries* pickedSerie, int X, int Y, const Types::Parameters::GridParameters& gridParams);
	}

	namespace SeriesControl
	{
		void __fastcall PickSerie(TObject* Object);
		void __fastcall UnPickSerie(TObject* Object);

		bool IsPicked(const TChartSeries* serie);

        void RemoveLastSpeedLimitPoint();
	}
}

//---------------------------------------------------------------------------
#endif
