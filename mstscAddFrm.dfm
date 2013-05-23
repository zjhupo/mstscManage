object frmmstscAdd: TfrmmstscAdd
  Left = 408
  Top = 256
  BorderStyle = bsDialog
  Caption = #22686#21152
  ClientHeight = 158
  ClientWidth = 271
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 9
    Width = 72
    Height = 13
    Caption = #36828#31243#26700#38754#21517#31216
  end
  object Label2: TLabel
    Left = 30
    Top = 40
    Width = 58
    Height = 13
    Caption = #36828#31243'IP'#22320#22336
  end
  object Label3: TLabel
    Left = 40
    Top = 71
    Width = 48
    Height = 13
    Caption = #36828#31243#31471#21475
  end
  object Edit1: TEdit
    Left = 102
    Top = 5
    Width = 143
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 102
    Top = 35
    Width = 143
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TCSpinEdit
    Left = 102
    Top = 66
    Width = 143
    Height = 22
    TabOrder = 2
    Value = 3389
  end
  object BitBtn1: TBitBtn
    Left = 89
    Top = 105
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 3
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 172
    Top = 105
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 4
    OnClick = BitBtn2Click
  end
end
