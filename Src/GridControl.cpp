//---------------------------------------------------------------------------

#pragma hdrstop

#include "GridControl.h"
#include "SeriesControl.h"
#include "Utils/Utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma region Grid control
namespace SmartGrid::GridControl
{
	using namespace SmartGrid::Types;

	void SetAxisLabels(TChartAxis* axis, int min, int max, int step)
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

	bool BuildGrid(TChart* gridChart, const Parameters::GridParameters& gridParams)
	{
		using namespace std;

		gridChart->SeriesList->Clear();

		// Set axis range
		SetAxisLabels(gridChart->BottomAxis, 0, gridParams.Length, gridParams.Step);
		SetAxisLabels(gridChart->LeftAxis, 0, gridParams.Vmax, gridParams.VStep);

		// Add grid lines
		for( int v = gridParams.Vmin; v <= gridParams.Vmax; v += gridParams.VStep )
		{
			auto serie = SmartGrid::SeriesControl::AddLineSerie(gridChart);

			serie->AddXY(0, v);
			serie->AddXY(gridParams.Length, v);
			SmartGrid::SeriesControl::SetSerieParams(serie);
		}

		for(int s = gridParams.Step; s <= gridParams.Length; s += gridParams.Step)
		{
			auto serie = SmartGrid::SeriesControl::AddLineSerie(gridChart);

			serie->AddXY(s, gridParams.Vmin);
			serie->AddXY(s, gridParams.Vmax);
			SmartGrid::SeriesControl::SetSerieParams(serie);
		}

		gridChart->Repaint();

		return true;
	}
}
#pragma end_region


