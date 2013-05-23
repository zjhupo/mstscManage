//---------------------------------------------------------------------------

#ifndef mstscManFrmH
#define mstscManFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TListView *lvList;
    TStatusBar *StatusBar1;
    TPopupMenu *PopupMenu1;
    TMenuItem *mnuConnect;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *mnuEdit;
    TMenuItem *mnuDel;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TTimer *Timer1;
    TMenuItem *N3;
    TMenuItem *mnuFTP;
    TMenuItem *mnuTelnet;
    void __fastcall mnuConnectClick(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall mnuEditClick(TObject *Sender);
    void __fastcall mnuDelClick(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall lvListAdvancedCustomDrawItem(TCustomListView *Sender,
          TListItem *Item, TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall PopupMenu1Popup(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    void __fastcall lvListDblClick(TObject *Sender);
    void __fastcall StatusBar1DblClick(TObject *Sender);
    void __fastcall mnuFTPClick(TObject *Sender);
    void __fastcall mnuTelnetClick(TObject *Sender);
private:	// User declarations
    int m_h1,m_h2,m_h3,bSize,m_L,m_T;
    void LoadDb();
    void WriteDb();
    void LoadHeader();
    void WriteHeader();
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
