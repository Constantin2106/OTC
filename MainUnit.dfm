object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 618
  ClientWidth = 1263
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object MainPanel: TPanel
    Left = 0
    Top = 0
    Width = 1263
    Height = 618
    Align = alClient
    Caption = 'MainPanel'
    TabOrder = 0
    DesignSize = (
      1263
      618)
    object GridChart: TChart
      Left = 1
      Top = 1
      Width = 1097
      Height = 616
      Title.Text.Strings = (
        'TChart')
      OnClickSeries = GridChartClickSeries
      BottomAxis.AxisValuesFormat = '###0.###'
      BottomAxis.LabelsFormat.Font.Style = [fsBold]
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.AxisValuesFormat = '###0.###'
      LeftAxis.LabelsSeparation = 0
      LeftAxis.Minimum = 448.750000000000000000
      View3D = False
      Align = alLeft
      OnKeyPress = GridChartKeyPress
      TabOrder = 0
      Anchors = [akLeft, akTop, akRight, akBottom]
      DefaultCanvas = 'TGDIPlusCanvas'
      PrintMargins = (
        15
        19
        15
        19)
      ColorPaletteIndex = 13
    end
    object ExitButton: TButton
      AlignWithMargins = True
      Left = 1130
      Top = 585
      Width = 126
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = 'Exit'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = ExitButtonClick
    end
    object ParamsGroupBox: TGroupBox
      Left = 1104
      Top = 1
      Width = 152
      Height = 272
      Anchors = [akTop, akRight]
      Caption = ' Grid '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object RLengthLabel: TLabel
        Left = 6
        Top = 48
        Width = 39
        Height = 14
        Caption = 'Length'
      end
      object Label1: TLabel
        Left = 122
        Top = 48
        Width = 10
        Height = 14
        Caption = 'm'
      end
      object SStepLabel: TLabel
        Left = 6
        Top = 20
        Width = 26
        Height = 14
        Caption = 'Step'
      end
      object Label3: TLabel
        Left = 122
        Top = 20
        Width = 10
        Height = 14
        Caption = 'm'
      end
      object Label2: TLabel
        Left = 119
        Top = 116
        Width = 28
        Height = 14
        Caption = 'km/h'
      end
      object VminLabel: TLabel
        Left = 6
        Top = 116
        Width = 27
        Height = 14
        Caption = 'Vmin'
      end
      object VmaxLabel: TLabel
        Left = 6
        Top = 143
        Width = 30
        Height = 14
        Caption = 'Vmax'
      end
      object Label5: TLabel
        Left = 119
        Top = 143
        Width = 28
        Height = 14
        Caption = 'km/h'
      end
      object VstepLabel: TLabel
        Left = 6
        Top = 88
        Width = 32
        Height = 14
        Caption = 'Vstep'
      end
      object Label6: TLabel
        Left = 119
        Top = 88
        Width = 28
        Height = 14
        Caption = 'km/h'
      end
      object RLengthEdit: TEdit
        Left = 49
        Top = 45
        Width = 51
        Height = 22
        NumbersOnly = True
        ReadOnly = True
        TabOrder = 2
        Text = '5000'
      end
      object SStepEdit: TEdit
        Left = 49
        Top = 17
        Width = 51
        Height = 22
        NumbersOnly = True
        ReadOnly = True
        TabOrder = 0
        Text = '200'
      end
      object SStepUpDown: TUpDown
        Left = 100
        Top = 17
        Width = 16
        Height = 22
        Associate = SStepEdit
        Min = 100
        Max = 1000
        Increment = 100
        Position = 200
        TabOrder = 1
        Thousands = False
        OnChangingEx = SStepUpDownChangingEx
      end
      object VminUpDown: TUpDown
        Left = 100
        Top = 113
        Width = 16
        Height = 22
        Associate = VminEdit
        Min = 10
        Max = 40
        Increment = 5
        Position = 10
        TabOrder = 7
      end
      object VminEdit: TEdit
        Left = 49
        Top = 113
        Width = 51
        Height = 22
        NumbersOnly = True
        ReadOnly = True
        TabOrder = 6
        Text = '10'
      end
      object VmaxEdit: TEdit
        Left = 49
        Top = 140
        Width = 51
        Height = 22
        NumbersOnly = True
        ReadOnly = True
        TabOrder = 8
        Text = '80'
      end
      object VmaxUpDown: TUpDown
        Left = 100
        Top = 140
        Width = 16
        Height = 22
        Associate = VmaxEdit
        Min = 80
        Increment = 5
        Position = 80
        TabOrder = 9
      end
      object BuildGridButton: TButton
        Left = 13
        Top = 236
        Width = 126
        Height = 25
        Caption = 'Build'
        TabOrder = 12
        OnClick = BuildGridButtonClick
      end
      object RLengthUpDown: TUpDown
        Left = 100
        Top = 45
        Width = 17
        Height = 22
        Associate = RLengthEdit
        Min = 1000
        Max = 25000
        Increment = 100
        Position = 5000
        TabOrder = 3
        Thousands = False
      end
      object VstepEdit: TEdit
        Left = 49
        Top = 85
        Width = 51
        Height = 22
        NumbersOnly = True
        ReadOnly = True
        TabOrder = 4
        Text = '2'
      end
      object VStepUpDown: TUpDown
        Left = 100
        Top = 85
        Width = 16
        Height = 22
        Associate = VstepEdit
        Min = 1
        Max = 20
        Position = 2
        TabOrder = 5
        OnChangingEx = VStepUpDownChangingEx
      end
      object SaveGridParamsButton: TButton
        Left = 13
        Top = 205
        Width = 126
        Height = 25
        Caption = 'Save'
        TabOrder = 11
        OnClick = SaveGridParamsButtonClick
      end
      object LoadGridParamsButton: TButton
        Left = 13
        Top = 174
        Width = 126
        Height = 25
        Caption = 'Load'
        TabOrder = 10
        OnClick = LoadGridParamsButtonClick
      end
    end
  end
end
