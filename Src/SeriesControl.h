//---------------------------------------------------------------------------

#ifndef SeriesControlH
#define SeriesControlH

#include "SmartCardPCH.h"

namespace SmartGrid
{
	namespace SeriesControl
	{
		// Serie pick/unpick control
		void __fastcall PickSerie(TObject* Object);
		void __fastcall UnPickSerie(TObject* Object);
		bool IsPicked(const TChartSeries* serie);

		TLineSeries* AddLineSerie(TChart* chart);
		TNotifyEvent& BindNotifyEvent(TChartSeries* serie, void __fastcall (*func)(TObject* Object));
        void SetSerieParams(TLineSeries* serie);

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

