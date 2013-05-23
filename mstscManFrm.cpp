//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mstscManFrm.h"
#include "mstscAddFrm.h"
#include <IniFiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Caption = "远程桌面连接管理器";
    Application->Title = Caption;
    LoadHeader();
    LoadDb();
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void TForm1::LoadHeader()
{
    TIniFile*ini = new TIniFile(".\\mstsc.data");
    Left = ini->ReadInteger("system","left",100);
    Top = ini->ReadInteger("system","top",100);
    m_L = Left;
    m_T = Top;
    Width = ini->ReadInteger("system","w",100);
    Height = ini->ReadInteger("system","h",100);
    bSize = false;

    lvList->Columns->Items[1]->Width = ini->ReadInteger("system","h1",100);
    lvList->Columns->Items[2]->Width = ini->ReadInteger("system","h2",100);
    lvList->Columns->Items[3]->Width = ini->ReadInteger("system","h3",70);
    m_h1 = lvList->Columns->Items[1]->Width;
    m_h2 = lvList->Columns->Items[2]->Width;
    m_h3 = lvList->Columns->Items[3]->Width;
    delete ini;
}

void TForm1::WriteHeader()
{
    TIniFile*ini = new TIniFile(".\\mstsc.data");
    ini->WriteInteger("system","left", Left);
    ini->WriteInteger("system","top", Top);
    ini->WriteInteger("system","w", Width);
    ini->WriteInteger("system","h", Height);
    ini->WriteInteger("system","h1",lvList->Columns->Items[1]->Width);
    ini->WriteInteger("system","h2",lvList->Columns->Items[2]->Width);
    ini->WriteInteger("system","h3",lvList->Columns->Items[3]->Width);
    delete ini;
}


void TForm1::LoadDb()
{
    TIniFile*ini = new TIniFile(".\\mstsc.data");
    int iCount = ini->ReadInteger("system","count",0);
    AnsiString sSection;
    lvList->Clear();
    TListItem*Item;
    for(int i=0;i<iCount;i++)
    {
        sSection = "ip"+ IntToStr(i+1);
        Item = lvList->Items->Add();
        Item->Caption = IntToStr(Item->Index+1);
        Item->SubItems->Add(ini->ReadString(sSection,"name",""));
        Item->SubItems->Add(ini->ReadString(sSection,"ip",""));
        Item->SubItems->Add(ini->ReadString(sSection,"port","3389"));
    }
    delete ini;
}

void TForm1::WriteDb()
{
    TIniFile*ini = new TIniFile(".\\mstsc.data");
    ini->WriteInteger("system","count",lvList->Items->Count);
    AnsiString sSection;
    for(int i=0;i<lvList->Items->Count;i++)
    {
        sSection = "ip"+ IntToStr(i+1);
        ini->WriteString(sSection,"name",lvList->Items->Item[i]->SubItems->Strings[0]);
        ini->WriteString(sSection,"ip",lvList->Items->Item[i]->SubItems->Strings[1]);
        ini->WriteString(sSection,"port",lvList->Items->Item[i]->SubItems->Strings[2]);
    }
    delete ini;
}

void __fastcall TForm1::mnuConnectClick(TObject *Sender)
{
    if(lvList->Selected == NULL)
        return;
    AnsiString sCmd;
    sCmd = "mstsc.exe /v:"+ lvList->Selected->SubItems->Strings[1]+
        ":"+lvList->Selected->SubItems->Strings[2];
    WinExec(sCmd.c_str(),SW_SHOW);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    //new
    frmmstscAdd = new TfrmmstscAdd(this);
    if(frmmstscAdd->ShowModal() == mrOk)
    {
        TListItem*Item = lvList->Items->Add();
        Item->Caption = IntToStr(Item->Index+1);
        Item->SubItems->Add(frmmstscAdd->Edit1->Text);
        Item->SubItems->Add(frmmstscAdd->Edit2->Text);
        Item->SubItems->Add(frmmstscAdd->Edit3->Text);
        WriteDb();
        LoadDb();

    }
    delete frmmstscAdd;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::mnuEditClick(TObject *Sender)
{
    if(lvList->Selected == NULL)
        return;
    //edit
    frmmstscAdd = new TfrmmstscAdd(this);
    frmmstscAdd->Edit1->Text = lvList->Selected->SubItems->Strings[0];
    frmmstscAdd->Edit2->Text = lvList->Selected->SubItems->Strings[1];
    frmmstscAdd->Edit3->Text = lvList->Selected->SubItems->Strings[2];
    if(frmmstscAdd->ShowModal() == mrOk)
    {
        lvList->Selected->SubItems->Strings[0] = frmmstscAdd->Edit1->Text;
        lvList->Selected->SubItems->Strings[1] = frmmstscAdd->Edit2->Text;
        lvList->Selected->SubItems->Strings[2] = frmmstscAdd->Edit3->Text;
        WriteDb();
        LoadDb();
    }
    delete frmmstscAdd;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::mnuDelClick(TObject *Sender)
{
    if(lvList->Selected == NULL)
        return;
    lvList->Selected->Delete();
    WriteDb();
    LoadDb();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
    AnsiString sCmd;
    sCmd = "mstsc.exe ";
    WinExec(sCmd.c_str(),SW_SHOW);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Timer1->Enabled = false;
    try
    {
        if(m_h1 != lvList->Columns->Items[1]->Width ||
            m_h2 != lvList->Columns->Items[2]->Width ||
            m_h3 != lvList->Columns->Items[3]->Width ||
            bSize || m_L != Left || m_T != Top)
        {
            bSize = false;
            WriteHeader();
        }
    }catch(...){}
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lvListAdvancedCustomDrawItem(
      TCustomListView *Sender, TListItem *Item, TCustomDrawState State,
      TCustomDrawStage Stage, bool &DefaultDraw)
{
    TListView*View = (TListView*)Sender;
    if(Item!=NULL)
    {
        //cdsSelected, cdsGrayed, cdsDisabled, cdsChecked, cdsFocused
        int idx = Item->Index;
        if(idx%2==0)
        {
            View->Canvas->Brush->Color = clInfoBk;
            View->Canvas->Font->Color = clBlack;
        }
        else
        {
            View->Canvas->Brush->Color = clGradientActiveCaption;
            View->Canvas->Font->Color = clBlack;
        }
        TRect r=Item->DisplayRect(drBounds);
        if(State.Contains(cdsFocused))
        {
            View->Canvas->Brush->Color = clMaroon;
            View->Canvas->Font->Color = clWhite;
        }
        View->Canvas->FillRect(r);
        TRect rtText;
        rtText.left = r.left+2;
        rtText.top = r.top;
        rtText.right = r.left+View->Columns->Items[0]->Width;
        rtText.Bottom  = r.Bottom;
        if(View->SmallImages!=NULL)
        {
            if(Item->ImageIndex>=0)
                View->SmallImages->Draw(View->Canvas,rtText.left,rtText.top,Item->ImageIndex,true);
            rtText.left += View->SmallImages->Width+4;
        }
        DrawText(View->Canvas->Handle,Item->Caption.c_str(),-1,&rtText,DT_END_ELLIPSIS | DT_PATH_ELLIPSIS);
        AnsiString sSubText;
        int iWidth;
        for(int i=0;i<Item->SubItems->Count;i++)
        {
            if(i>=View->Columns->Count)
                continue;
            sSubText = Item->SubItems->Strings[i];
            iWidth = 0;
            for(int k=0;k<i+1;k++)
                iWidth += View->Columns->Items[k]->Width+2;
            iWidth-=1;
            rtText.left = r.left+4+iWidth;
            rtText.top = r.top;
            if(i+1<View->Columns->Count)
                rtText.right = rtText.left+View->Columns->Items[i+1]->Width;
            else
                rtText.right = rtText.left+View->Columns->Items[i]->Width;
            rtText.Bottom = r.Bottom;
            DrawText(View->Canvas->Handle,sSubText.c_str(),-1,&rtText,DT_END_ELLIPSIS | DT_PATH_ELLIPSIS);
        }
    }
    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
    bSize = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PopupMenu1Popup(TObject *Sender)
{
    mnuConnect->Enabled = lvList->Selected !=NULL;
    mnuEdit->Enabled = mnuConnect->Enabled;
    mnuDel->Enabled = mnuConnect->Enabled;
    mnuFTP->Enabled = mnuConnect->Enabled;
    mnuTelnet->Enabled = mnuConnect->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lvListDblClick(TObject *Sender)
{
    mnuConnect->Click();    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StatusBar1DblClick(TObject *Sender)
{
    ShellExecute(NULL,"open","http://www.cnhup.net",NULL,NULL,SW_SHOW);    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuFTPClick(TObject *Sender)
{
    if(lvList->Selected == NULL)
        return;
    AnsiString sCmd;
    sCmd = "ftp.exe "+ lvList->Selected->SubItems->Strings[1];
    WinExec(sCmd.c_str(),SW_SHOW);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuTelnetClick(TObject *Sender)
{
    if(lvList->Selected == NULL)
        return;
    AnsiString sCmd;
    sCmd = "telnet.exe "+ lvList->Selected->SubItems->Strings[1];
    WinExec(sCmd.c_str(),SW_SHOW);
}
//---------------------------------------------------------------------------

