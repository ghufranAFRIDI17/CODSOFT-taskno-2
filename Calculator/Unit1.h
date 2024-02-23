//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *output;
	TButton *one;
	TButton *two;
	TButton *three;
	TButton *four;
	TButton *five;
	TButton *six;
	TButton *seven;
	TButton *eight;
	TButton *nine;
	TButton *dot;
	TButton *zero;
	TButton *back;
	TButton *clear;
	TButton *plus;
	TButton *minus;
	TButton *multiply;
	TButton *divide;
	TButton *equal;
	TLabel *opr;
	TEdit *input1;
	TEdit *input2;
	TSwitch *switch_button;
	void __fastcall oneClick(TObject *Sender);
	void __fastcall twoClick(TObject *Sender);
	void __fastcall threeClick(TObject *Sender);
	void __fastcall fourClick(TObject *Sender);
	void __fastcall fiveClick(TObject *Sender);
	void __fastcall sixClick(TObject *Sender);
	void __fastcall sevenClick(TObject *Sender);
	void __fastcall eightClick(TObject *Sender);
	void __fastcall nineClick(TObject *Sender);
	void __fastcall zeroClick(TObject *Sender);
	void __fastcall dotClick(TObject *Sender);
	void __fastcall backClick(TObject *Sender);
	void __fastcall plusClick(TObject *Sender);
	void __fastcall divideClick(TObject *Sender);
	void __fastcall multiplyClick(TObject *Sender);
	void __fastcall minusClick(TObject *Sender);
	void __fastcall equalClick(TObject *Sender);
	void __fastcall switch_buttonSwitch(TObject *Sender);
	void __fastcall clearClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
