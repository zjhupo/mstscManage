//---------------------------------------------------------------------------

#ifndef mstscAddFrmH
#define mstscAddFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmmstscAdd : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *Edit1;
    TEdit *Edit2;
    TCSpinEdit *Edit3;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmmstscAdd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmmstscAdd *frmmstscAdd;
//---------------------------------------------------------------------------
#endif
