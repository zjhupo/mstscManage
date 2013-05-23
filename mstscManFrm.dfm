object Form1: TForm1
  Left = 355
  Top = 300
  Width = 389
  Height = 262
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #36828#31243#26700#38754#31649#29702#22120
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 12
  object lvList: TListView
    Left = 0
    Top = 0
    Width = 381
    Height = 209
    Align = alClient
    Columns = <
      item
        Caption = #24207#21495
      end
      item
        Caption = #26700#38754#21517#31216
        Width = 100
      end
      item
        Caption = #36828#31243'IP'
        Width = 100
      end
      item
        Caption = #36828#31243#31471#21475
        Width = 60
      end>
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    Items.Data = {
      400000000100000000000000FFFFFFFFFFFFFFFF0300000000000000013108B2
      E2CAD4D7C0C3E60D3230322E3130372E3234352E380433333839FFFFFFFFFFFF}
    ReadOnly = True
    RowSelect = True
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 0
    ViewStyle = vsReport
    OnAdvancedCustomDrawItem = lvListAdvancedCustomDrawItem
    OnDblClick = lvListDblClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 209
    Width = 381
    Height = 19
    Hint = #21452#20987#35775#38382#20027#39029
    Panels = <
      item
        Text = 'http://www.cnhup.net'
        Width = 50
      end>
    ParentShowHint = False
    ShowHint = True
    SimplePanel = False
    OnDblClick = StatusBar1DblClick
  end
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 179
    Top = 117
    object mnuConnect: TMenuItem
      Caption = #36830#25509#36828#31243#26700#38754'(&T)'
      Default = True
      OnClick = mnuConnectClick
    end
    object N7: TMenuItem
      Caption = #33258#23450#20041#36830#25509'(&C)'
      OnClick = N7Click
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object mnuFTP: TMenuItem
      Caption = 'FTP'#36830#25509'(&F)'
      OnClick = mnuFTPClick
    end
    object mnuTelnet: TMenuItem
      Caption = 'Telnet'#36830#25509'(&L)'
      OnClick = mnuTelnetClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object N2: TMenuItem
      Caption = #28155#21152#26700#38754'(&A)'
      OnClick = N2Click
    end
    object mnuEdit: TMenuItem
      Caption = #32534#36753#26700#38754'(&M)'
      OnClick = mnuEditClick
    end
    object mnuDel: TMenuItem
      Caption = #21024#38500#26700#38754'(&D)'
      OnClick = mnuDelClick
    end
    object N5: TMenuItem
      Caption = '-'
    end
    object N6: TMenuItem
      Caption = #36864#20986'(&X)'
      OnClick = N6Click
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 136
    Top = 63
  end
end
