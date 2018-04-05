// file name -> allemp.cpp

/******** function to list the records of all the employees ********/
void data :: disp_all()
{
	clrscr();
	fstream in;
	in.open("off_det.dat",ios::ate | ios::binary | ios::in | ios::out);
	in.seekg(0);
	gotoxy(66,1);
	cout<<"Q -> Quit";
	cout<<"\n\t\t************  LIST OF EMPLOYEES  ************\n";
	cout<<"\nECODE       NAME  		 DESIGNATION        DEPARTMENT       BASIC\n";
	cout<<"-----------------------------------------------------------------------------\n";
	in.read((char *) this, sizeof(*this));
	int flag = 0;
	int choice_check = 1;
	while(in)
	{
		flag = flag++;
		cout<<"\n"
		<<setiosflags(ios::left)<<setw(7)<<ecode
		<<setiosflags(ios::left)<<setw(25)<<ename
		<<setiosflags(ios::left)<<setw(17)<<desig
		<<setiosflags(ios::left)<<setw(15)<<dept
		<<setiosflags(ios::right)<<setw(12)<<basic;
		if(flag >= 15) // To display only a screenfull at a time
		{
			cout<<"\n\n\t\t\tPress any key to continue.......";
			char choice;
			choice=getch();
			if (choice == 'q' || choice == 'Q')
			{
				choice_check=0;
				break;
			}
			flag = 0;
			clrscr();
			gotoxy(66,1);
			cout<<"Q -> Quit";
			cout<<"\n\t\t************  LIST OF EMPLOYEES  ************\n";
			cout<<"\nECODE       NAME  		 DESIGNATION        DEPARTMENT       BASIC\n";
			cout<<"-----------------------------------------------------------------------------\n";
		}
		in.read((char *) this, sizeof(*this));
	}
	if(choice_check !=0)
	{
		getch();
	}
}

