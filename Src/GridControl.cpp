//---------------------------------------------------------------------------

#pragma hdrstop

#include "GridControl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include "GridControl.h"

#pragma region Utilities to work with chart and series
namespace
{
	void SetAxis(TChartAxis* axis, int min, int max, int step)
	{
		axis->Automatic = false;
		axis->Minimum = 0;
		axis->Maximum = 0;
		axis->Maximum = max;
		axis->Minimum = min;
		axis->Increment = step;
		axis->LabelsFont->Size = 10;
		axis->LabelsFont->Style = axis->LabelsFont->Style << fsBold;
	}

	TLineSeries* AddLineSerie(TChart* chart)
	{
		chart->AddSeries(new TLineSeries(chart));
		return static_cast<TLineSeries*>(chart->SeriesList->Last());
	}

	TNotifyEvent& BindNotifyEvent(TChartSeries* serie, void __fastcall (*func)(TObject* Object))
	{
		TMethod method;
		method.Data = serie;
		method.Code = reinterpret_cast<decltype(method.Code)>(func);
		return (TNotifyEvent&)method;
	}

	void SetSerieParams(TLineSeries* serie)
	{
		serie->Color = clGray;
		serie->ClickTolerance = 3;
		serie->Pen->Width = 2;
		serie->LinePen->Style = psDash;
		serie->OnMouseEnter = BindNotifyEvent(serie, SmartGrid::SeriesControl::PickSerie);
		serie->OnMouseLeave = BindNotifyEvent(serie, SmartGrid::SeriesControl::UnPickSerie);
	}
}
#pragma end_region

#pragma region Grid control
namespace SmartGrid::GridControl
{
	using namespace SmartGrid::Types;

	bool BuildGrid(TChart* gridChart, const Parameters::GridParameters& gridParams)
	{
		using namespace std;

		gridChart->SeriesList->Clear();

		// Set axis range
		SetAxis(gridChart->BottomAxis, 0, gridParams.Length, gridParams.Step);
		SetAxis(gridChart->LeftAxis, 0, gridParams.Vmax, gridParams.VStep);

		// Add grid lines
		for( int v = gridParams.Vmin; v <= gridParams.Vmax; v += gridParams.VStep )
		{
			auto serie = AddLineSerie(gridChart);

			serie->AddXY(0, v);
			serie->AddXY(gridParams.Length, v);
			SetSerieParams(serie);
		}

		for(int s = gridParams.Step; s <= gridParams.Length; s += gridParams.Step)
		{
			auto serie = AddLineSerie(gridChart);

			serie->AddXY(s, gridParams.Vmin);
			serie->AddXY(s, gridParams.Vmax);
			SetSerieParams(serie);
		}

		gridChart->Repaint();

		return true;
	}
}
#pragma end_region

#pragma region Serie control
namespace SmartGrid::SeriesControl
{
	static TLineSeries* limSpeedSerie{};

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
		if(!SmartGrid::SeriesControl::IsPicked(pickedSerie))
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
