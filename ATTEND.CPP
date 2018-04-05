// file name -> attend.cpp
// This file handles all about the attendance
class attendence
{
	protected :
		int nodwk ;    // No of days worked
		int ela ;      // earned leave availed
		int cla ;      // casual leave availed
		int lwp ;      // leave without pay
		int month;
		int  year ;
		float advance; // advance taken by any employee
	public :
		int ecode ;
		void getdata();  // function to record the attendance
		void putdata();  // function to display the attendance
		friend void disp_one();
		friend void salary();
		friend void dept_sal();
};

void attendence ::getdata() // function to get the attendance after a month
{
	attendence a1;
	fstream io_attend;
	io_attend.open("attend.dat",ios::binary|ios::in|ios::out|ios::ate);
	char ch='y';
	while (ch=='y' || ch=='Y')
	{
		clrscr();
		cout<<"\n\n\t\t..........MONTHLY ATTENDENCE RECORD..........\n\n";
		cout<<"\n\tEmployee code        : ";
		cin>>ecode;
		data d1;
		fstream io_data("off_det.dat",ios::in | ios::out | ios::binary);
		io_data.seekg(0);
		io_data.read((char *) &d1, sizeof(d1));
		int ecode_check=0;
		while(io_data)
		{
			if(ecode == d1.ecode)
			{
				ecode_check++;
				break;
			}
			io_data.read((char *) &d1, sizeof(d1));
		}
		if (ecode_check == 0)
		{
			gotoxy(10,24);
			cout<<"This E-code does not exist ";
			getch();
			io_data.close();
			io_attend.close();
			getdata();
		}
		int month_check = 0;
		while (month_check == 0)
		{
			cout<<"\n\tMonth (in number)    :   \b\b";
			cin>>month;
			if (month >= 1 && month <=12)
			{
				month_check = 1;
				gotoxy(10,24);
				cout<<"                                 ";
			}
			else
			{
				gotoxy(10,24);
				cout<<"Enter between 1 and 12";
				gotoxy(1,7);
				month_check = 0;
			}
		}
		gotoxy(1,9);
		cout<<"\n\tYear	             : ";
		cin>>year;
		io_attend.seekg(0);
		io_attend.read((char *) &a1, sizeof(a1));
		int attend_check = 1;
		while (io_attend)
		{
			if (ecode == a1.ecode && month == a1.month && year == a1.year)
			{
				attend_check = 0;
				break;
			}
			io_attend.read((char *) &a1, sizeof(a1));
		}
		if (attend_check == 0)
		{
			cout<<"\n\n\n\t\t Attendence already recorded for this period";
			getch();
			break;
		}

		int leaves_check = 0;
		while ( leaves_check == 0)
		{
			int el_check = 0;
			while (el_check == 0)
			{
				gotoxy(1,11);
				cout<<"\n\tEarned leave availed :   \b\b";
				cin>>ela;
				if ( ela > d1.el )
				{
					gotoxy(10,24);
					cout<<"Can't take more than remaining "<<d1.el
						<<" earned leave(s)";
					gotoxy(1,11);
					el_check = 0;
				}
				else
				{
					gotoxy(10,24);
					cout<<"                                                   ";
					el_check = 1;
				}
			}
			int cl_check = 0;
			while (cl_check == 0)
			{
				gotoxy(1,13);
				cout<<"\n\tCasual leave availed :   \b\b";
				cin>>cla;
				if (cla>d1.cl)
				{
					gotoxy(10,24);
					cout<<"Can't take more than remaining "<<d1.cl
						<<" casual leave(s)";
					gotoxy(1,13);
					cl_check = 0;
				}
				else
				{
					gotoxy(10,24);
					cout<<"                                                           ";
					cl_check = 1;
				}
			}
			gotoxy(1,15);
			cout<<"\n\tLeave without pay    :   \b\b";
			cin>>lwp;

			int nod_in_month;
			if ( month == 1 || month == 3 || month == 5 || month == 7 ||
				 month == 8 || month == 10 || month == 12 )
			{
				nod_in_month = 31;
				nodwk = 31 - (ela + cla + lwp);
			}
			else
			if ( month == 4 || month == 6 ||	month == 9 || month == 11 )
			{
				nod_in_month = 30;
				nodwk = 30 - (ela + cla + lwp);
			}
			else
			if ( month == 2 )
			{
				if (year % 4 == 0)
				{
					nod_in_month = 29;
					nodwk = 29 - (ela + cla + lwp);
				}
				else
				{
					nod_in_month = 28;
					nodwk = 28 - (ela + cla + lwp);
				}
			}


			if ((ela + cla + lwp) > nod_in_month )
			{
				gotoxy(10,24);
				cout<<"Leaves can't exceed days in  a month";
			}
			else
			{
				gotoxy(10,24);
				cout<<"                                      ";
				leaves_check = 1;
			}
		}
		gotoxy(1,17);
		cout<<"\n\tAdvance(if any)      : ";
		cin>>advance;

		gotoxy(1,19);
		cout<<"\n\tNo of Days Worked    : ";
		cout<<nodwk;

		int size = sizeof(d1);
		io_data.seekp(-size,ios::cur);
		d1.el = d1.el - ela;
		d1.cl = d1.cl - cla;
		io_data.write((char *) &d1, sizeof(d1));
		io_data.close();

		io_attend.clear();
		io_attend.write((char *) this,sizeof(*this));
		cout<<"\n\n\t\t\t    ATTENDENCE RECORDED \n";
		cout<<"\n\t\t\t     Add more(y/n) : ";
		cin>>ch;
	}
	io_attend.close();
	clrscr();
}

void attendence :: putdata() // function to display the attendance
{
	cout<<endl<<"\t"<<setiosflags(ios::left)<<setw(8)<<year
		<<setiosflags(ios::left)<<setw(4)<<month
		<<setiosflags(ios::right)<<setw(6)<<cla
		<<setiosflags(ios::right)<<setw(6)<<ela
		<<setiosflags(ios::right)<<setw(6)<<lwp
		<<setiosflags(ios::right)<<setw(7)<<nodwk
		<<setiosflags(ios::right)<<setw(12)<<advance;
}