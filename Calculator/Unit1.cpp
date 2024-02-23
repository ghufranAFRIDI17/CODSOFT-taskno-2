//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
char op;
double input1_number;
double input2_number;
double output_number;
bool flag;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	op='N';
	input1_number=0;
	input2_number=0;
	output_number=0;
	output->Text=0;
	flag=false;
}

bool checkfordot(const String  &str)
{
    int size= str.Length();
	for(int i=1;i<=size;++i)
	{
		if(str[i]=='.')
		{
			return false;
		}
	}
	return true;
}
double stringtodouble(const String &str)
{
	int i=1,number1=0,number2=0,x=1;
	for(;i<=str.Length();++i)
	{
		if(str[i]!='.')
		{
			number1*=10;
			number1+=str[i]-'0';
		}
		else
		{
            ++i;
            break;
		}
	}
	for(;i<=str.Length();++i)
	{
        x*=10;
		number2*=10;
        number2+=str[i]-'0';
	}
	number2/=x;
	number1+=number2;
	return number1;
}

double operation(const double number1,const double number2)
{
	switch(op)
	{
	 case '+':
		return number1+number2;
	 case '-':
		return number1-number2;
	 case 'x':
		return number1*number2;
	 case '/':
		return number1/number2;
	}
	return 0.0;
}

bool isvalid(const String str)
{
    bool flag=true;
	for(int i=1;i<=str.Length();++i)
	{
		if(str[i]=='.' && flag==true)
		{
			flag=false;
		}
		if(str[i]<'0' || str[i]>'9')
		{
			return false;
		}
	}
    return true;

}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void __fastcall TForm1::oneClick(TObject *Sender)
{
    input2->Text+="1";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::twoClick(TObject *Sender)
{
	input2->Text+="2";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::threeClick(TObject *Sender)
{
	input2->Text+="3";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fourClick(TObject *Sender)
{
	input2->Text+="4";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fiveClick(TObject *Sender)
{
	input2->Text+="5";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sixClick(TObject *Sender)
{
	input2->Text+="6";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sevenClick(TObject *Sender)
{
	input2->Text+="7";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::eightClick(TObject *Sender)
{
	input2->Text+="8";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::nineClick(TObject *Sender)
{
	input2->Text+="9";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::zeroClick(TObject *Sender)
{
	if(input2->Text!="0")
	{
		input2->Text+="0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::dotClick(TObject *Sender)
{
	 String str=input2->Text;
	if(str=="")
	{
		input2->Text+="0.";
	}
	else if(checkfordot(str))
	{
		input2->Text+=".";
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::backClick(TObject *Sender)
{
	if(output->Text!="")
	{
		String str=input2->Text;
		int index=str.Length();
		str.Delete(index,1);
		input2->Text=str;
	}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::plusClick(TObject *Sender)
{
	if(switch_button->IsChecked==true)
	{
		op='+';
		opr->Text="+";
        return;
	}
	String str=input2->Text;
	input2_number=stringtodouble(str);
	if(flag)
	{

		if(input2->Text=="")
		{
			input1_number=output_number;
		}
		else
		{
			input1_number=input2_number;
			output_number=input1_number;
		}
        op='+';
		input1->Text=input1_number;
		input2->Text="";
        output->Text=output_number;
		opr->Text=op;
        flag=false;
		return;
	}
	if(input1->Text=="")
	{
		input1_number=input2_number;
		output_number=input1_number;
		output->Text=output_number;
		input1->Text=input1_number;
		opr->Text="+";
		op='+';
		input2->Text="";
		return;
	}
	if(op=='/' && input2_number==0)
	{
		output_number=0;
		output->Text="INFINITY";
		input1_number=0;
		input1->Text="";
		input2_number=0;
		input2->Text="";
		op='N';
		opr->Text="";
		return;
	}
	input1_number = output_number=operation(input1_number,input2_number);
	output->Text=output_number;
	input1->Text=input1_number;
	opr->Text="+";
	op='+';
	input2->Text="";


	flag=false;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


void __fastcall TForm1::divideClick(TObject *Sender)
{
    if(switch_button->IsChecked==true)
	{
		op='/';
		opr->Text="/";
        return;
	}
	String str=input2->Text;
	input2_number=stringtodouble(str);
	if(input1->Text=="")
	{
		input1_number=input2_number;
		output_number=input1_number;
		output->Text=output_number;
		input1->Text=input1_number;
		opr->Text="/";
		op='/';
		input2->Text="";
		return;
	}
	if(op=='/' && input2_number==0)
	{
		output_number=0;
		output->Text="INFINITY";
		input1_number=0;
		input1->Text="";
		input2_number=0;
		input2->Text="";
		op='N';
		opr->Text="";
		return;
	}
	input1_number = output_number=operation(input1_number,input2_number);
	output->Text=output_number;
	input1->Text=input1_number;
	opr->Text="/";
	op='/';
	input2->Text="";


	flag=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::multiplyClick(TObject *Sender)
{
    if(switch_button->IsChecked==true)
	{
		op='x';
		opr->Text="x";
        return;
	}
	String str=input2->Text;
	input2_number=stringtodouble(str);
	if(input1->Text=="")
	{
		input1_number=input2_number;
		output_number=input1_number;
		output->Text=output_number;
		input1->Text=input1_number;
		opr->Text="x";
		op='x';
		input2->Text="";
		return;
	}
	if(op=='/' && input2_number==0)
	{
		output_number=0;
		output->Text="INFINITY";
		input1_number=0;
		input1->Text="";
		input2_number=0;
		input2->Text="";
		op='N';
		opr->Text="";
		return;
	}
	input1_number = output_number=operation(input1_number,input2_number);
	output->Text=output_number;
	input1->Text=input1_number;
	opr->Text="x";
	op='x';
	input2->Text="";


	flag=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::minusClick(TObject *Sender)
{
    if(switch_button->IsChecked==true)
	{
		op='-';
		opr->Text="-";
        return;
	}
	String str=input2->Text;
	input2_number=stringtodouble(str);
	if(input1->Text=="")
	{
		input1_number=input2_number;
		output_number=input1_number;
		output->Text=output_number;
		input1->Text=input1_number;
		opr->Text="-";
		op='-';
		input2->Text="";
		return;
	}
	if(op=='/' && input2_number==0)
	{
		output_number=0;
		output->Text="INFINITY";
		input1_number=0;
		input1->Text="";
		input2_number=0;
		input2->Text="";
		op='N';
		opr->Text="";
		return;
	}
	input1_number = output_number=operation(input1_number,input2_number);
	output->Text=output_number;
	input1->Text=input1_number;
	opr->Text="-";
	op='-';
	input2->Text="";


	flag=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::equalClick(TObject *Sender)
{
    if(switch_button->IsChecked==true)
	{
		String num1=input1->Text;
		String num2=input2->Text;
		if(num1!="" && isvalid(num1))
		{
            input1_number=stringtodouble(num1);
		}
		else
		{
			input1->Text="";
			output->Text="Enter valid input 1";
			if(num2=="" || !isvalid(num2))
			{
				output->Text="Enter valid input 1 and input 2";
                input2->Text="";
			}
			return;
		}
		if(num2!="" && isvalid(num2))
		{
            input2_number=stringtodouble(num2);
		}
		else
		{
			input2->Text="";
			output->Text="Enter valid input 2";
            return;
		}
		if(op=='N')
		{
			output->Text="Select Operator";
			return;
		}
		output_number=operation(input1_number,input2_number);
        output->Text=output_number;
        return;
	}
	if(input2->Text!="")
	{
        String num2=input2->Text;
		input2_number=stringtodouble(num2);
	}
	else
	{
        input2_number=output_number;
	}
	if(op=='N')
	{
		input1_number=input2_number;
		output_number=input2_number;
		input1->Text=input1_number;
		output->Text=output_number;
		input2->Text="";
		flag=true;
		return;
	}
	if(!flag)
	{
        double temp=input1_number;
		input1_number=input2_number;
		input2_number=temp;

	}
    	if(op=='/' && input1_number==0)
	{
		output_number=0;
		output->Text="INFINITY";
		input1_number=0;
		input1->Text="";
		input2_number=0;
		input2->Text="";
		op='N';
		opr->Text="";
		return;
	}
    output_number=operation(input2_number,input1_number);
	input1->Text=input1_number;
    input2_number=0;
	input2->Text="";
	output->Text=output_number;
	opr->Text=op;
	flag=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::switch_buttonSwitch(TObject *Sender)
{
    op='N';
	input1_number=0;
	input2_number=0;
	output_number=0;
	output->Text=0;
	input1->Text="";
	input2->Text="";
    opr->Text="";
	flag=false;
	bool check=switch_button->IsChecked;
	input1->Enabled=check;
	input2->Enabled=check;
	back->Enabled=!check;
	dot->Enabled=!check;
	zero->Enabled=!check;
	one->Enabled=!check;
	two->Enabled=!check;
	three->Enabled=!check;
	four->Enabled=!check;
	five->Enabled=!check;
	six->Enabled=!check;
	seven->Enabled=!check;
	eight->Enabled=!check;
	nine->Enabled=!check;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::clearClick(TObject *Sender)
{
	op='N';
	input1_number=0;
	input2_number=0;
	output_number=0;
	output->Text=0;
	input1->Text="";
	input2->Text="";
    opr->Text="";
	flag=false;
}
//---------------------------------------------------------------------------

