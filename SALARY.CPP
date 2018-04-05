// file name -> salary.cpp

/**********  fuction to calculate and display the pay slip  **********/
void salary()
{
	int cecode; //desired ecode or current ecode
	int cyear; //desired year or current year
	int cmonth; //desired month or current month
	float hra = 0.0; // Housing rent allowance
	float da = 0.0;  // Dearness allowance
	float pf = 0.0;  // provident fund
	float gross = 0.0 ,net = 0.0; // gross salary , net salary
	float cbasic ; //temporary storage of basic salary
	int flag = 0;
	char char_month[10];
	int valid=0;

	clrscr();
	gotoxy(25,10);
	cout<<"Enter Employee Code : ";
	cin>>cecode;

	while (valid==0)
	{
	gotoxy(25,12);
	cout<<"Enter month (in number) :   \b\b";
	cin>>cmonth;
	switch(cmonth)
	{
		case 1 :
		{
			strcpy(char_month,"January")  ;
			valid = 1;
			break;
		}
		case 2 :
		{
			strcpy(char_month,"February") ;
			valid = 1;
			break;
		}
		case 3 :
		{
			strcpy(char_month,"March") ;
			valid = 1;
			break;
		}
		case 4 :
		{
			strcpy(char_month,"April") ;
			valid - 1;
			break;
		}
		case 5 :
		{
			strcpy(char_month,"May") ;
			valid = 1;
			break;
		}
		case 6 :
		{
			strcpy(char_month,"June") ;
			valid = 1;
			break;
		}
		case 7 :
		{
			strcpy(char_month,"July") ;
			valid = 1;
			break;
		}
		case 8 :
		{
			strcpy(char_month,"August") ;
			valid = 1;
			break;
		}
		case 9 :
		{
			strcpy(char_month,"September") ;
			valid = 1;
			break;
		}
		case 10 :
		{
			strcpy(char_month,"October") ;
			valid = 1;
			break;
		}
		case 11 :
		{
			strcpy(char_month,"November") ;
			valid = 1;
			break;
		}
		case 12 :
		{
			strcpy(char_month,"December") ;
			valid = 1;
			break;
		}
		default:
		{
			valid = 0;
			gotoxy(25,14);
			cout<<"Enter between 1 to 12";
			getch();
			gotoxy(25,14);
			cout<<"                                  ";
			break;
		}
	}
	}
	gotoxy(25,14);
	cout<<"Enter year : ";
	cin>>cyear;

	data d1;
	attendence a1;
	fstream indata , inattend;
	indata.open("off_det.dat",ios::in | ios::ate | ios::binary);
	inattend.open("attend.dat",ios::in | ios::ate | ios::binary);
	indata.seekg(0);
	inattend.seekg(0);
	indata.read((char *) &d1 , sizeof(d1));
	inattend.read((char *) &a1 , sizeof(a1));

	clrscr();
	cout<<t1"   _________PAY SLIP_________\n";
	cout<<"\t\t\t\tfor "<<char_month<<" "<<cyear<<"\n";
	while(indata)
	{
		if(d1.ecode == cecode)
		{
			cout<<"\t";
			d1.putdata1();
			cbasic = d1.basic;
			break;
		}
		indata.read((char *) &d1 , sizeof(d1));
	}

	if (cbasic >= 2500 && cbasic <=3000)
	{
		da = cbasic * 0.9;
		hra = cbasic * 0.2;
	}
	else
		if (cbasic >=3001 && cbasic <=4000)
		{
			da = cbasic * 1.2;
			hra = cbasic * 0.3;
		}
		else
			if (cbasic >=4001 && cbasic <=5000)
			{
				da = cbasic * 1.4;
				hra = cbasic * 0.35;
			}
			else
				if (cbasic >= 5001)
				{
					da = cbasic * 1.5;
					hra = cbasic * 0.4;
				}

	pf = cbasic * 0.12;
	gross = cbasic  + da + hra ;

	while(inattend)
	{
		if ( a1.ecode == cecode && a1.year == cyear && a1.month == cmonth )
		{
			net = gross - pf - a1.advance - (gross/30) * a1.lwp;
			flag++;
			break;
		}
		else
			inattend.read((char *) &a1 , sizeof(a1));
	}

	if (flag != 0)
	{
		cout<<"\n\t--------------------------------------------------------------\n";
		cout<<"                         EARNINGS                           DEDUCTIONS";
		cout<<"\n\t--------------------------------------------------------------\n\n";
		cout<<"\tBasic   : "
			<<setw(14)<<setiosflags(ios::right|ios::showpoint|ios::fixed)<<setprecision(2)<<cbasic
			<<"      Provident Fund    : "
			<<setw(12)<<setiosflags(ios::right)<<pf<<"\n"
			<<"\tD.A.    : "
			<<setw(14)<<setiosflags(ios::right)<<da
			<<"      Advance           : "
			<<setw(12)<<setiosflags(ios::right)<<a1.advance<<"\n"
			<<"\tH.R.A.  : "
			<<setw(14)<<setiosflags(ios::right)<<hra
			<<"      Leave without Pay : "
			<<setw(12)<<setiosflags(ios::right)<<(gross/30)*a1.lwp<<"\n";
		cout<<"\n\t--------------------------------------------------------------\n";
		cout<<"\tTot Earning :"
			<<setw(11)<<setiosflags(ios::right)<<cbasic+hra+da
			<<"      Tot Deductions    : "
			<<setw(12)<<setiosflags(ios::right)<<pf+a1.advance+(gross/30)*a1.lwp;
		cout<<"\n\n\tNet Pay : "<<net;

		int dd,mm,yy;
		struct date d;
		getdate(&d);
		dd = d.da_day;
		mm = d.da_mon;
		yy = d.da_year;
		gotoxy(41,23);
		cout<<"\t\tDate : ";
		cout<<dd<<"-"<<mm<<"-"<<yy;

	}
	box();
	getch();
}