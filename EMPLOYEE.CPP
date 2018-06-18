// file name -> Employee.cpp

//    ****************   EMPLOYEE MANAGEMENT SYSTEM   ****************
//    ****************	  Author : codered-jack    ****************

// Inclusion of standard header files
#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<dos.h>

// Declaration of free functions
void main_menu(void);
int password();
void pass_screen();
void emp_mas(void);
void report();
void box();

// Defination of global constants
#define  t "\n\t\t\t"
#define  t1 "\n\n\t\t\t"

// Inclusion of files containing classes and methods
#include "data.cpp"
#include "attend.cpp"
#include "password.cpp"
#include "emp_mast.cpp"
#include "allemp.cpp"
#include "oneemp.cpp"
#include "salary.cpp"
#include "dept_sal.cpp"
#include "bal_leav.cpp"

void main_menu()
{
	clrscr();
	cout<<"\n\n\n\n\n\n\t\t\t  EMPLOYEE MANAGEMENT SYSTEM\n";
	cout<<t"******************************";
	cout<<t1"1. Employee Master File";
	cout<<t"2. Attendence";
	cout<<t"3. List of Employees";
	cout<<t"4. See individual Employee";
	cout<<t"5. Reports";
	cout<<t"0. Exit";
	cout<<t1"  Enter Your Choice : ";
	box();
	gotoxy(47,18);
	int ch;
	scanf("%d",&ch);
	fflush(stdin);
	while(ch!= 0)
	{
		switch(ch)
		{
			case 1:
			{
				int rt;
				rt = password();
				if ( rt != 0)
					emp_mas();
				break;
			}
			case 2:
			{
				attendence a1;
				a1.getdata();
				break;
			}
			case 3:
			{
				data e1;
				e1.disp_all();
				break;
			}
			case 4:
			{
				disp_one();
				break;
			}
			case 5:
				report();
				break;
			default:
			{
				textcolor(11+BLINK);
				gotoxy(26,21);
				cprintf("Invalid Data  Please reenter");
				textcolor(14);
				getch();
				break;
			}
		}
	  main_menu();
	}
   exit(0);
}

void emp_mas()
{
	clrscr();
	cout<<"\n\n\n\n\t\t\t   EMPLOYEE MASTER FILE\n";
	cout<<"\n\t\t    ----------------------------------";
	cout<<t1"1. Add New Employee";
	cout<<t1"2. Modify Employee Details";
	cout<<t1"3. Remove Employee";
	cout<<t1"0. Return";
	cout<<"\n"<<t1"  Enter your choice : ";
	int ch ;
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch)
	{
		case 1 :
		{
			data e1;
			e1.add_emp();
			break;
		}
		case 2 :
		{
			data e2;
			e2.mod_emp();
			break;
		}
		case 3 :
		{
			data e3;
			e3.del_emp();
			break;
		}
		case 0 :
		{
			clrscr();
			main_menu();
			break;
		}
		default :
		{
			textcolor(11+BLINK);
			gotoxy(26,21);
			cprintf("Invalid data Please reenter ");
			textcolor(14);
			getch();
			break;
		}
	}
	emp_mas();
}

void report()
{
	clrscr();
	cout<<"\n\n\n\n\t\t\t\t REPORT MENU \n\n";
	cout<<"\t\t      ----------------------------------";
	cout<<t1"1. Pay Slip";
	cout<<t1"2. Balance leave details";
	cout<<t1"3. Dept wise monthly salary report";
	cout<<t1"0. Return";
	cout<<"\n"<<t1"  Enter your choice : ";
	int ch ;
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch)
	{
		case 1 :
		{
			salary();
			break;
		}
		case 2 :
		{
			data d1;
			d1.bal_leave();
			break;
		}
		case 3 :
		{
			dept_sal();
			break;
		}
		case 0 :
		{
			clrscr();
			main_menu();
			break;
		}
		default :
		{
			textcolor(11+BLINK);
			gotoxy(26,21);
			cprintf("Invalid data Please reenter ");
			textcolor(14);
			getch();
			break;
		}
	}
	report();
}

void box()
{
	for(int i=2,j=7 ; j<73 ; j++) // for printing ÍÍÍÍÍ
	{
		gotoxy(j,i);
		cprintf("%c",205);
	}
	gotoxy(73,2);
	cprintf("%c",187); // for printing "
	for (i=23,j=73 ; i>2 ; i--)
	{
		gotoxy(j,i);
		cprintf("%c",186);          // for printing º
	}
	gotoxy(73,24);
	cprintf("%c",188); // for printing  1/4

	for (i=24,j=7 ; j<73 ; j++)   // for printing ÍÍÍÍÍ
	{
		gotoxy(j,i);
		cprintf("%c",205);
	}
	gotoxy(6,24);
	cprintf("%c",200); // for printing È
	for(i=3,j=6 ; i<24 ; i++)     // for printing º
	{
		gotoxy(j,i);
		cprintf("%c",186);
	}
	gotoxy(6,2);
	cprintf("%c",201); // for printing É
	gotoxy(25,25);
	textcolor(10);
	cprintf("Developed By -> codered-jack");
	textcolor(14);
}

void main()
{
	textcolor(14);
	clrscr();
	main_menu();
}
