//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.ComCtrls.hpp>

#include "Src/GridControl.h"
#include "Src/SeriesControl.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *MainPanel;
	TChart *GridChart;
	TButton *ExitButton;
	TGroupBox *ParamsGroupBox;
	TLabel *RLengthLabel;
	TEdit *RLengthEdit;
	TLabel *Label1;
	TLabel *SStepLabel;
	TEdit *SStepEdit;
	TUpDown *SStepUpDown;
	TLabel *Label3;
	TLabel *Label2;
	TUpDown *VminUpDown;
	TEdit *VminEdit;
	TLabel *VminLabel;
	TLabel *VmaxLabel;
	TEdit *VmaxEdit;
	TUpDown *VmaxUpDown;
	TLabel *Label5;
	TButton *BuildGridButton;
	TUpDown *RLengthUpDown;
	TLabel *VstepLabel;
	TEdit *VstepEdit;
	TUpDown *VStepUpDown;
	TLabel *Label6;
	TButton *SaveGridParamsButton;
	TButton *LoadGridParamsButton;
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall BuildGridButtonClick(TObject *Sender);
	void __fastcall SStepUpDownChangingEx(TObject *Sender, bool &AllowChange, int NewValue,
          TUpDownDirection Direction);
	void __fastcall LoadGridParamsButtonClick(TObject *Sender);
	void __fastcall SaveGridParamsButtonClick(TObject *Sender);
	void __fastcall VStepUpDownChangingEx(TObject *Sender, bool &AllowChange, int NewValue, TUpDownDirection Direction);
	void __fastcall GridChartClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall GridChartKeyPress(TObject *Sender, System::WideChar &Key);


private:	// User declarations
	 SmartGrid::Types::Parameters::GridParameters mGridParameters;

	 const SmartGrid::Types::Parameters::GridParameters& GetGridParameters();

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
