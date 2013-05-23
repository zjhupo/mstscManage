//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mstscAddFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TfrmmstscAdd *frmmstscAdd;
//---------------------------------------------------------------------------
__fastcall TfrmmstscAdd::TfrmmstscAdd(TComponent* Owner)
    : TForm(Owner)
{
    Edit1->Text = "";
    Edit2->Text = "";
    Edit3->Value = 3389;
}
//---------------------------------------------------------------------------
void __fastcall TfrmmstscAdd::BitBtn1Click(TObject *Sender)
{
    ModalResult = mrOk;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmmstscAdd::BitBtn2Click(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------
