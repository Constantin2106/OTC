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

	namespace SeriesControl
	{
		// Serie pick/unpick control
		void __fastcall PickSerie(TObject* Object);
		void __fastcall UnPickSerie(TObject* Object);
		bool IsPicked(const TChartSeries* serie);

		// Speed restriction seire control
		void CreateSpeedLimitSerie(TChart* gridChart,
			const Types::Parameters::GridParameters& gridParams);
		void AddSpeedLimitPoint(TChartSeries* pickedSerie,
			const Types::Parameters::GridPoint point,
			const Types::Parameters::GridParameters& gridParams);
		void RemoveLastSpeedLimitPoint();
	}
}

//---------------------------------------------------------------------------
#endif
