//---------------------------------------------------------------------------
#include <Math.h>
#pragma hdrstop

#include "MainUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace SmartGrid::Types::Parameters;
using namespace SmartGrid::GridControl;
using namespace SmartGrid::SeriesControl;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
const GridParameters& TForm1::GetGridParameters()
{
	return mGridParameters = {SStepUpDown->Position, RLengthUpDown->Position,
							  VminUpDown->Position, VmaxUpDown->Position, VStepUpDown->Position};
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ExitButtonClick(TObject *Sender)
{
	Close();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::SStepUpDownChangingEx(TObject *Sender, bool &AllowChange,
		  int NewValue, TUpDownDirection Direction)
{
	RLengthUpDown->Increment = NewValue;
	RLengthUpDown->Update();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::VStepUpDownChangingEx(TObject *Sender, bool &AllowChange,
		  int NewValue, TUpDownDirection Direction)
{
	VminUpDown->Increment = NewValue;
	VmaxUpDown->Increment = NewValue;
	VminUpDown->Min = V_MIN - V_MIN % NewValue;
	VminUpDown->Position = VminUpDown->Min;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::LoadGridParamsButtonClick(TObject *Sender)
{// Load

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveGridParamsButtonClick(TObject *Sender)
{// Save

}

//---------------------------------------------------------------------------
void __fastcall TForm1::BuildGridButtonClick(TObject *Sender)
{// Build grid
	BuildGrid(GridChart, GetGridParameters());
	CreateSpeedLimitSerie(GridChart, GetGridParameters());
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GridChartClickSeries(TCustomChart *Sender, TChartSeries *Series,
			int ValueIndex, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	AddSpeedLimitPoint(Series, GridPoint{X, Y}, GetGridParameters());
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GridChartKeyPress(TObject *Sender, System::WideChar &Key)
{
    /* TODO : Delegate key events handling to parent */
	if(Key == VK_ESCAPE)
	{
		auto chart = dynamic_cast<TChart*>(Sender);
		if(chart)
			RemoveLastSpeedLimitPoint();
	}
}

//---------------------------------------------------------------------------


