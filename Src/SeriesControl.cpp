//---------------------------------------------------------------------------

#pragma hdrstop

#include "SeriesControl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma region Serie control
namespace SmartGrid::SeriesControl
{
	namespace
	{
		static TLineSeries* limSpeedSerie{};
	}

	using namespace SmartGrid::Types;

	// Set serie's picked flag
	void __fastcall PickSerie(TObject* Object)
	{
		auto serie = dynamic_cast<TLineSeries*>(Object);
		if(serie)
			serie->Tag = 1;
	}
	// Reset serie's picked flag
	void __fastcall UnPickSerie(TObject* Object)
	{
		auto serie = dynamic_cast<TLineSeries*>(Object);
		if(serie)
			serie->Tag = 0;
	}
	// Check serie's picked flag
	bool IsPicked(const TChartSeries* serie)
	{
		return serie->Tag == 1;
	}
	// Add new TLineSeries
	TLineSeries* AddLineSerie(TChart* chart)
	{
		chart->AddSeries(new TLineSeries(chart));
		return static_cast<TLineSeries*>(chart->SeriesList->Last());
	}
	// Create notificatiton event handler
	TNotifyEvent& CreateNotifyEvent(TChartSeries* serie, void __fastcall (*func)(TObject* Object))
	{
		TMethod method;
		method.Data = serie;
		method.Code = reinterpret_cast<decltype(method.Code)>(func);
		return (TNotifyEvent&)method;
	}
	// Set serie parameters
	void SetSerieParams(TLineSeries* serie)
	{
		serie->Color = clGray;
		serie->ClickTolerance = 3;
		serie->Pen->Width = 2;
		serie->LinePen->Style = psDash;
		serie->OnMouseEnter = CreateNotifyEvent(serie, PickSerie);
		serie->OnMouseLeave = CreateNotifyEvent(serie, UnPickSerie);
	}

	// Create speed restriction serie
	void CreateSpeedLimitSerie(TChart* gridChart, const Parameters::GridParameters& gridParams)
	{
		// Add speed restriction line
		limSpeedSerie = AddLineSerie(gridChart);
		limSpeedSerie->Color = clBlack;
		limSpeedSerie->Pen->Width = 5;
		//limSpeedSerie->Stairs = true;
		limSpeedSerie->AddXY(Parameters::S_MIN, gridParams.Vmin);
	}
	// Add a new speed restriction point
	void AddSpeedLimitPoint(TChartSeries* pickedSerie,
		const Parameters::GridPoint point,
		const Parameters::GridParameters& gridParams)
	{
		if(!IsPicked(pickedSerie))
			return;

		auto chart = pickedSerie->ParentChart;

		for(const auto& serie : chart->SeriesList)
		{
			if(serie->Tag)
			{
				auto roundedS = static_cast<int>(Math::RoundTo(serie->XScreenToValue(point.X), 2));

				double vStep = gridParams.VStep;
				double vHalfStep = vStep / 2;
				auto actualV = serie->YScreenToValue(point.Y);
				auto roundedV = fmod(actualV, vStep) > vHalfStep ?
					static_cast<int>(actualV) + 1 :
					static_cast<int>(actualV);

				limSpeedSerie->AddXY(roundedS, roundedV);
				//ShowMessage(String("Serie s = ") + IntToStr(roundedS) + String(" v = ") + IntToStr(roundedV));

				return;
			}
		}
	}

	void RemoveLastSpeedLimitPoint()
	{
		auto size = limSpeedSerie->Count();
		if(size > 1)
			limSpeedSerie->Delete(size - 1);
    }
}
#pragma end_region
